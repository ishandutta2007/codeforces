#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2e6 + 10;

int n, m;

int _x[MAXN], _y[MAXN];
ll f[MAXN];
vector<PII> E[MAXN];
int a[MAXN], dep[MAXN], vis[MAXN];
int MAKI;

int dfs(int u, int fa, int dp, int num){
	dep[u] = dp;
	ll now = a[u];
	for (auto &v : E[u])
		if (v.st != fa && !dep[v.st]){
			dfs(v.st, u, dp + 1, v.nd);
			now -= f[v.nd];
		}
	f[num] = now;
}

int DFS(int u, int fa, int num){
	vis[u] = 1;
	ll now = a[u];
	for (auto &v : E[u])
		if (v.st != fa && !vis[v.st]){
			DFS(v.st, u, v.nd);
			now -= f[v.nd];
		}
	f[num] = now;
}

int gao(int flag){
	for (int i = 0; i <= m; i++)
		f[i] = 0, vis[i] = 0;
	int fd = 0;
	for (int i = 1; i <= m; i++)
		if ((dep[_x[i]]&1) == (dep[_y[i]]&1)){
			fd = i;
			f[i] = flag * MAKI / 2;
			a[_x[i]] -= f[i];
			a[_y[i]] -= f[i];
			break;
		}
	if (fd == 0) return 0;
	DFS(1, 0, 0);
	a[_x[fd]] += f[fd];
	a[_y[fd]] += f[fd];
	return f[0] == 0;
}

void printans(){
	puts("YES");
	for (int i = 1; i <= m; i++)
		printf("%lld\n", f[i]);
	return ;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		_x[i] = x, _y[i] = y;
		E[x].push_back(PII(y, i));
		E[y].push_back(PII(x, i));
	}
	dfs(1, 0, 1, 0);
	if (f[0] == 0){
		printans();
		return 0;
	}
	MAKI = f[0];
	//cout << MAKI << endl;
	if (gao(1)){
		printans();
		return 0;
	}
	if (gao(-1)){
		printans();
		return 0;
	}
	puts("NO");
	return 0;
}