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

int n, h;

int main()
{
	cin >> n >> h;

	r32 top = 0.0, sum = 0.0;
	for (int i = 1; i < n; ++i)
	{
		r32 d = -top + sqrt(top * top + 1.0 / n);
		top += d, sum += d * h;
		printf("%.16f ", sum);
	}

	return 0;
}