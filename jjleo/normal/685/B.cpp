#include <bits/stdc++.h>
#define maxn 300086
using namespace std;

vector<int> v[maxn];
int cen[maxn], siz[maxn], fa[maxn], ms[maxn];

void dfs(int i){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
		siz[i] += siz[to];
		ms[i] = max(ms[i], siz[to]);
	}
	int x = i, y = ms[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		int z = cen[to];
		while(z ^ i){
			if(siz[z] > siz[i] - siz[z]) break;
			z = fa[z];	
		}
		if(max(ms[z], siz[i] - siz[z]) < y){
			x = z;
			y = max(ms[z], siz[i] - siz[z]);
		}
	}
	cen[i] = x;
}

int n, m;
int x;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 2;i <= n;i++){
		scanf("%d", &x);
		fa[i] = x;
		v[x].push_back(i);
	}
	dfs(1);
	while(m--){
		scanf("%d", &x);
		printf("%d\n", cen[x]);
	}
}