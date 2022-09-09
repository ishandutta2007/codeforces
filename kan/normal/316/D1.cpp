#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int MOD = 1000000007;

const int maxn = 505;

int ans[maxn][maxn][5];
int n;

inline void upd(int &a, ll b)
{
	a = (a + b) % MOD;
}

int main()
{
	scanf("%d", &n);
	int kv0 = 0;
	int kv1 = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1) kv0++;
		else kv1++;
	}
	memset(ans, 0, sizeof(ans));
	int answer = 0;
	if (kv0 > 0) ans[kv0 - 1][kv1][1] = 1;
	else ans[kv0][kv1 - 1][0] = 1;
	for (int i = kv0; i >= 0; i--)
	{
		for (int j = kv1; j >= 0; j--)
		{
			for (int kz = 0; kz <= 2; kz++)
			{
				if (i > 0) upd(ans[i - 1][j][kz + 1], (ll)ans[i][j][kz] * i);
				if (j > 0) upd(ans[i][j - 1][kz], (ll)ans[i][j][kz] * j);
				if (i > 0) upd(ans[i - 1][j][1], ans[i][j][kz]);
				else if (j > 0) upd(ans[i][j - 1][0], ans[i][j][kz]);
				else upd(answer, ans[i][j][kz]);
			}
		}
	}
	cout << answer << endl;
	return 0;
}