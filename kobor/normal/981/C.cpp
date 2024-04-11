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

const int N=1e5+5;

int n, root, num;
vi G[N];
vi path[N];
int grp[N], par[N];
set<int> fajny;

void dfs(int v, int p, bool nowa){
	if(nowa){
		grp[v]=++num;
		path[grp[v]].pb(p);
	}
	else grp[v]=grp[p];
	path[grp[v]].pb(v);
	int xd=0;
	for(auto &x: G[v]){
		if(x==p) continue;
		dfs(x, v, xd);
		if(xd==1) fajny.insert(v);
		xd++;
	}
}

void solve(){
	int a, b;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i, 1, n) if(SIZE(G[i])==1) root=i;
	dfs(root, root, 1);
	if(SIZE(fajny)>1){
		cout<<"No"<<ent;
		return;
	}
	cout<<"Yes"<<ent;
	cout<<num<<ent;
	FOR(i, 1, num) cout<<path[i].front()<<sp<<path[i].back()<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}