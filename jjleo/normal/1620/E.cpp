#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
int fa[maxn];
int cnt;
int opt, x, y;
int c[maxn];
int id[maxn];
int m;
int col[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
	for(int i = 1;i < maxn;i++) fa[i] = i;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d", &x);
			if(!c[x]) c[x] = ++cnt, col[cnt] = x;
			id[++m] = ++cnt;
			fa[id[m]] = c[x];
		}else{
			scanf("%d%d", &x, &y);
			if(x == y) continue;
			if(!c[x]) continue;
			if(!c[y]) c[y] = ++cnt, col[cnt] = y;
			fa[c[x]] = c[y];
			c[x] = 0;
		}
	}
	for(int i = 1;i <= m;i++) printf("%d ", col[find(id[i])]);
}