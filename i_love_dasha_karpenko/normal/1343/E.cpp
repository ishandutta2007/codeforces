#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e19;

ll p[DIM],dist1[DIM],dist2[DIM],dist3[DIM],pref[DIM];
vector<ll> G[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    memset(dist3,-1,sizeof(dist3));

    while(t--){
        ll n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        forn(i,m)cin>>p[i];
        forn(i,m){
            ll x,y;
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        queue<ll> Q;
        Q.push(a);
        dist1[a] = 0;
        while(!Q.empty()){
            ll v = Q.front();
            Q.pop();
            for(ll to:G[v]){
                if (dist1[to]==-1 || dist1[to]>dist1[v]+1){
                    dist1[to] = dist1[v]+1;
                    Q.push(to);
                }
            }
        }
        Q.push(b);
        dist2[b] = 0;
        while(!Q.empty()){
            ll v = Q.front();
            Q.pop();
            for(ll to:G[v]){
                if (dist2[to]==-1 || dist2[to]>dist2[v]+1){
                    dist2[to] = dist2[v]+1;
                    Q.push(to);
                }
            }
        }
        Q.push(c);
        dist3[c] = 0;
        while(!Q.empty()){
            ll v = Q.front();
            Q.pop();
            for(ll to:G[v]){
                if (dist3[to]==-1 || dist3[to]>dist3[v]+1){
                    dist3[to] = dist3[v]+1;
                    Q.push(to);
                }
            }
        }
        sort(p+1,p+1+m);
        forn(i,m){
            pref[i] = pref[i-1]+p[i];
        }
        ll res = INF;
        forn(i,n){
            ll sum = dist1[i]+dist2[i]+dist3[i];

            G[i].clear();
            if (sum>m){
                dist1[i] = dist2[i] = dist3[i] = -1;
                continue;
            }
            ll r = pref[sum]+pref[dist2[i]];
            res = min(res,r);

            dist1[i] = dist2[i] = dist3[i] = -1;
        }
        cout<<res<<endl;

    }
    return 0;
}