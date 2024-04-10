#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n, m;
int a[maxn];
pair<int, int> f[maxn], g[maxn], F[maxn], G[maxn];
inline pair<int, int> get(pair<int, int> &a, pair<int, int> &b){
	return {min(a.first, b.first), max(a.second, b.second)};
}
int Id[maxn];
pair<int, int> p[maxn], q[maxn];
int cnt;

inline int id(int x, int y){
	return (x - 1) * m + y;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[id(i, j)]);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				f[id(i, j)] = {a[id(i, j)], a[id(i, j)]};
				if(j > 1) f[id(i, j)] = get(f[id(i, j)], f[id(i, j - 1)]);
			}
			for(int j = m;j;j--){
				g[id(i, j)] = {a[id(i, j)], a[id(i, j)]};
				if(j < m) g[id(i, j)] = get(g[id(i, j)], g[id(i, j + 1)]);
			}
		}
		bool tag = false;
		for(int j = 1;j < m;j++){
			for(int i = 1;i <= n;i++) p[i] = {f[id(i, j)].first, i}, p[i + n] = {f[id(i, j)].second, -i};
			sort(p + 1, p + 1 + n * 2);
			int cnt = 0, tot = 0;
			pair<int, int> now = {1e7, -1e7};
			for(int i = 1;i <= n * 2;i++){
				if(p[i].second < 0) tot--;
				else{
					tot++;
					now = get(now, g[id(p[i].second, j + 1)]);
					Id[p[i].second] = cnt + 1;
				}
				if(i < n * 2 && p[i].first == p[i + 1].first) continue;
				if(tot == 0){
					q[++cnt] = now;
					now = {1e7, -1e7};
				}
			}
			for(int k = 1;k <= cnt;k++){
				F[k] = q[k];
				if(k > 1) F[k] = get(F[k], F[k - 1]);
			}
			for(int k = cnt;k;k--){
				G[k] = q[k];
				if(k < cnt) G[k] = get(G[k], G[k + 1]);
			}
			for(int k = 1;k < cnt;k++){
				if(F[k].first > G[k + 1].second){
					puts("YES");
					for(int i = 1;i <= n;i++) printf(Id[i] <= k ? "B" : "R");
					printf(" %d\n", j);
					tag = true;
					break;
				}
			}
			if(tag) break;
		}
		if(!tag) puts("NO");
	}
}