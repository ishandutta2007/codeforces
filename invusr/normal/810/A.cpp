#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int n, k, sum = 0;

int main()
{
	n = getint(), k = getint();
	for (int i = 0; i < n; ++i)
		sum += getint();

	for (int i = 0; ; ++i)
	{
		int u = sum + i * k << 1;
		int v = (2 * k - 1) * (i + n);
		if (u >= v)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}