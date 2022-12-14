#include <bits/stdc++.h>
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

const int MaxN = 100000;

int n;
int a[MaxN + 1];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[getint()] ^= 1;

	for (int i = 1; i <= MaxN; ++i)
		if (a[i] & 1)
		{
			puts("Conan");
			return 0;
		}

	puts("Agasa");

	return 0;
}