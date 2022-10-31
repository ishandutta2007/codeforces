//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1E5+7;
const ll INF = 1E7+7;
const ll MULT = 1E5;
ll dp[DIM],vis[DIM];
pair<ll,ll> P[DIM];
ll type,x,y,turn,n,m;
pair<ll,ll> solve(ll num){
    ll step = y;

    while(step--){

        ll nxt;
        if (type==1){
            nxt = (num*MULT+x);
            nxt = nxt/MULT+ll(nxt%MULT!=0ll);
        }
        else{
            nxt = (num*x);
            nxt = nxt/MULT+ll(nxt%MULT!=0ll);
        }
        if (nxt>m)break;
        if (vis[nxt]==0){
            if (dp[nxt]!=-1)step = y;
            else dp[nxt] = turn;

            vis[nxt] = 1;
        }
        else{
            //break;
        }
        num = nxt;

    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(turn = 1;turn<=n;++turn){
        cin>>type>>x>>y;
        for(ll i = 0;i<=m;++i){
            P[i] = {i,0};
            vis[i] = 0;

        }
        for(ll i = 0;i<=m;++i){
            if (i==95){
                ll h;
                ++h;

            }
            if (dp[i]==-1 || dp[i]==turn || vis[i])continue;
            solve(i);
        }
    }
    for(ll i = 1;i<=m;++i)
        cout<<dp[i]<<' ';
    cout<<endl;

    return 0;
}