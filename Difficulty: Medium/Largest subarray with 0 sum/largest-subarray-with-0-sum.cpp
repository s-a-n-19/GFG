//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
       map<long long, int> presumMap; // Corrected variable name
        long long sum = 0;
        int maxlen = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == 0) {
                maxlen = max(maxlen, i + 1);
            }
            long long rem = sum - 0; // rem = sum - k (here k = 0)
            if (presumMap.find(rem) != presumMap.end()) {
                int len = i - presumMap[rem];
                maxlen = max(maxlen, len);
            }
            if (presumMap.find(sum) == presumMap.end()) {
                presumMap[sum] = i;
            }
        }
        return maxlen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends