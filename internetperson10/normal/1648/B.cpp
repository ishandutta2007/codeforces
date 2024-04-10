#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        auto it = std::unique(nums.begin(), nums.end());
        int x = it - nums.begin();
        nums.resize(x);
        if(nums[0] != 1) {
            cout << "No\n";
            continue;
        }
        vector<int> pref(c+1);
        for(int g : nums) pref[g]++;
        for(int i = 1; i <= c; i++) pref[i] += pref[i-1];
        bool ok = true;
        for(int i = 2; i*i <= c; i++) {
            int lim = c/i;
            for(int j = 2; j <= lim; j++) {
                if((pref[i] - pref[i-1]) && (pref[j] - pref[j-1])) continue;
                if(pref[i] - pref[i-1]) {
                    if((pref[min(c, i*j+i-1)] - pref[min(c, i*j-1)])) ok = false;
                }
                if(pref[j] - pref[j-1]) {
                    if((pref[min(c, i*j+j-1)] - pref[min(c, i*j-1)])) ok = false;
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}