#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> a(n), b(n);

        for(int i = 0; i < n; ++i){
            cin >> a[i];

            b[i] = a[i];
            if(i){
                b[i] ^= b[i - 1];
            }
        }

        vector<int> dp(n);

        map<int, int> mp;

        mp[0] = 1;

        for(int i = 0; i < n; ++i){
            dp[i] = !!a[i];

            if(i) dp[i] += dp[i - 1];

            if(i){
                int p = mp[b[i - 1] ^ a[i]];

                p -= 2;
                if(p >= -1){
                    dp[i] = min(dp[i], (p >= 0 ? dp[p] : 0) + i - p - 1);
                }
            }

            mp[b[i]] = i + 2;
        }

        cout << dp[n - 1] << '\n';
    }
    
    return 0;
}