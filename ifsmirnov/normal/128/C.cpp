#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define mp make_pair
const int maxn = 1005;
const int mod = 1e9+7;
typedef long long i64;

int mmul (int a, int b)
{
	return ((i64)a*(i64)b) % mod;
}
int madd (int a, int b)
{
	return (a+b)%mod;
}

int n, m, k;
int cnk[maxn][maxn];
void init()
{
	int t = max(n, m);
	forn(i, t+1)
		cnk[i][0] = 1;
	fore(i, 1, t) fore(j, 1, i)
		cnk[i][j] = madd(cnk[i-1][j], cnk[i-1][j-1]);
}
int getf(int n, int k)
{
	int s = 0;
	fore(i, 1, n-1)
	{
		int pref = i-1;
		int suf = n-i-1;
		s = madd(mmul(cnk[pref][k-1], cnk[suf][k]), s);
	}
	return s;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	init();
	cout << mmul(getf(n, k), getf(m, k)) << endl;
	
	return 0;
}