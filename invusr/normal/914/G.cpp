#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 1000000;
const int L = 17;
const int N = 1 << L;
const int M = 1000000007;
const int I = 500000004;

inline int add(int a, const int &b)
{
	a += b;
	return a >= M ? a - M : a;
}
inline int dec(int a, const int &b)
{
	a -= b;
	return a < 0 ? a + M : a;
}

int n;
int fib[N], bit[N];

const int OR = 0;
const int AND = 1;
const int XOR = 2;

inline void transform(int *a, const int &type)
{
	for (int k = 1; k < N; k <<= 1)
		for (int s = 0; s < N; s += k << 1)
			for (int i = s; i < s + k; ++i)
			{
				int &e = a[i];
				int &o = a[i + k];

				if (type == OR)
					o = add(o, e);
				else if (type == AND)
					e = add(o, e);
				else
				{
					int bak_e = e, bak_o = o;
					e = add(bak_e, bak_o);
					o = dec(bak_e, bak_o);
				}
			}
}

inline void inverse_transform(int *a, const int &type)
{
	for (int k = 1; k < N; k <<= 1)
		for (int s = 0; s < N; s += k << 1)
			for (int i = s; i < s + k; ++i)
			{
				int &e = a[i];
				int &o = a[i + k];

				if (type == OR)
					o = dec(o, e);
				else if (type == AND)
					e = dec(e, o);
				else
				{
					int bak_e = e, bak_o = o;
					e = (s64)I * (bak_e + bak_o) % M;
					o = (s64)I * (bak_e - bak_o) % M;
					o = (o + M) % M;
				}
			}
}

int da[L + 1][N];
int db[N], dc[N], dd[N];

int main()
{
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < N; ++i)
		fib[i] = add(fib[i - 1], fib[i - 2]);
	for (int i = 1; i < N; ++i)
		bit[i] = bit[i >> 1] + (i & 1);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x = getint(), l = bit[x];
		da[l][x] = add(da[l][x], 1);
		db[x] = add(db[x], fib[x]);
		dc[x] = add(dc[x], 1);
	}

	transform(dc, XOR);
	for (int i = 0; i <= L; ++i)
		transform(da[i], OR);

	for (int i = 0; i < N; ++i)
		dc[i] = (s64)dc[i] * dc[i] % M;

	inverse_transform(dc, XOR);

	for (int i = 0; i <= L; ++i)
	{
		static int d[N];

		fill(d, d + N, 0);
		for (int j = 0; j <= i; ++j)
			for (int s = 0; s < N; ++s)
				d[s] = (d[s] + (s64)da[j][s] * da[i - j][s]) % M;

		inverse_transform(d, OR);

		for (int s = 0; s < N; ++s)
			if (bit[s] == i)
				dd[s] = (s64)fib[s] * d[s] % M;
	}

	for (int i = 0; i < N; ++i)
		dc[i] = (s64)dc[i] * fib[i] % M;

	transform(db, AND);
	transform(dc, AND);
	transform(dd, AND);

	for (int i = 0; i < N; ++i)
		db[i] = (s64)db[i] * dc[i] % M * dd[i] % M;

	inverse_transform(db, AND);

	int res = 0;
	for (int i = 0; i < L; ++i)
		res = add(res, db[1 << i]);

	cout << res << endl;

	return 0;
}