#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n, k;

inline bool query(int a, int b)
{
	if (!~a || !~b)
		return false;
	string ret;
	cout << 1 << ' ' << a << ' ' << b << endl;
	cin >> ret;
	return ret == "TAK";
}

inline int get(int l, int r)
{
	if (l > r)
		return -1;

	while (l < r)
	{
		int mid = l + r >> 1;
		if (query(mid, mid + 1))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int main()
{
	cin >> n >> k;

	int a = get(1, n);
	int b = get(1, a - 1);
	if (!query(b, a))
		b = get(a + 1, n);

	cout << 2 << ' ';
	cout << a << ' ' << b << endl;

	return 0;
}