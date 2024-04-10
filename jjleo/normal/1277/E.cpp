#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m, a, b;
vector<int> v[maxn];
int x, y;

int siz[maxn];
bool tag[maxn], bak[maxn];
int dep[maxn];
int ans;
int f[maxn];

void dfs(int i, int fa){
	siz[i] = 1;
	tag[i] = tag[fa], dep[i] = dep[fa] + 1;
	if(tag[i]) bak[i] = bak[fa];
	if(i == b) tag[i] = true, bak[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		if(dep[to]){
			if(i != b && tag[i]){
				if(dep[to] < dep[b]) bak[i] = false;
			}
		}
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		if(!dep[to]){
			dfs(to, i);
			siz[i] += siz[to];
			if(i != b && tag[i] && !bak[to]) bak[i] = false;
			if(i == b && bak[to]){
				ans += siz[to];
			}
		}
	}
	//printf("%d %d--\n", i, bak[i]);
	//if(i ^ b) ans += bak[i];
	f[i] = fa;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for(int i = 1;i <= n;i++) tag[i] = dep[i] = bak[i] = 0, v[i].clear();
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}
		ans = 0;
		dfs(a, 0);
		while(f[b] ^ a) b = f[b];
		printf("%lld\n", 1ll * ans * (siz[a] - siz[b] - 1));
	}
}