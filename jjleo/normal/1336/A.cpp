#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;


int n, k;
vector<int> v[maxn]; 
int x, y;
int siz[maxn], dep[maxn];
int a[maxn];
ll ans;

void dfs(int i, int fa){
	dep[i] = dep[fa] + 1;
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] == fa) continue;
		dfs(v[i][j], i);
		siz[i] += siz[v[i][j]];
	}
}

inline bool cmp(int x, int y){
	return dep[x] - (siz[x] - 1) > dep[y] - (siz[y] - 1);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) a[i] = i;
	dep[0] = -1;dfs(1, 0);
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1;i <= k;i++) ans += dep[a[i]] - (siz[a[i]] - 1);
	printf("%lld", ans);
}