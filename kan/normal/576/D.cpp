#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back

const int maxn = 155;

struct tedge
{
	int a, b, d;
};

inline bool operator<(const tedge &a, const tedge &b)
{
	return a.d < b.d;
}

int can[maxn][maxn], canpow[maxn][maxn];
int tmp[maxn][maxn], tmpmul[maxn][maxn];
int cur[maxn], nextcur[maxn];
int n, m;
int last;
tedge e[maxn];
int d[maxn];
queue<int> q;

void mul(int a[maxn][maxn], int b[maxn][maxn])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) tmpmul[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) if (a[i][j] > 0)
		{
			for (int k = 0; k < n; k++) tmpmul[i][k] += a[i][j] * b[j][k];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) a[i][j] = min(1, tmpmul[i][j]);
	}
}

inline void powcan(int st)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) tmp[i][j] = can[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) canpow[i][j] = (i == j);
	}
	while (st)
	{
		if (st & 1) mul(canpow, tmp);
		mul(tmp, tmp);
		st >>= 1;
	}
}

void doall(int kv)
{
	if (kv == 0) return;
// 	cout << "doall " << last << ' ' << kv << endl;
	for (int i = 0; i < n; i++) d[i] = n + 1;
	for (int i = 0; i < n; i++) if (cur[i] > 0)
	{
		q.push(i);
		d[i] = 0;
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < n; i++) if (can[x][i] && d[i] > d[x] + 1)
		{
			d[i] = d[x] + 1;
			q.push(i);
		}
	}
	if (d[n - 1] != n + 1 && d[n - 1] <= kv)
	{
		printf("%d\n", last + d[n - 1]);
		exit(0);
	}
// 	for (int i = 0; i < n; i++) printf("%d", cur[i]);
// 	printf("\n");
// 	printf("\n");
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n; j++) printf("%d", can[i][j]);
// 		printf("\n");
// // 	}
	powcan(kv);
	for (int i = 0; i < n; i++) nextcur[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) nextcur[j] += cur[i] * canpow[i][j];
	}
	for (int i = 0; i < n; i++) cur[i] = min(1, nextcur[i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].d);
		e[i].a--;
		e[i].b--;
	}
	sort(e, e + m);
	cur[0] = 1;
	last = 0;
	for (int i = 0; i < m; i++)
	{
		doall(e[i].d - last);
		can[e[i].a][e[i].b] = 1;
		last = e[i].d;
// 		cerr << i << endl;
	}
	doall(n);
	printf("Impossible\n");
	return 0;
}