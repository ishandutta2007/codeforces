#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int n, m, sn;
vector<int> v[maxn];
int fa[maxn], dep[maxn];
int x, y;
bool suc;
bool del[maxn];
int a[maxn];


void dfs(int i){
	if(suc) return;
	for(int j = 0;j < v[i].size();j++){
		if(suc) return;
		if(v[i][j] != fa[i]){
			if(!dep[v[i][j]]){
				fa[v[i][j]] = i, dep[v[i][j]] = dep[i] + 1;
				dfs(v[i][j]);
			}else{
				if(dep[i] - dep[v[i][j]] >= sn - 1){
					suc = true;
					printf("2\n%d\n", dep[i] - dep[v[i][j]] + 1);
					for(int k = i;;k = fa[k]){
						printf("%d ", k);
						if(k == v[i][j]) return;
					}
				}
			}
		}
	}
	if(!del[i]) for(int j = 0;j < v[i].size();j++) del[v[i][j]] = true;
}


int main(){
	scanf("%d%d", &n, &m);
	sn = (int)ceil(sqrt(n));
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dep[1] = 1;
	dfs(1);
	if(!suc){
		puts("1");
		for(int i = 1;i <= n && sn;i++) if(!del[i]) printf("%d ", i), sn--;
	} 
}