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
//#define po(x) (1ll<<x)
const ll DIM = 3*10E4+7;
const ll INF = 10E17;
ll n,dp[DIM],res;
vector<ll> G[DIM];
void dfs(ll v,ll par){
    ll mx = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        mx = max(mx,dp[to]);
    }
    dp[v] = G[v].size()+mx-(mx!=0);
}
void findans(ll v,ll par,ll dpar){
    priority_queue<pp> Q;
    Q.push({dpar,par});
    for(ll to:G[v]){
        if (to==par)continue;
        Q.push({dp[to],to});
    }
    priority_queue<pp> sq;
    ll ans = 0;
    while(!Q.empty() && sq.size()<2){
        if (Q.top().fi==0)break;
        sq.push(Q.top());
        ans+=Q.top().fi;
        Q.pop();
    }
    ans+=G[v].size()-sq.size()+1;
    //cout<<ans<<' '<<v<<endl;
    res = max(res,ans);
    while(!sq.empty()){
        Q.push(sq.top());
        sq.pop();
    }
    for(ll to:G[v]){
        if (to==par)continue;
        ans = 0;
        ll cnt = 0;
        while(!Q.empty() && cnt<1){
            if (Q.top().fi==0)break;
            sq.push(Q.top());
            if (Q.top().sc!=to){
                ans+=Q.top().fi;
                cnt++;
            }
            Q.pop();
        }
        ans += G[v].size()-cnt;
        while(!sq.empty()){
            Q.push(sq.top());
            sq.pop();
        }

        findans(to,v,ans);
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n;
        cin>>n;
        forn(i,n-1){
            ll x,y;
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        res = 0;
        dfs(1,-1);
        findans(1,-1,0);
        cout<<res<<endl;
        forn(i,n){
            G[i].clear();
            dp[i] = 0;
        }
    }
    return 0;
}