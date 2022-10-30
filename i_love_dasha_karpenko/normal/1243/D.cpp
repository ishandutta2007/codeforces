#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define endl '\n'
#define x1 dsfdsfdsfewewer
#define y1 fdgretdfdsfgddsf
const ll DIM = (10e4)+7;
const ll INF = 10e16;
const ll MOD = (10e9)+7;
const ll _MAX = (10e8)+7;
/*                       */

ll n,m,vis[DIM];
vector<ll> G[DIM];
queue<ll> Q;
void bfs(ll v,set<ll> &S){
    Q.push(v);
    while(!Q.empty()){
        v = Q.front();Q.pop();
        set<ll> S1 = S;
        for(ll to:G[v]){
            if (S1.count(to)==1)S1.erase(to);
        }
        for(ll  to:S1){
            S.erase(to);
            if (vis[to]==0)Q.push(to);
            vis[to] = 1;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    forn(i,m){
        ll x,y; cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    set<ll> S;
    forn(i,n)S.insert(i);
    ll comp = 0;
    forn(i,n){
        if (vis[i]==0){
            comp++;
            bfs(i,S);
        }
    }
    cout<<comp-1<<endl;
    return 0;
}