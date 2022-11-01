#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, m;
vector<int> v[maxn];
ll p[maxn], h[maxn];
int x, y;

bool suc;

void dfs(int i, int fa){
	if(!suc) return;
	ll g = 0, siz = 0;
	for(int j = 0;j < v[i].size();j++){
		if(!suc) return;
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		siz += p[to];
		g += h[to];
	}
	if(!suc) return;
	ll x = siz + h[i] + p[i];
	if(x < 0 || (x & 1)){
		suc = false;
		return;
	}
	h[i] = x / 2;
	ll y = p[i] + siz - h[i];
	if(y < 0){
		suc = false;
		return;
	}
	if(h[i] - max(0ll, p[i] - y) < g){
		suc = false;
		return;
	}
	p[i] += siz;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%lld", &p[i]);
		for(int i = 1;i <= n;i++) scanf("%lld", &h[i]), v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		suc = true;
		dfs(1, 0);
		puts(suc ? "YES" : "NO");
	}
}