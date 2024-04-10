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

const int maxn = 100005;

char s[maxn][2][55];
bool ans[maxn][2];
int p[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s%s", s[i][0], s[i][1]);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
	ans[0][0] = true;
	ans[0][1] = true;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ans[i][j] = false;
			for (int k = 0; k < 2; k++) ans[i][j] |= ans[i - 1][k] && (strcmp(s[p[i - 1]][k], s[p[i]][j]) == -1);
		}
	}
	cout << (ans[n - 1][0] || ans[n - 1][1] ? "YES" : "NO") << endl;
	return 0;
}