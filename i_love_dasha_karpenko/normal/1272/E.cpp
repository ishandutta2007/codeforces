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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
ll A[DIM],dist[DIM];
vector<ll> G[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    priority_queue<pp,vector<pp>,greater<pp> > Q;
    memset(dist,-1,sizeof(dist));
    forn(i,n)G[i].clear();
    forn(i,n){
        cin>>A[i];
        if (i-A[i]>=1){
            G[i-A[i]].pb(i);
        }
        if (i+A[i]<=n){
            G[i+A[i]].pb(i);
        }
    }
    forn(i,n){
        if ( (i-A[i]>=1 && A[i]%2!=A[i-A[i]]%2) || (i+A[i]<=n && A[i]%2!=A[i+A[i]]%2)){
            Q.push({1,i});
            dist[i] = 1;
        }
    }
    while(!Q.empty()){
        ll v = Q.top().sc;
        Q.pop();
        for(ll to:G[v]){
            if (dist[to]==-1 || dist[to]>dist[v]+1){
                dist[to] = dist[v]+1;
                Q.push({dist[to],to});
            }
        }
    }
    forn(i,n)cout<<dist[i]<<' ';
    return 0;
}