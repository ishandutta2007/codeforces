#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 500000;
const int MaxTN = 1048576;
const int M = 998244353;
const int FFT_G = 3;

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

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

int tn, tl, inv;
int rev[MaxTN];
int root[MaxTN];

inline void fft_init(int n)
{
	tn = 1, tl = 0;
	while (tn < n)
		tn <<= 1, ++tl;
	inv = modpow(tn, M - 2);

	for (int i = 1; i < tn; ++i)
	{
		int l = rev[i >> 1] >> 1;
		rev[i] = l | ((i & 1) << tl - 1);
	}

	int bn = tn >> 1;
	root[bn + 0] = 1;
	root[bn + 1] = modpow(FFT_G, (M - 1) / tn);
	for (int i = 2; i < bn; ++i)
		root[bn + i] = (s64)root[bn + i - 1] * root[bn + 1] % M;
	for (int i = bn - 1; i > 0; --i)
		root[i] = root[i << 1];
}

inline void fft(int *a, int type)
{
	if (type)
		reverse(a + 1, a + tn);

	for (int i = 0; i < tn; ++i)
	{
		int r = rev[i];
		if (i < r)
			swap(a[i], a[r]);
	}

	for (int k = 1; k < tn; k <<= 1)
	{
		int *g = root + k;
		for (int s = 0; s < tn; s += k << 1)
		{
			int *w = g;
			for (int i = s; i < s + k; ++i, ++w)
			{
				int o = a[i], e = (s64)a[i + k] * *w % M;
				a[i] = add(o, e);
				a[i + k] = dec(o, e);
			}
		}
	}

	if (type)
	{
		for (int i = 0; i < tn; ++i)
			a[i] = (s64)a[i] * inv % M;
	}
}

int m, n;
string s;

int da[MaxTN];
int db[MaxTN];

bool mark[MaxN + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m;
	while (m--)
	{
		cin >> n >> s;

		fft_init(n * 2 + 1);

		fill(da, da + tn, 0);
		fill(db, db + tn, 0);
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'V')
				da[i] = 1;
			if (s[i] == 'K')
				db[n - i - 1] = 1;
		}

		fft(da, 0);
		fft(db, 0);
		for (int i = 0; i < tn; ++i)
			da[i] = (s64)da[i] * db[i] % M;
		fft(da, 1);

		fill(mark, mark + n + 1, false);
		for (int i = 1; i < n; ++i)
			mark[i] = da[n - i - 1] || da[n + i - 1];
		for (int i = 1; i < n; ++i)
			for (int j = i + i; j < n; j += i)
				mark[i] |= mark[j];

		vector<int> result;
		for (int i = 1; i <= n; ++i)
			if (!mark[i])
				result.push_back(i);

		cout << result.size() << endl;
		for (int i : result)
			cout << i << ' ';
		cout << endl;
	}

	return 0;
}