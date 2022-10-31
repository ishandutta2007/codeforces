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
const ll INF = 10E16;

ll n,A[DIM],dist[DIM],ways[DIM];
vector<ll> G[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        G[y].pb(x);
    }
    ll k;
    cin>>k;
    forn(i,k)cin>>A[i];
    memset(dist,-1,sizeof(dist));
    dist[A[k]] = 0;
    ways[A[k]] = 1;
    queue<ll> Q;
    Q.push(A[k]);
    while(!Q.empty()){
        ll v = Q.front();
        Q.pop();
        for(ll to:G[v]){
            if (dist[to]==dist[v]+1){
                ways[to]++;
            }
            else if (dist[to]==-1 || dist[to]>dist[v]+1){
                dist[to] = dist[v]+1;
                ways[to] = 1;
                Q.push(to);
            }
        }
    }
    ll mi = 0,mx = 0;
    forn(i,k-1){
        if (dist[A[i+1]]!=dist[A[i]]-1){
            mi++;
            mx++;
        }
        else{
            if (ways[A[i]]>1)mx++;
        }
    }
    cout<<mi<<' '<<mx<<endl;
    return 0;
}