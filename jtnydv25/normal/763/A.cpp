#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10;
map<int, int> all;
int tree[N], col[N], c[N];
vector<int> con[N];
int choose = -1;
int dfs(int s, int p){
	tree[s] = 1;
	map<int, int > cols;
	bool no = 0;
	cols[c[s]] ++;
	for(int v: con[s]){
		if(v != p){
			dfs(v, s);
			if(col[v] == -1) no = 1;
			cols[col[v]] += tree[v];
			tree[s] += tree[v];
		}
	}
	if(no) return col[s] = -1;
	int size = all.size();
	for(auto it: cols) if(all[it.first] == it.second) size--;
	if(choose == -1 && size <= 1){ choose = s;}	
	if(cols.size() > 1){ return col[s] = -1; };
	return col[s] = c[s];
}
int main(){
	int n, u, v;
	sd(n);
	for(int i = 0; i < n - 1; i ++){
		sd(u), sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		sd(c[i]);
		all[c[i]] ++;
	}
	dfs(1, 0);
	if(choose == -1){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	printf("%d\n", choose);
}