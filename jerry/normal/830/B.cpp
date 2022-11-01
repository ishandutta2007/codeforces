#include <bits/stdc++.h>
using namespace std;

multiset<int> tr[262144];
int n, a[100005];
long long ans;
int loc;

bool gl(int lo, int val)
{
	int at = 131072+lo;
	while (at)
	{
		if (tr[at].find(val) != tr[at].end())
		{
			if (at >= 131072) break;
			at *= 2;
			continue;
		}
		ans += tr[at].size();
		if (__builtin_popcount(++at) == 1) return false;
		if (~at&1) at /= 2;
	}
	for (loc = at-131072;at;at/=2) tr[at].erase(tr[at].find(val));
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", a+i);
		for (int j = 131072+i;j;j/=2) tr[j].insert(a[i]);
	}
	for (int Z = 0;Z < n;Z++)
	{
		int v = *tr[1].begin();
		if (gl(loc, v)) continue;
		gl(0, v);
	}
	ans += n;
	cout << ans << endl;
	return 0;
}