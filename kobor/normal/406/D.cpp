//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

typedef pair<ll, ll> pt;
#define x st
#define y nd

const int N=1e5+5;
const int M=17;

pt t[N];
int n, m;
int par[N][M+1], dpth[N];
vi G[N], oto;

void dfs(int v){
	for(auto &x: G[v]){
		dpth[x]=dpth[v]+1;
		dfs(x);
	}
}

void prep(){
	FOR(i, 1, M) FOR(j, 1, n) par[j][i]=par[par[j][i-1]][i-1];
}

int lca(int a, int b){
	if(dpth[a]<dpth[b]) swap(a, b);
	FORD(i, M, 0) if(dpth[par[a][i]]>=dpth[b]) a=par[a][i];
	if(a==b) return a;
	FORD(i, M, 0) if(par[a][i]!=par[b][i]) a=par[a][i], b=par[b][i];
	return par[a][0];
}

ld cross(pt a, pt b, pt c){
	a.x-=c.x; a.y-=c.y;
	b.x-=c.x; b.y-=c.y;
	return (ld)a.x*b.y-(ld)b.x*a.y;
}

void solve(){
	int a, b;
	cin>>n;
	FOR(i, 1, n) cin>>t[i].x>>t[i].y;
	oto={n}; par[n][0]=n;
	cout<<ent;
	FORD(i, n-1, 1){
		while(SIZE(oto)>1 && cross(t[oto.back()], t[i], t[oto[SIZE(oto)-2]])<0) oto.pop_back();
		par[i][0]=oto.back();
		G[oto.back()].pb(i);
		oto.pb(i);
	}
	dfs(n);
	prep();
	cin>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		cout<<lca(a, b)<<sp;
	}
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}