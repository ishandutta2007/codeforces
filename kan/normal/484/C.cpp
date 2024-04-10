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

const int maxn = 1000006;
const int LOG = 20;

int p[LOG][maxn];
char s[maxn], t[maxn];
int dist[maxn];
int n, m;

int up(int x, int b)
{
// 	cout << "up " << b << ' ' << x << endl;
	for (int j = LOG - 1; j >= 0; j--) if (b >= (1 << j))
	{
		x = p[j][x];
		b -= (1 << j);
	}
// 	cout << x << endl;
	return x;
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &m);
	for (int IT = 0; IT < m; IT++)
	{
		int k, d;
		scanf("%d%d", &k, &d);
		int cur = 0;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j * d + i < k; j++)
			{
				p[0][j * d + i] = cur++;
			}
		}
		assert(cur == k);
		for (int i = 0; i < k; i++) dist[i] = -1;
		for (int i = 1; i < k; i++) p[0][i]--;
		dist[0] = 0;
		for (int i = 1; i < k; i++) if (p[0][i] == 0) dist[i] = 1;
		for (int j = 1; j < LOG; j++)
		{
			for (int i = 0; i < k; i++)
			{
				p[j][i] = p[j - 1][p[j - 1][i]];
// 				cout << ' ' << j << ' ' << i << ' ' << p[j][i] << endl;
				if (p[j][i] == 0 && dist[i] == -1) dist[i] = (1 << (j - 1)) + dist[p[j - 1][i]];
			}
		}
		for (int i = 0; i < k; i++) if (dist[i] == -1) dist[i] = n + 5;
// 		for (int i = 0; i < k; i++) cout << i << ' ' << p[0][i] << ' ' << dist[i] << endl;
		for (int i = 0; i < n; i++)
		{
			int whbegin = (i < k ? i : k - 1);
			int howlong = min(dist[whbegin], min(n - i, n - k + 1));
			int whend = up(whbegin, howlong) + max(0, i - (k - 1)) + howlong;
// 			cout << i << ' ' << whbegin << ' ' << howlong << ' ' << whend << endl;
			t[whend] = s[i];
		}
		for (int i = 0; i < n; i++) s[i] = t[i];
		printf("%s\n", s);
	}
	return 0;
}