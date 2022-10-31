#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
ll A[DIM],dist[DIM],dist1[DIM];
priority_queue<pp,vector<pp>,greater<pp> > dp[DIM];
queue<ll> Q;
vector<ll> G[DIM];
void bfs(ll v){
    memset(dist,-1,sizeof(dist));
    dist[v] = 0;
    Q.push(v);
    while(!Q.empty()){
        v = Q.front(); Q.pop();
        for(ll to:G[v]){
            if (dist[to]==-1){
                dist[to] = dist[v]+1;
                Q.push(to);
            }
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    forn(i,k){
        cin>>A[i];
    }
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    bfs(n);
    forn(i,n)dist1[i] = dist[i];
    bfs(1);
    ll base = dist[n];
    vector<pp> V;
    forn(i,k){
        V.pb({dist1[A[i]]-dist[A[i]],A[i]});
    }
    sort(V.begin(),V.end());
    for(ll i = 1;i<=V.size();i++){
        dp[i] = dp[i-1];
        dp[i].push({dist1[V[i-1].sc],V[i-1].sc});
        while(dp[i].size()>2)dp[i].pop();
    }
    ll res = 0;
    forn(i,k){
        ll dif = dist1[A[i]]-dist[A[i]];
        ll pos = upper_bound(V.begin(),V.end(),pp{dif,INF})-V.begin();
        ll cnt = dist[A[i]]+1,flag = 0;
        queue<pp> qq;
        while(!dp[pos].empty()){
            qq.push(dp[pos].top());
            pp t = dp[pos].top();
            dp[pos].pop();
            if (t.sc==A[i])continue;
            cnt+=t.fi;
            flag = 1;
            break;
        }
        while(!qq.empty()){
            dp[pos].push(qq.front());
            qq.pop();
        }
        if (flag==1)
        res = max(res,cnt);
    }
    res = min(res,base);
    cout<<res<<endl;
    return 0;
}