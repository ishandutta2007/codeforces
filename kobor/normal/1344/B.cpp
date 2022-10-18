// Krzysztof Boryczka
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

const int N=1010;

int n, m, ind;
int grid[N][N];
ii lew[N*N], gor[N*N];
bool pwie, pkol;
int par[N*N];
int xx[4]={1, 0, -1, 0}, yy[4]={0, -1, 0, 1};

int Find(int v){
	return par[v]==v ? v : par[v]=Find(par[v]);
}

void Union(int v, int u){
	v=Find(v);
	u=Find(u);
	par[u]=v;
	lew[v]={min(lew[v].st, lew[u].st), max(lew[v].nd, lew[u].nd)};
	gor[v]={min(gor[v].st, gor[u].st), max(gor[v].nd, gor[u].nd)};
}

set<int> repr;
vii pozio, piono;

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) FOR(j, 1, m){
		char c;
		cin>>c;
		if(c=='#'){
			grid[i][j]=++ind;
			par[ind]=ind;
			lew[ind]={j, j};
			gor[ind]={i, i};
		}
	}
	FOR(i, 1, n){
		int sum=0, bloki=0;
		FOR(j, 1, m) sum+=grid[i][j], bloki+=(grid[i][j]&&!grid[i][j-1]);
		if(sum==0) pwie=1;
		if(bloki>1){
			cout<<-1<<ent;
			return;
		}
	}
	FOR(j, 1, m){
		int sum=0, bloki=0;
		FOR(i, 1, n) sum+=grid[i][j], bloki+=(grid[i][j]&&!grid[i-1][j]);
		if(sum==0) pkol=1;
		if(bloki>1){
			cout<<-1<<ent;
			return;
		}
	}
	FOR(i, 1, n) FOR(j, 1, m) FOR(k, 0, 3){
		if(grid[i][j] && grid[i+xx[k]][j+yy[k]]) Union(grid[i][j], grid[i+xx[k]][j+yy[k]]);
	}
	FOR(i, 1, ind) repr.insert(Find(i));
	for(auto &x: repr){
		pozio.pb(lew[x]);
		piono.pb(gor[x]);
	}
	pozio.pb({0, 0});
	pozio.pb({m+1, m+1});
	piono.pb({0, 0});
	piono.pb({n+1, n+1});
	sort(pozio.begin(), pozio.end());
	sort(piono.begin(), piono.end());
	FOR(i, 0, SIZE(pozio)-2){
		if(pozio[i].nd>=pozio[i+1].st || (pozio[i].nd+1<pozio[i+1].st && !pwie)){
			cout<<-1<<ent;
			return;
		}
	}
	FOR(i, 0, SIZE(piono)-2){
		if(piono[i].nd>=piono[i+1].st || (piono[i].nd+1<piono[i+1].st && !pkol)){
			cout<<-1<<ent;
			return;
		}
	}
	cout<<SIZE(repr)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // int tt; cin>>tt;
    // FOR(te, 1, tt){
	// 	// cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}