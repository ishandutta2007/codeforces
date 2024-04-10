#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

s64 p;
int k;

int n;

s64 vl[233333];
s64 vr[233333];

s64 out[233333];

inline s64 f(s64 a, s64 b)
{
	return a < 0 ? -((-a - 1) / b + 1) : a / b;
}
inline s64 g(s64 a, s64 b)
{
	return a < 0 ? -(-a / b) : (a - 1) / b + 1;
}

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> p >> k;

	if (p < k)
	{
		cout << 1 << endl;
		cout << p << endl;
		return 0;
	}

	s64 l = g(-p, k);
	s64 r = f(k - 1 - p, k);
	vl[1] = l, vr[1] = r;

//	cout << l << ' ' << r << endl;

	n = 2;
	while (true)
	{
	//	1 <= kx + L <= k-1
	//	1-L <= kx <= k-1-L
		s64 nl = g(-r, k);
		s64 nr = f(k - 1 - l, k);
		vl[n] = nl, vr[n] = nr;

	//	if (n <= 15)
	//		cout << nl << ' ' << nr << endl;
		if (nl > nr)
			break;

		s64 il = max(nl, 1ll);
		s64 ir = min(nr, k - 1ll);
		if (il <= ir)
		{
			out[n] = il;
			for (int i = n - 1; i; --i)
			{
				s64 a = k * out[i + 1];
				s64 tl = -a, tr = k - 1 - a;
				s64 pl = max(tl, vl[i]);
				s64 pr = min(tr, vr[i]);
				assert(pl <= pr);
				out[i] = pl;
			}

			cout << n + 1 << endl;
			printf("%lld", out[1] * k + p);
			for (int i = 1; i <= n; ++i)
				printf(" %lld", out[i] + out[i + 1] * k);
			puts("");

			return 0;
		}

		if ((r32)clock() / CLOCKS_PER_SEC > 0.9)
			break;

		++n;

		l = nl, r = nr;
	}

	cout << -1 << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}