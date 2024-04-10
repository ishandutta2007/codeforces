#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define vii vector<pii >
#define vi vector<int>
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
const int N = 1e6 + 10;
int col[N], row[N], vis[N], val[N], cnt = 0;
vector<vector<int> > a;
vii pairs;
vi con[N], v, comp[N], nodes;
map<int, vi> myp;
void dfs(int s){
	comp[cnt].pb(s); vis[s] = 1;
	for(int v: con[s]) if(!vis[v]) dfs(v);
}
void dfs(int n, int m){
	for(int i = 0; i < n * m; i++) nodes.pb(i);
	srand(time(NULL)); random_shuffle(nodes.begin(), nodes.end());
	for(int k = 0; k < n * m; k++){
		int i = nodes[k];
		if(!vis[i]){dfs(i); val[cnt] = a[i/m][i%m]; cnt++;}
	}
}
int main(){
	int n, m;
	sd(n), sd(m);
	a.resize(n);
	for(int i = 0; i < n; i++) a[i].resize(m);
	for(int i = 0; i < n; i++){
		myp.clear(); v.clear();
		for(int j = 0; j < m; j ++){
			sd(a[i][j]);
			myp[a[i][j]].pb(i * m + j);
		}
		for(auto it: myp){
			v = it.S;
			for(int j = 0; j < v.size() - 1; j ++){
				con[v[j]].pb(v[j + 1]);
				con[v[j + 1]].pb(v[j]);
			}
		}
	}
	for(int j = 0; j < m; j++){
		myp.clear(); v.clear();
		for(int i = 0; i < n; i++){
			myp[a[i][j]].pb(i * m + j);	
		}
		for(auto it: myp){
			v = it.S;
			for(int i = 0; i < v.size() - 1; i ++){
				con[v[i]].pb(v[i + 1]);
				con[v[i + 1]].pb(v[i]);
			}
		}
	}
	dfs(n, m);
	for(int i = 0; i < cnt; i++) pairs.pb(mp(val[i], i));
	sort(pairs.begin(), pairs.end());
	for(int k = 0; k < cnt; k++){
		int c = pairs[k].S;
		int mx = 0;
		for(int node : comp[c]){
			int i = node / m, j = node % m;
			mx = max(mx, max(row[i], col[j]));
		}
		for(int node : comp[c]){
			int i = node / m, j = node % m;
			a[i][j] = mx + 1;
			row[i] = max(row[i], mx + 1);
			col[j] = max(col[j], mx + 1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
}