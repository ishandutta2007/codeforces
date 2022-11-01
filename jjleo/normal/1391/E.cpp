#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t;
int n, m;
int x, y;
vector<int> v[maxn];
vector<int> a[maxn];
int dep[maxn], fa[maxn];
vector<pair<int, int> > ans;

void dfs(int i){
	dep[i] = dep[fa[i]] + 1;
	a[dep[i]].push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(dep[to]) continue;
		fa[to] = i;
		dfs(to);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), a[i].clear(), dep[i] = 0;
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}
		dfs(1);
		if(a[(n + 1) / 2].size()){
			printf("PATH\n%d\n", (n + 1) / 2);
			for(int i = a[(n + 1) / 2].back();i;i = fa[i]) printf("%d ", i);
			puts("");
		}else{
			puts("PAIRING");
			ans.clear();
			for(int i = 2;i <= n;i++){
				while(a[i].size() > 1){
					int x = a[i].back();
					a[i].pop_back();
					int y = a[i].back();
					a[i].pop_back();
					ans.push_back({x, y});
				}
			}
			printf("%d\n", ans.size());
			for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
}