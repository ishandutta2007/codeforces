#include <bits/stdc++.h>
using namespace std;

int n, ptr; long long a, cf, cm, m;
pair<long long, int> x[100005]; long long cu[100005];
long long tot[100005];

long long foo(int up)
{
	long long rem = (up+1)*a;
	if (up != -1) rem -= cu[up];
	rem = m - rem;
	if (rem < 0) return -1;
	long long ret = (up+1)*cf;
	while (ptr <= up) ptr++;
	while (tot[ptr] > rem) ptr++;
	if (up < n-1)
	{
		long long tmp;
		for (;ptr > up;ptr--)
		{
			if (tot[ptr] > rem)
				break;
			tmp = rem - tot[ptr];
		}
		ret += min((long long)a, (x[ptr+1].first+tmp/(n-ptr-1)))*cm;
	} else ret += a*cm;
	return ret;
}

long long fix(int up)
{
	long long rem = m - ((up+1)*a - cu[up]);
	if (rem < 0) return -1;
	long long ret = (up+1)*cf;
	if (up < n-1)
	{
		int i = n-1;
		long long tmp;
		for (;i > up;i--)
		{
			if (tot[i] > rem)
				break;
			tmp = rem - tot[i];
		}
		long long finval = min((long long)a, (x[i+1].first+tmp/(n-i-1)));
		for (i++;i < n;i++)
			x[i].first = finval;
		ret += finval*cm;
	} else ret += a*cm;
	for (int i = 0;i <= up;i++) x[i].first = a;
	return ret;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> cf >> cm >> m; ptr = n-1;
	for (int i = 0;i < n;i++)
		cin >> x[i].first, x[i].second = i;
	sort(x, x+n, greater<pair<long long, int> >());
	cu[0] = x[0].first;
	for (int i = 1;i < n;i++)
		cu[i] = cu[i-1] + x[i].first;

	for (int i = 0;i < n;i++)
	{
		tot[i] = cu[n-1];
		if (i) tot[i] -= cu[i-1];
		tot[i] = (n-i)*x[i].first - tot[i];
	}

	long long best = foo(-1); int lo = -1;
	for (int i = 0;i < n;i++)
	{
		long long alt = foo(i);
		if (alt > best)
		{
			best = alt;
			lo = i;
		}
	}

	cout << fix(lo) << "\n";
	sort(x, x+n, [](pair<long long, int> a, pair<long long, int> b)->bool {
			return (a.second < b.second);
			});
	for (int i = 0;i < n;i++)
		cout << x[i].first << " ";
	cout << endl;

	return 0;
}