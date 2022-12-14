#include <bits/stdc++.h>
using namespace std;

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

int main()
{
	int n, k = 1, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (~x & 1)
			k = !k;
		cout << k + 1 << endl;
	}

	return 0;
}