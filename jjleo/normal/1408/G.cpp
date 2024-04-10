#include <bits/stdc++.h>
#define maxn 1505

using namespace std;

const int p = 998244353;

int fa[maxn], siz[maxn], cnt[maxn];
int f[maxn][maxn], g[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int n;
int x;

struct Edge{
	int x, y, z;
};
vector<Edge> v;

inline bool cmp(Edge a, Edge b){
	return a.z < b.z;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d", &x);
			if(i < j) v.push_back((Edge){i, j, x});
		}
	}
	for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1, f[i][1] = 1; 
	sort(v.begin(), v.end(), cmp);
	for(int i = 0;i < v.size();i++){
		int x = find(v[i].x), y = find(v[i].y);
		if(x == y){
			cnt[x]++;
			if(cnt[x] == siz[x] * (siz[x] - 1) / 2) f[x][1] = (f[x][1] + 1) % p;
		}else{
			if(siz[x] > siz[y]) swap(x, y);
			for(int j = 1;j <= siz[x] + siz[y];j++) g[j] = 0;
			for(int j = 1;j <= siz[x];j++){
				for(int k = 1;k <= siz[y];k++){
					g[j + k] = (g[j + k] + 1ll * f[x][j] * f[y][k]) % p;
				}
			}
			fa[x] = y, siz[y] += siz[x], cnt[y] += cnt[x] + 1;
			for(int j = 1;j <= siz[y];j++) f[y][j] = g[j];
			if(cnt[y] == siz[y] * (siz[y] - 1) / 2) f[y][1] = (f[y][1] + 1) % p;
		}
	}
	x = find(1);
	for(int i = 1;i <= n;i++) printf("%d ", f[x][i]);
}