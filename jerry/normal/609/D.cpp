#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s, a[200005], b[200005], c[200005];
int n, k, m, t[200005];

int main()
{
	scanf("%d%d%d%lld", &n, &m, &k, &s);
	for (int i = 0;i < n;i++) scanf("%lld", a+i);
	for (int i = 0;i < n;i++) scanf("%lld", b+i);
	for (int i = 0;i < m;i++) scanf("%d%lld", t+i, c+i), t[i]--;
	int lo = 0, hi = n+1;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) >> 1;
		int A = 0, B = 0;
		for (int i = 1;i < mid;i++)
		{
			if (a[i] < a[A]) A = i;
			if (b[i] < b[B]) B = i;
		}
		vector<ll> ord;
		for (int i = 0;i < m;i++)
			if (t[i] == 0) ord.push_back(c[i]*a[A]);
			else ord.push_back(c[i]*b[B]);
		sort(ord.begin(), ord.end());
		long long req = 0;
		for (int i = 0;i < k;i++) req += ord[i];
		if (req <= s) hi = mid;
		else lo = mid;
	}
	if (hi == n+1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", hi);
	int A = 0, B = 0;
	for (int i = 1;i < hi;i++)
	{
		if (a[i] < a[A]) A = i;
		if (b[i] < b[B]) B = i;
	}
	vector<pair<ll, int> > ord;
	for (int i = 0;i < m;i++)
		if (t[i] == 0) ord.emplace_back(c[i]*a[A], i);
		else ord.emplace_back(c[i]*b[B], i);
	sort(ord.begin(), ord.end());
	for (int i = 0;i < k;i++) printf("%d %d\n", ord[i].second+1, 1+(t[ord[i].second]?B:A));
	return 0;
}