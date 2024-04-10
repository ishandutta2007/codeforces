#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n, m;
vector<int> v[maxn];
ll a[maxn];
int x, y;
bool vis[maxn], tag, col[maxn];

void dfs(int i){
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]){
			if(col[i] == col[to]) tag = true;
		}else{
			col[to] = col[i] ^ 1;
			dfs(to);
			a[i] -= a[to];
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false;
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[i] = x - a[i];
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}	
		tag = false;
		dfs(1);
		//printf("%lld--\n", a[1]);
		if(a[1] & 1) puts("NO");
		else if(!a[1] || tag) puts("YES");
		else puts("NO"); 
	}
}