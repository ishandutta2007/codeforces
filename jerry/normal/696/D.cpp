#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mat[50][205][205];
ll vec[205];
int _;
struct node
{
	int ch[30];
	vector<int> sl;
	int va;
	node()
	{
		for (int i = 0;i < 30;i++) ch[i] = -1;
		va = 0;
	}
} all[205];

void dfs(int at, int par, int wot)
{
	all[at].sl.push_back(0);
	if (par != -1)
	{
		for (int u: all[par].sl) if (all[u].ch[wot] != -1) all[at].sl.push_back(all[u].ch[wot]);
		ll cu = 0;
		for (int u: all[at].sl) cu += all[u].va;
		for (int u: all[at].sl) mat[0][u][par] = max(mat[0][u][par], cu);
	}
	for (int i = 0;i < 30;i++) if (all[at].ch[i] != -1) dfs(all[at].ch[i], at, i);
}

char buf[205];
int a[205];
int n;
ll l;

void pmat(int z)
{
	for (int i = 0;i < _;i++)
	{
		for (int j = 0;j < _;j++)
		{
			if (mat[z][i][j] == -(1ll<<61)) printf("\x1b[31m  -\x1b[0m ");
			else if (mat[z][i][j] == 0) printf("\x1b[33m  0\x1b[0m ");
			else printf("\x1b[32m% 3lld\x1b[0m ", mat[z][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mult(ll x[205][205], ll y[205][205])
{
	for (int i = 0;i < _;i++) for (int j = 0;j < _;j++) for (int k = 0;k < _;k++) x[i][j] = max(x[i][j], y[i][k]+y[k][j]);
	for (int i = 0;i < _;i++) for (int j = 0;j < _;j++) if (x[i][j] < 0) x[i][j] = -(1ll<<61);
}

void mult(ll x[205][205])
{
	ll y[205];
	for (int i = 0;i < 205;i++) y[i] = -(1ll<<61);
	for (int i = 0;i < _;i++) for (int j = 0;j < _;j++)
		y[i] = max(y[i], x[i][j]+vec[j]);
	for (int i = 0;i < _;i++) vec[i] = y[i];
}

int main()
{
	_ = 1;
	for (int i = 0;i < 50;i++) for (int j = 1;j < 205;j++) for (int k = 0;k < 205;k++) mat[i][j][k] = -(1ll<<61);
	for (int i = 1;i < 205;i++) vec[i] = -(1ll<<61);
	scanf("%d%lld", &n, &l);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	for (int i = 0;i < n;i++)
	{
		scanf("%s", buf);
		int at = 0;
		for (int j = 0;buf[j];j++)
		{
			buf[j] -= 'a';
			if (all[at].ch[buf[j]] == -1) all[at].ch[buf[j]] = _++;
			at = all[at].ch[buf[j]];
		}
		all[at].va += a[i];
	}
	dfs(0, -1, -1);
	for (int i = 1;i < 50;i++) mult(mat[i], mat[i-1]);
	for (int i = 0;i < 50;i++) if (l&(1ll<<i)) mult(mat[i]);
//	pmat(0); pmat(1); pmat(2);
	ll ans = 0;
	for (int i = 0;i < _;i++) ans = max(ans, vec[i]);
	printf("%lld\n", ans);
	return 0;
}