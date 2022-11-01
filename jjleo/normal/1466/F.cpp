#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

const int p = 1e9 + 7;

int n, m, k;
int x, y;
pair<pair<int, int>, int> a[maxn];
vector<int> ans;

int fa[maxn], siz[maxn];
bool vis[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &k);
		if(k == 1){
			scanf("%d", &x);
			a[i] = {{x, m + 1}, i};
		}else{
			scanf("%d%d", &x, &y);
			if(x > y) swap(x, y);
			a[i] = {{x, y}, i};
		}
	}
	for(int i = 1;i <= m;i++) fa[i] = i, siz[i] = 1;
	for(int i = 1;i <= n;i++){
		int x = a[i].first.first, y = a[i].first.second, z = a[i].second;
		if(y == m + 1){
			x = find(x);
			if(vis[x]) continue;
			vis[x] = true;
			ans.push_back(z);
		}else{
			x = find(x), y = find(y);
			if(x == y) continue;
			if(vis[x] && vis[y]) continue;
			if(siz[x] > siz[y]) swap(x, y);
			fa[x] = y, siz[y] += siz[x], vis[y] |= vis[x];
			ans.push_back(z);
		} 
	}
	int x = 1;
	for(int i = 1;i <= ans.size();i++) x = (x + x) % p;
	printf("%d %d\n", x, ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
}