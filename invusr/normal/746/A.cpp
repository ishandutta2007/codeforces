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

int a, b, c;

int main()
{
	cin >> a >> b >> c;

	b /= 2, c /= 4;
	a = b = c = min(a, min(b, c));
	cout << a + b * 2 + c * 4;

	return 0;
}