#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N=110;

int m, n, glob;
map<string, int> nr;
vi G[N];
set<string> zioms;
int vis[N];
bool cyc;

void dfs(int v){
	vis[v] = 1;
	TRAV(x, G[v]){
		if(vis[x] == 1) cyc=1;
		if(!vis[x]) dfs(x);
	}
	vis[v] = 2;
}

string flip(string s){
	string ret;
	ret.resize(n, '0');
	FOR(i, 0, n) if(s[i] == '0') ret[i] = '1';
	return ret;
}

bool podz(string x, string y){
	FOR(i, 0, n) if(x[i] == '0' && y[i] == '1') return false;
	return true;
}

void solve(){
	cin >> m >> n;
	FOR(i, 0, m){
		int k, a;
		string v;
		v.resize(n, '0');
		cin >> k;
		FOR(j, 0, k){
			cin >> a;
			v[a-1] = '1';
		}
		string vp = flip(v);
		if(nr.count(v) == 0) nr[v] = ++glob;
		if(nr.count(vp) == 0) nr[vp] = ++glob;
		G[nr[v]].PB(nr[vp]);
		zioms.insert(v);
		zioms.insert(vp);
	}
	TRAV(x, zioms) TRAV(y, zioms) if(x != y && podz(x, y)) G[nr[x]].PB(nr[y]);
	FOR(i, 1, glob+1) if(!vis[i]) dfs(i);
	if(cyc) cout << "im";
	cout << "possible\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}