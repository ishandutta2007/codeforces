#include <bits/stdc++.h>
using namespace std;

pair<int, int> all[200005];
int l[200005];
int n, k;

long long calc(long long v)
{
	long long res = 0;
	for (int i = 0;i < k;i++)
		if (l[i] > v) return 1ll<<62;
		else if (2*l[i] < v) res += l[i];
		else res += 3ll*l[i]-v;
	return res;
}

bool can(long long test, long long tim)
{
	return calc(test) <= tim;
}

int solve(int t)
{
	long long lo = 0, hi = 1ll<<60;
	while (lo+1 < hi)
	{
		long long mid = (lo+hi) >> 1;
		if (can(mid, t)) hi = mid;
		else lo = mid;
	}
	int bst = -1;
	for (int i = 0;i < n;i++) if (all[i].second >= hi)
	{
		if (bst == -1) bst = i;
		if (all[i].first < all[bst].first) bst = i;
	}
	return bst!=-1?all[bst].first:-1;
}

int main()
{
	int s, t;
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 0;i < n;i++) scanf("%d%d", &all[i].first, &all[i].second);
	for (int i = 0;i < k;i++) scanf("%d", l+i);
	l[k] = s; k++;
	sort(l, l+k);
	for (int i = k-1;i > 0;i--) l[i] -= l[i-1];
	printf("%d\n", solve(t));
	return 0;
}