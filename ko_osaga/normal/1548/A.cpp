#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 300005;
const int mod = 998244353;

int n, m;
set<int> gph[MAXN];
int cnt;

void add_edge(int u, int v){
	if(sz(gph[u]) && *gph[u].rbegin() > u) cnt--;
	if(sz(gph[v]) && *gph[v].rbegin() > v) cnt--;
	gph[u].insert(v);
	gph[v].insert(u);
	if(sz(gph[u]) && *gph[u].rbegin() > u) cnt++;
	if(sz(gph[v]) && *gph[v].rbegin() > v) cnt++;
}
void rem_edge(int u, int v){
	if(sz(gph[u]) && *gph[u].rbegin() > u) cnt--;
	if(sz(gph[v]) && *gph[v].rbegin() > v) cnt--;
	gph[u].erase(v);
	gph[v].erase(u);
	if(sz(gph[u]) && *gph[u].rbegin() > u) cnt++;
	if(sz(gph[v]) && *gph[v].rbegin() > v) cnt++;
}

int query(){
	return n - cnt;
}

int main(){
	scanf("%d %d",&n,&m);
	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&u,&v);
		add_edge(u, v);
	}
	int q; scanf("%d",&q);
	while(q--){
		int t; scanf("%d",&t);
		if(t == 3) printf("%d\n", query());
		else{
			int u, v; scanf("%d %d",&u,&v);
			if(t == 1) add_edge(u, v);
			else rem_edge(u, v);
		}
	}
}