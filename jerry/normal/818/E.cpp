#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], ok;
map<int, int> req, hv;
long long ans;

void add(int v, int b)
{
	for (auto u: req)
	{
		if (u.second <= hv[u.first]) ok--;
		for (;v%u.first == 0;v /= u.first) hv[u.first] += b;
		if (u.second <= hv[u.first]) ok++;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	if (k == 1) ans = 1ll*n*(n+1)/2;
	else
	{
		for (int i = 0;i < n;i++) scanf("%d", a+i);
		for (int i = 2;i < 32000;i++) for (;k%i == 0;k /= i) req[i]++;
		if (k > 1) req[k]++;
		for (auto u: req) hv[u.first] = 0;
		for (int l = 0, r = 0;l < n;l++)
		{
			while (ok < req.size() && r < n)
			{
				add(a[r], 1);
				r++;
			}
			if (ok == req.size()) ans += n-r+1;
			add(a[l], -1);
		}
	}
	cout << ans << endl;
	return 0;
}