#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int MAXA = 100005;
const int maxx = 305;
const int maxn = 100005;
const int inf = 1e9;

int last[MAXA];
int ans[maxx][maxn];
int a[maxn], b[maxn];
int n, m, S, E;

int main()
{
	scanf("%d%d%d%d", &n, &m, &S, &E);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int j = 0; j < m; j++) scanf("%d", &b[j]);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= S / E; j++) ans[j][i] = inf;
	}
	ans[0][0] = 0;
	int answer = 0;
	for (int x = 0; x <= S / E; x++)
	{
		for (int i = 0; i < n; i++) ans[x][i + 1] = min(ans[x][i + 1], ans[x][i]);
		for (int i = 0; i < MAXA; i++) last[i] = m + 1;
		int cur = m;
		for (int i = 0; i <= n; i++)
		{
// 			cout << x << ' ' << i << ' ' << ans[x][i] << endl;
			while (cur >= ans[x][i])
			{
				last[b[cur]] = cur;
				cur--;
			}
			int kv_energy = x * E + i + ans[x][i];
			if (kv_energy > S) continue;
			answer = max(answer, x);
// 			cout << "next will " << last[a[i]] << endl;
			if (i >= n || last[a[i]] >= m) continue;
			ans[x + 1][i + 1] = min(ans[x + 1][i + 1], last[a[i]] + 1);
		}
	}
	cout << answer << endl;
	return 0;
}