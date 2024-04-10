#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 2e3+7;
const ll MOD = 1e9+7;
pair<ll,ll> dp[2][N<<1];
void solve() {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int tr = 0;
    for(int w = -n;w<=n;++w)
        dp[tr][w+n] = mp(0,0);
    dp[0][n] = mp(0,1);
    for(int i = 0;i<n;++i){
        for(int w = -n;w<=n;++w)
            dp[tr^1][w+n] = mp(0,0);

        if (i&1){
            if (s[i]!='?')
                s[i] = s[i]=='1'?'0':'1';
            if (t[i]!='?')
                t[i] = t[i]=='1'?'0':'1';
        }
        int l1 = 0,r1 = 0,l2 = 0,r2 = 0;
        if (s[i]=='?')
            r1++;
        else l1+=gi(s[i]),r1+=gi(s[i]);
        if (t[i]=='?')
            l2--;
        else l2-=gi(t[i]),r2-=gi(t[i]);
        for(int d1 = l1;d1<=r1;++d1) {
            for(int d2 = l2;d2<=r2;++d2) {
                int d = d1+d2;
                for (ll w = -n; w <= n; ++w) {
                    if (dp[tr][n + w].second == 0 || w + d < -n || w+d>n)
                        continue;
                    int nw = w + d;
                    dp[tr ^ 1][n + nw].first =
                            (dp[tr ^ 1][nw + n].first + dp[tr][w + n].first + abs(w) * dp[tr][w + n].second) % MOD;
                    dp[tr ^ 1][nw + n].second = (dp[tr ^ 1][nw + n].second +dp[tr][w + n].second)%MOD;
                }
            }
        }
        tr^=1;
    }
    cout<<dp[tr][n].first<<endl;
}
signed main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}