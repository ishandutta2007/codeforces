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

const int MaxN = 100005;

int n, f;
int k[MaxN], l[MaxN];

int idx[MaxN];

inline bool comparator(int i, int j)
{
	int u = min(l[i], k[i] << 1) - min(l[i], k[i]);
	int v = min(l[j], k[j] << 1) - min(l[j], k[j]);
	return u > v;
}

int main()
{
	cin >> n >> f;
	for (int i = 1; i <= n; ++i)
		k[i] = getint(), l[i] = getint(), idx[i] = i;

	sort(idx + 1, idx + n + 1, comparator);

	long long res = 0;
	for (int i = 1; i <= f; ++i)
		res += min(l[idx[i]], k[idx[i]] << 1);
	for (int i = f + 1; i <= n; ++i)
		res += min(l[idx[i]], k[idx[i]]);

	cout << res << endl;

	return 0;
}