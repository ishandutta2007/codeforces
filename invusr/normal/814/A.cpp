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

const int MaxN = 105;

int n, k;
int a[MaxN], b[MaxN];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= k; ++i)
		cin >> b[i];

	sort(b + 1, b + k + 1);

	for (int i = 1; i <= n; ++i)
		if (a[i] == 0)
			a[i] = b[k--];

	bool ok = false;
	for (int i = 2; i <= n; ++i)
		if (a[i] <= a[i - 1])
			ok = true;
	if (ok)
		puts("Yes");
	else
		puts("No");

	return 0;
}