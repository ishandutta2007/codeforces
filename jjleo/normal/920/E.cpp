#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int fa[maxn], siz[maxn];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector<int> v[maxn];
int n, m;
int x, y;
int a[maxn];
vector<int> ans;

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	x = 1;
	for(int i = 2;i <= n;i++) if(v[i].size() < v[x].size()) x = i;
	for(int i = 0;i < v[x].size();i++) a[v[x][i]] = 1;
	for(int i = 1;i <= n;i++) if(!a[i]) merge(x, i);
	for(int i = 0;i < v[x].size();i++) a[v[x][i]] = 0;
	for(int i = 0;i < v[x].size();i++){
		int to = v[x][i];
		for(int j = 0;j < v[to].size();j++) a[v[to][j]] = 1;
		for(int j = 1;j <= n;j++) if(!a[j]) merge(to, j);
		for(int j = 0;j < v[to].size();j++) a[v[to][j]] = 0;
	}
	for(int i = 1;i <= n;i++) if(i == find(i)) ans.push_back(siz[i]);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
} //