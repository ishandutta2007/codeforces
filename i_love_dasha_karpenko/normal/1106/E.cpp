#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 10E4+7;
const ll INF = 10E17;

struct node{
    ll p,d,w;
};
vector<node> ev[DIM];
ll dp[DIM][207];
const bool operator<(const node &a,const node &b){
    if (a.w==b.w){
        if (a.d==b.d)return a.p<b.p;
        return a.d>b.d;
    }
    return a.w>b.w;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k; cin>>n>>m>>k;
    forn(i,k){
        ll l,r,d,w;
        cin>>l>>r>>d>>w;
        d++;
        ev[l].pb({i,d,w});
        ev[r+1].pb({i+k,d,w});
    }
    set<node> S;
    forn(i,n+1){
        for(ll j=  0;j<=m;j++)dp[i][j] = INF;
    }
    dp[1][0] = 0;
    forn(i,n){
        for(node to:ev[i]){
            if (to.p>k)S.erase({to.p-k,to.d,to.w});
            else S.insert(to);
        }
        if (!S.empty()){
            node a = *S.begin();
            for(ll j = 0;j<=m;j++){
                dp[a.d][j] = min(dp[a.d][j],dp[i][j]+a.w);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
            }
        }
        else{
            for(ll j = 0;j<=m;j++){
                //dp[a.d][j] = min(dp[a.d][j],dp[i][j]+a.w);
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            }
        }
    }
    ll res = INF;
    for(ll i =0;i<=m;i++)res = min(res,dp[n+1][i]);
    cout<<res<<endl;
    return 0;
}