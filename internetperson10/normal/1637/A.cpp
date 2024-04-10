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
        for(int i = 0; i < n; i++) cin >> nums[i];
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        bool ok = true;
        if(sorted != nums) ok = false;
        cout << (ok ? "NO\n" : "YES\n");
    }
}