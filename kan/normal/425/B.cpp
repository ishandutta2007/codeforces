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

const int maxn = 105;

int a[maxn][maxn], b[maxn][maxn];
int n, m, k;
bool badrow[maxn], badcol[maxn];
int answer, addans;

void solve(int n, int m, int wasn)
{
	assert(n <= 10);
	int km = 1 << n;
	for (int mask = 0; mask < km; mask++)
	{
		int curans = __builtin_popcount(mask);
		for (int i = 0; i < m; i++)
		{
			int cursum = 0;
			for (int j = 0; j < n; j++) cursum += (b[j][i] ^ ((mask >> j) & 1));
			curans += min(cursum, 1 + wasn - cursum);
		}
		answer = min(answer, curans + addans);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	}
	answer = n * m + 2;
	addans = 0;
	for (int IT = 0; IT < 2; IT++)
	{
		memset(badcol, 0, sizeof(badcol));
		memset(badrow, 0, sizeof(badrow));
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++) if ((a[i][j] ^ a[i][0] ^ a[0][j] ^ a[0][0]) != 0)
			{
				badrow[i] = true;
				badcol[j] = true;
			}
		}
		int kvbadrows = 0;
		for (int i = 0; i < n; i++) kvbadrows += badrow[i];
		if (kvbadrows <= k)
		{
			int cur = 0;
			for (int i = 1; i < n; i++) if (badrow[i])
			{
				for (int j = 1; j < m; j++) b[cur][j - 1] = (a[i][j] ^ a[i][0] ^ a[0][j] ^ a[0][0]);
				cur++;
			}
			solve(kvbadrows, m - 1, n - 1);
		}
		int kvbadcols = 0;
		for (int i = 0; i < m; i++) kvbadcols += badcol[i];
		if (kvbadcols <= k)
		{
			int cur = 0;
			for (int j = 1; j < m; j++) if (badcol[j])
			{
				for (int i = 1; i < n; i++) b[cur][i - 1] = (a[i][j] ^ a[i][0] ^ a[0][j] ^ a[0][0]);
				cur++;
			}
			solve(kvbadcols, n - 1, m - 1);
		}
		
		a[0][0] ^= 1;
		addans ^= 1;
	}
	if (answer <= k) cout << answer << endl;
	else cout << -1 << endl;
	return 0;
}