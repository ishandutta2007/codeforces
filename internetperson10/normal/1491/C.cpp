#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums, extra;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        nums.resize(n);
        extra.resize(n);
        ll ans = 0;
        ll x = n-1;
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = 0; i < n; i++) {
            for(int j = i+2; j <= min(n-1, i+nums[i]); j++) extra[j]++;
            ans += max(0, nums[i] - 1 - extra[i]);
            if(i < n-1) extra[i+1] += max(0, extra[i] - nums[i] + 1);
        }
        cout << ans << '\n';
        vector<int>().swap(nums);
        vector<int>().swap(extra);
    }
}