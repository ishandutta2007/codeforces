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

const int maxn = 2005;

char p[maxn][maxn];
int n, m;

inline bool check(int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	return p[x][y] == c;
}

int main()
{
	scanf("%d%d%*d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", p[i]);
	for (int j = 0; j < m; j++)
	{
		int curans = 0;
		for (int i = 0; i < n; i++)
		{
			curans += check(i, j - i, 'R');
			curans += check(i, j + i, 'L');
			curans += check(2 * i, j, 'U');
		}
		cout << curans << ' ';
	}
	cout << endl;
	return 0;
}