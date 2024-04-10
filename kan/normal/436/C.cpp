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

const int maxn = 1005;

char p[maxn][105];
int dist[maxn];
int d[maxn][maxn];
int n, m, k, W;
vector<pair<int, int> > answer;
bool was[maxn];
int from[maxn];

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &W);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++) scanf("%s", p[i] + j * m);
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			d[i][j] = 0;
			for (int t = 0; t < n * m; t++) d[i][j] += p[i][t] != p[j][t];
			d[i][j] = min(d[i][j] * W, n * m);
			d[j][i] = d[i][j];
		}
	}
	for (int i = 0; i < k; i++) dist[i] = n * m, was[i] = false;
	int ans = 0;
	for (int IT = 0; IT < k; IT++)
	{
		int cur = -1;
		int curd = n * m + 2;
		for (int i = 0; i < k; i++) if (!was[i] && dist[i] < curd)
		{
			curd = dist[i];
			cur = i;
		}
		assert(cur != -1);
		was[cur] = true;
		ans += dist[cur];
		if (dist[cur] == n * m) answer.push_back(make_pair(cur, 0));
		else answer.push_back(make_pair(cur, from[cur] + 1));
		for (int i = 0; i < k; i++) if (!was[i] && dist[i] > d[cur][i])
		{
			dist[i] = d[cur][i];
			from[i] = cur;
		}
	}
	printf("%d\n", ans);
	for (auto x : answer) printf("%d %d\n", x.first + 1, x.second);
	return 0;
}