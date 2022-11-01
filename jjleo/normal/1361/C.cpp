#include <bits/stdc++.h>
#define maxn 4000086

using namespace std;

int n;
vector<pair<int, int> > v[maxn];
int x, y;
int a[maxn];
int cnt;
bool tag[maxn];
int cur[maxn];

inline void addEdge(int x, int y, int z){
	v[x].push_back({y, z}), v[y].push_back({x, z});
}

int sk[maxn], top;

void dfs(int i){
	for(int &j = cur[i];j < v[i].size();j++){
		if(tag[v[i][j].second]) continue;
		tag[v[i][j].second] = true;
		dfs(v[i][j].first);
	}
	sk[++top] = i;
}

bool vis[maxn];

void Dfs(int i){
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		if(!vis[v[i][j].first]) Dfs(v[i][j].first);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a[i * 2 - 1], &a[i * 2]);
		addEdge(i * 2 - 1, i * 2, i);
	}
	for(int k = 20, l = 1 << 20;l;k--, l >>= 1){
		cnt = n;
		for(int i = 1;i <= n;i++){
			addEdge(i * 2 - 1, a[i * 2 - 1] % l + n * 2 + 1, ++cnt);
			addEdge(i * 2, a[i * 2] % l + n * 2 + 1, ++cnt);
		}
		bool suc = false;
		for(int i = 1;i <= n;i++){
			if(v[a[i * 2 - 1] % l + n * 2 + 1].size() & 1) break;
			if(v[a[i * 2] % l + n * 2 + 1].size() & 1) break;
			if(i == n) suc = true;
		}
		if(suc){
			Dfs(1);
			for(int i = 1;i <= n * 2;i++){
				if(!vis[i]){
					suc = false;
					break;
				}
			}
			if(!suc){
				for(int i = 1;i <= n;i++){
					vis[i * 2 - 1] = vis[i * 2] = false;
					vis[a[i * 2 - 1] % l + n * 2 + 1] = vis[a[i * 2] % l + n * 2 + 1] = false;
				}
			}else{
				dfs(1); 
				printf("%d\n", k);
				if(sk[2] > n * 2){
					for(int i = 2;i <= top;i++) if(sk[i] <= n * 2) printf("%d ", sk[i]);
				}else{
					for(int i = 1;i < top;i++) if(sk[i] <= n * 2) printf("%d ", sk[i]);
				}
				return 0;
			}
		}
		for(int i = 1;i <= n;i++){
			v[i * 2 - 1].pop_back(), v[i * 2].pop_back();
			v[a[i * 2 - 1] % l + n * 2 + 1].pop_back(), v[a[i * 2] % l + n * 2 + 1].pop_back();
		}
	}
}