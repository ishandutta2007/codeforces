#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int g;
        cin >> g;
        k--;
        while(k--) {
            int x;
            cin >> x;
            g = __gcd(g, x);
        }
        vector<vector<ll>> comb(g);
        vector<int> ct(g);
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) ct[i%g]++;
            comb[i%g].push_back(abs(nums[i]));
        }
        for(int i = 0; i < g; i++) {
            ct[i] %= 2;
            sort(comb[i].begin(), comb[i].end());
        }
        ll ans1 = 0, ans2 = 0;
        for(int i = 0; i < g; i++) {
            for(int j = 0; j < comb[i].size(); j++) {
                if(j == 0) {
                    if(ct[i] == 1) {
                        ans1 += comb[i][j];
                        ans2 -= comb[i][j];
                    }
                    else {
                        ans1 -= comb[i][j];
                        ans2 += comb[i][j];
                    }
                }
                else {
                    ans1 += comb[i][j];
                    ans2 += comb[i][j];
                }
            }
        }
        ll ans = max(ans1, ans2);
        cout << ans << '\n';
    }
}