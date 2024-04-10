#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int p[maxn], tag[maxn], cnt;
vector<pair<int, int> > v[maxn];
int a[maxn];
int x, y;

void dfs(int i, int fa, int val){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, id = v[i][j].second;
		if(to == fa) continue;
		a[id] = val;
		dfs(to, i, 5 - val);
	}
}

int main(){
	for(int i = 2;i <= 1000;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i <= 1000;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 1;i <= cnt;i++){
		for(int j = i;j <= cnt;j++){
			for(int k = j;k <= cnt;k++){
				if(p[j] + p[k] <= 1000){
					if(!tag[p[i] + p[j]] && !tag[p[i] + p[k]] && !tag[p[j] + p[k]]) printf("%d %d %d\n", p[i], p[j], p[k]);
				}
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back({y, i}), v[y].push_back({x, i}); 
		}
		bool tag = false;
		for(int i = 1;i <= n;i++) if(v[i].size() > 2) tag = true;
		if(tag){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(v[i].size() == 1){
				dfs(i, 0, 2);
				break;
			}
		}
		for(int i = 1;i < n;i++) printf("%d ", a[i]);puts("");
	}
}