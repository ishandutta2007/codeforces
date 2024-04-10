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
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		if (i & 1)
			cout << "I hate ";
		else
			cout << "I love ";
		if (i == n)
			cout << "it";
		else
			cout << "that ";
	}

	return 0;
}