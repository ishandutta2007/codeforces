#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn = 55;
const ll MOD = 1000000007;

ll cur[maxn][maxn], ans[maxn][maxn];
ll n;
char s[10];
int m, k;

void mul(ll a[maxn][maxn], ll b[maxn][maxn], int n)
{
	ll tmp[maxn][maxn];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) a[i][j] = tmp[i][j];
	}
}

int main()
{
	scanf(LLD "%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++) cur[i][j] = 1;
	}
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%s", s);
		if ('a' <= s[0] && s[0] <= 'z') a = s[0] - 'a';
		else a = s[0] - 'A' + 26;
		if ('a' <= s[1] && s[1] <= 'z') b = s[1] - 'a';
		else b = s[1] - 'A' + 26;
		cur[a][b] = 0;
	}
	if (n == 1)
	{
		cout << m << endl;
		return 0;
	}
	n--;
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < m; i++) ans[i][i] = 1;
	while (n)
	{
		if (n & 1) mul(ans, cur, m);
		mul(cur, cur, m);
		n >>= 1;
	}
	ll answer = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++) answer = (answer + ans[i][j]) % MOD;
	}
	cout << answer << endl;
	return 0;
}