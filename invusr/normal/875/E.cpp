#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
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
const int INF = 0x3f3f3f3f;

int n;
int a[MaxN + 3];

inline int length(int i, int j)
{
	return abs(a[i] - a[j]);
}

set<int> all;

inline bool validate(const int &d)
{
	all.clear();
	if (length(1, 3) <= d)
		all.insert(a[1]);
	if (length(2, 3) <= d)
		all.insert(a[2]);

	if (all.empty())
		return false;

	for (int i = 4; i <= n; ++i)
	{
		while (!all.empty() && abs(a[i] - *all.begin()) > d)
			all.erase(all.begin());
		while (!all.empty() && abs(a[i] - *all.rbegin()) > d)
			all.erase(*all.rbegin());
		if (length(i, i - 1) <= d)
			all.insert(a[i - 1]);

		if (all.empty())
			return false;
	}

	return true;
}

int main()
{
	cin >> n, n += 2;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	int l = length(1, 2), r = INF;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (validate(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << l << endl;

	return 0;
}