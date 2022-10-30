#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, q;
vector<pair<int, int> > v[maxn];
struct DSU{
	int fa[maxn];
	bool tag[maxn];
	void init(){
		for(int i = 1;i <= n;i++){
			fa[i] = i;
			for(int j = 0;j < v[i].size();j++){
				int co = v[i][j].second;
				if(!(co & 1)) tag[i] = true;
			}
		}
	}
	int find(int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
}d[30];

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({y, z}), v[y].push_back({x, z});
	}
	for(int j = 0;j < 30;j++){
		d[j].init();
		for(int i = 1;i <= n;i++) for(int k = 0;k < v[i].size();k++){
			int to = v[i][k].first, co = v[i][k].second;
			if(co & (1 << j)){
				int x = d[j].find(i), y = d[j].find(to);
				if(x ^ y){
					d[j].tag[y] |= d[j].tag[x];
					d[j].fa[x] = y;
				}
			}
		}
	}
	scanf("%d", &q);
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = 2;
		for(int i = 0;i < 30;i++){
			if(d[i].find(x) == d[i].find(y)){
				ans = 0;
				break;
			}
			if(i && d[i].tag[d[i].find(x)]) ans = 1;
		}
		printf("%d\n", ans);
	}
}