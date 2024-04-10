#include <iostream>
#include <cstdlib>
#include <cstring>

typedef long long ll;

using namespace std;

ll MOD, l, r, k;

void umn(ll a[2][2], ll b[2][2])
{
	ll tmp[2][2];
	memset(tmp, 0, sizeof tmp);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++) a[i][j] = tmp[i][j];
	}
}

ll fib(ll x)
{
	if (x <= 2) return 1 % MOD;
	ll tmp[2][2];
	tmp[0][0] = 0;
	tmp[0][1] = 1;
	tmp[1][0] = 1;
	tmp[1][1] = 1;
	ll ans[2][2];
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;
	x -= 2;
//	cerr << "need " << x << endl;
	while (x)
	{
//		cout << tmp[0][0] << ' ' << tmp[0][1] << '\n' << tmp[1][0] << ' ' << tmp[1][1] << endl;
		if (x & 1) umn(ans, tmp);
		umn(tmp, tmp);
		x >>= 1;
	}
	return (ans[1][0] + ans[1][1]) % MOD;
}

int main()
{
	cin >> MOD >> l >> r >> k;
	l--;
	ll dmax = (r - l - 1) / (k - 1);
//	cerr << dmax << ' ' << r / dmax - l / dmax << endl;
	while (r / dmax - l / dmax < k)
	{
//		cerr << dmax << endl;
		if (dmax < 1e6) dmax--;
		else dmax = r / (r / dmax + 1);
	}
	cout << fib(dmax) << endl;
	return 0;
}