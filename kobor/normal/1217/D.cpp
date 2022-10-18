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

const int N=5050;

int n, m, kol=1;
vii G[N];
vi topo;
bool vis[N];
int ktory[N], col[N];

void dfs(int v){
	vis[v]=1;
	for(auto &x: G[v]) if(!vis[x.st]) dfs(x.st);
	topo.pb(v);
}

void solve(){
	int a, b, v;
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		G[a].pb({b, i});
	}
	FOR(i, 1, n) if(!vis[i]) dfs(i);
	FOR(i, 0, n-1) ktory[topo[i]]=i;
	FOR(i, 0, n-1){
		v=topo[i];
		for(auto &x: G[v]){
			if(ktory[x.st]<i) col[x.nd]=1;
			else{
				col[x.nd]=2;
				kol=2;
			}
		}
	}
	cout<<kol<<ent;
	FOR(i, 1, m) cout<<col[i]<<sp;
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