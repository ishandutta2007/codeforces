#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define MODULO 998244353
const ll MAXN = ll(10E8);
const ll INF = 10E16;
const ll masksz = 1048576;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n,m,w[DIM],r[DIM],sz[DIM];
vector<ll> G[DIM];
queue<ll> Q;
int main() {
	schnell;
	cin>>n>>m;
    forn(i,n)cin>>w[i];
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll start;
    cin>>start;
    forn(i,n){
        if (i!=start && G[i].size()==1)Q.push(i);
        sz[i] = G[i].size();
    }
    while(!Q.empty()){
            ll v = Q.front(); Q.pop();
            sz[v] = -1;
        for(ll to:G[v]){
            if (sz[to]<0)continue;
            r [to] = max(r[to],r[v]+w[v]);
            sz[to]--;
            if (sz[to]==1 && to!=start)Q.push(to);
        }
    }
    ll res = 0,res1 = 0;
    for(ll i = 1;i<=n;i++){
        if (sz[i]>=0){
        res = max(res,r[i]);
        res1+=w[i];
        }
    }
    cout<<res1+res<<endl;
	return 0;
}