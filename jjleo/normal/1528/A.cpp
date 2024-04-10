#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
vector<int> v[maxn];
int x, y;
int l[maxn], r[maxn];
ll f[maxn][2];

void dfs(int i, int fa){
	f[i][0] = f[i][1] = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		f[i][0] += max(f[to][0] + abs(l[i] - l[to]), f[to][1] + abs(l[i] - r[to]));
		f[i][1] += max(f[to][0] + abs(r[i] - l[to]), f[to][1] + abs(r[i] - r[to]));
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d%d", &l[i], &r[i]), v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1, 0);
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
}