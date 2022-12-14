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

const int MaxN = 100005;

int n;
s64 s, t, l;
s64 a[MaxN];

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> s >> t >> l;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	a[n + 1] = 0x3f3f3f3f3f3f3f3fll;

	if (n == 0)
	{
		cout << s << endl;
		return 0;
	}

	s64 now = s, num = max(0ll, s - (a[1] - 1)), res = a[1] > s ? s : a[1] - 1;
	for (int i = 1; i <= n; ++i)
	{
		now = max(now, a[i]);
		now += l;
		if (now >= t)
			break;

		if (i == n || a[i] != a[i + 1])
		{
			s64 x = min(a[i + 1] - 1, now);
			s64 w = now - x;
			if (w < num && x + l - 1 < t)
				num = w, res = x;
		}
	}

	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}