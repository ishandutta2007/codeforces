#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int m, n;
int a[maxn], b[maxn];

int fa[maxn], siz[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

struct Edge{
	int x, y, z;
};

inline bool cmp(Edge a, Edge b){
	return a.z > b.z;
}

vector<Edge> v;
int x, y, z;


int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n + m;i++) fa[i] = i, siz[i] = 1;
	long long ans = 0;
	for(int i = 1;i <= m;i++){
		scanf("%d", &x);
		while(x--){
			scanf("%d", &y);
			v.push_back((Edge){y, i + n, a[i] + b[y]});
			ans += a[i] + b[y];
		}
	} 
	sort(v.begin(), v.end(), cmp);
	for(int i = 0;i < v.size();i++){
		x = v[i].x, y = v[i].y, z = v[i].z;
		x = find(x), y = find(y);
		if(x == y) continue;
		if(siz[x] > siz[y]) swap(x, y);
		fa[x] = y, siz[y] += siz[x];
		ans -= z;
	}
	printf("%lld", ans);
	
}