#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t, n, m;
vector<int> v[maxn], e[maxn], a[maxn], A, B;
int x, y; 
int fa[maxn], siz[maxn];
int ans[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), e[i].clear(), a[i].clear(), fa[i] = 0;
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		for(int i = 2;i <= n;i++){
			if(v[i].size() == n - 1) continue;
			for(int j = 0;j < v[i].size();j++) tag[v[i][j]] = true;
			for(int j = 1;j <= n;j++){
				if(!tag[j] && i != j){
					e[i].push_back(j), e[j].push_back(i);
					break;
				}
			}
			for(int j = 0;j < v[i].size();j++) tag[v[i][j]] = false;
		}
		for(int i = 1;i <= n;i++){
			if(v[i].size() == n - 1 || fa[i]) continue;
			int x = e[i].back();
			if(fa[x]){
				if(siz[fa[x]] == 2){
					fa[fa[x]] = 0;
				}else{
					siz[fa[x]]--;
				}
				fa[x] = x, siz[x] = 1;
				for(int j = 0;j < e[x].size();j++){
					int to = e[x][j];
					if(!fa[to]) fa[to] = x, siz[x]++;
				}
			}else{
				fa[x] = x, siz[x] = 1;
				for(int j = 0;j < e[x].size();j++){
					int to = e[x][j];
					if(!fa[to]) fa[to] = x, siz[x]++;
				}
			}
		}
		A.clear(), B.clear();
		for(int i = 1;i <= n;i++){
			if(v[i].size() == n - 1) continue;
			if(fa[i] != i) a[fa[i]].push_back(i);
		}
		for(int i = 1;i <= n;i++){
			if(fa[i] != i) continue;
			for(int j = 0;j < a[i].size();j++) A.push_back(a[i][j]);
			A.push_back(i), B.push_back(i);
			for(int j = 0;j < a[i].size();j++) B.push_back(a[i][j]);
		} 
		for(int i = 1;i <= n;i++) if(v[i].size() == n - 1) A.push_back(i), B.push_back(i);
		for(int i = 0;i < A.size();i++) ans[A[i]] = i + 1;
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
		for(int i = 0;i < B.size();i++) ans[B[i]] = i + 1;
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
	}
}