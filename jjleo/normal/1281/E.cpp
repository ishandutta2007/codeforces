#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
vector<pair<int, int> > v[maxn];
int x, y, z;

long long g, b;

int dfs1(int i, int fa){
	int x = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		if(dfs1(to, i)){
			x++;
			g += v[i][j].second;
		}
	}
	if(x & 1) return 0;
	else return 1;
}

int siz[maxn];
int c, d;

void dfs2(int i, int fa){
	siz[i] = 1;
	int x = 0; 
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		dfs2(to, i);
		siz[i] += siz[to]; 
		x = max(x, siz[to]);
	}
	x = max(x, n - siz[i]);
	if(x < c) c = x, d = i;
} 

void dfs3(int i, int fa, long long dep){
	b += dep;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		dfs3(to, i, dep + v[i][j].second);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), n <<= 1;
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({y, z}), v[y].push_back({x, z});
		}
		g = b = 0;
		dfs1(1, 0);
		c = n, dfs2(1, 0);
		dfs3(d, 0, 0);
		printf("%lld %lld\n", g, b);
	}
}