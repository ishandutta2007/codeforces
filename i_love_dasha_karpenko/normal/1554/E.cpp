//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 2E5+7;
const int MOD = 998244353;
int dp[DIM];
vector<int> G[DIM];
ll solve(int v,int par,int div){
    int cur = 0;
    for(auto to:G[v]){
        if (to==par)
            continue;
        int ret = solve(to,v,div);
        cur+=ret;
    }
    if (v==par){
        if (cur%div!=0)
            dp[div] = 0;
    }
    if (cur%div==0)
        return 1;
    else{
        if ((cur+1)%div)
            dp[div] = 0;
        return 0;
    }
}
void solve(){
    int n;
    cin>>n;
    ll total = 1;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        total*=2;
        if (total>=MOD)
            total-=MOD;
    }
    for(int i = 2;i*i<=n-1;++i){
        if ((n-1)%i)
            continue;
        dp[i] = 1;
        solve(1,1,i);
        if (i*i!=n-1) {
            dp[(n - 1) / i] = 1;
            solve(1, 1, (n - 1) / i);
        }
    }
    dp[n-1] = 1;
    solve(1,1,n-1);
    dp[1] = total;
    for(int i = n-1;i>=1;--i){
        for(ll j = i*2;j<=n-1;j+=i){
            dp[i]-=dp[j];
        }
        while(dp[i]<0)
            dp[i]+=MOD;
    }
    for(int i = 1;i<=n;++i) {
        cout << dp[i] << ' ', G[i].clear();
        dp[i] = 0;
    }
    cout<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/**
1
6 3
111001
111100
10 3
1101000000
1011000000

**/