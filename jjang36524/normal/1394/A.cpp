#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
int N, a, b, c, d, L;
using namespace std;
vector<int>x, y;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> d >> a;
	int i;
	for (i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (t <= a)
			y.push_back(-t);
		t *= -1;
		x.push_back(t);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int cur = (N + d) / (d + 1);
	int ans = 0;
	int n = 0;
	for (i = 0; i < cur; i++)
	{
		n -= x[i];
	}
	for (i = max(cur-(x.size()-y.size()),0LL); i < y.size(); i++)
	{
		ans = max(ans, n);
		n -= y[i];
		if ((N-i+d) % (d + 1) == 0)
		{
			if(-x[(N - i + d) / (d + 1) - 1]>a)
				n += x[ (N - i+d) / (d + 1)-1];
		}
	}
	ans = max(ans, n);
	cout << ans;
}