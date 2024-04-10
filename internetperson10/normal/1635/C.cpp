#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> sorted;
        for(int i = 0; i < n; i++) cin >> nums[i];
        sorted = nums;
        sort(sorted.begin(), sorted.end());
        if(sorted == nums) {
            cout << "0\n";
        }
        else if(nums[n-1] < 0 || nums[n-2] > nums[n-1]) {
            cout << "-1\n";
        }
        else {
            cout << n-2 << '\n';
            for(int i = 1; i < n-1; i++) cout << i << ' ' << n-1 << ' ' << n << '\n';
        }
    }
}