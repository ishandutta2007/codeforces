#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, q, s, d;
vector<pair<int, int> > v[maxn];
int a[maxn], val[maxn];
int x, y;

int fa[maxn], siz[maxn], mn[maxn], id1[maxn], id2[maxn];
int nxt[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline bool merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return false;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x]; 
	return true;
}

/*
void solve(int l, int r){
	if(l == r) return;
	int mid = l + r >> 1;
	int id1, id2, mn = 1e9, x = mid + 1;
	for(int i = l;i <= mid;i++){
		while(x < r && a[x] < a[i] + d) x++;
		if(abs(a[x] - a[i] - d) < mn) mn = abs(a[x] - a[i] - d), id1 = i, id2 = x;
		if(x > mid + 1 && abs(a[x - 1] - a[i] - d) < mn) mn = abs(a[x - 1] - a[i] - d), id1 = i, id2 = x - 1;
	}
	x = mid + 1;
	for(int i = l;i <= mid;i++){
		while(x < r && a[x] < a[i] - d) x++;
		if(x > mid + 1 && abs(a[x - 1] - a[i] - d) < mn) mn = abs(a[x - 1] - a[i] - d), id1 = i, id2 = x - 1;
	}
	v[id1].push_back({id2, mn}), v[id2].push_back({id1, mn});
	solve(l, mid), solve(mid + 1, r);
}
*/

void dfs(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		val[to] = max(val[i], v[i][j].second), dfs(to, i);
	}
}


int main(){
	scanf("%d%d%d%d", &n, &q, &s, &d);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), fa[i] = i, siz[i] = 1;
	while(1){
		for(int i = 1;i <= n;i++) mn[i] = 1e9;
		nxt[1] = 0;for(int i = 2;i <= n;i++) nxt[i] = find(i) == find(i - 1) ? nxt[i - 1] : i - 1;
		x = 1;
		for(int i = 1;i <= n;i++){
			while(x < n && a[x + 1] <= a[i] + d) x++;
			int I = find(i);
			if(find(x) != I && abs(a[x] - a[i] - d) < mn[I]) mn[I] = abs(a[x] - a[i] - d), id1[I] = i, id2[I] = x;
			if(nxt[x] && find(nxt[x]) != I && abs(a[nxt[x]] - a[i] - d) < mn[I]) mn[I] = abs(a[nxt[x]] - a[i] - d), id1[I] = i, id2[I] = nxt[x];
		}
		x = 1;
		for(int i = 1;i <= n;i++){
			while(x < n && a[x + 1] <= a[i] - d) x++;
			int I = find(i);
			if(find(x) != I && abs(a[x] - a[i] + d) < mn[I]) mn[I] = abs(a[x] - a[i] + d), id1[I] = i, id2[I] = x;
			if(nxt[x] && find(nxt[x]) != I && abs(a[nxt[x]] - a[i] + d) < mn[I]) mn[I] = abs(a[nxt[x]] - a[i] + d), id1[I] = i, id2[I] = nxt[x];
		}
		nxt[n] = 0;for(int i = n - 1;i;i--) nxt[i] = find(i) == find(i + 1) ? nxt[i + 1] : i + 1;
		x = 1;
		for(int i = 1;i <= n;i++){
			while(x < n && a[x] < a[i] + d) x++;
			int I = find(i);
			if(find(x) != I && abs(a[x] - a[i] - d) < mn[I]) mn[I] = abs(a[x] - a[i] - d), id1[I] = i, id2[I] = x;
			if(nxt[x] && find(nxt[x]) != I && abs(a[nxt[x]] - a[i] - d) < mn[I]) mn[I] = abs(a[nxt[x]] - a[i] - d), id1[I] = i, id2[I] = nxt[x];
		}
		x = 1;
		for(int i = 1;i <= n;i++){
			while(x < n && a[x] < a[i] - d) x++;
			int I = find(i);
			if(find(x) != I && abs(a[x] - a[i] + d) < mn[I]) mn[I] = abs(a[x] - a[i] + d), id1[I] = i, id2[I] = x;
			if(nxt[x] && find(nxt[x]) != I && abs(a[nxt[x]] - a[i] + d) < mn[I]) mn[I] = abs(a[nxt[x]] - a[i] + d), id1[I] = i, id2[I] = nxt[x];
		}
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(mn[i] == 1e9) continue;
			tag = true;
			if(merge(id1[i], id2[i])) v[id1[i]].push_back({id2[i], mn[i]}), v[id2[i]].push_back({id1[i], mn[i]});
		}
		if(!tag) break;
	}
	dfs(s, 0);
	while(q--){
		scanf("%d%d", &x, &y);
		puts(y >= val[x] ? "YES" : "NO");
	}
}