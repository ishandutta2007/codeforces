#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, long long> hv;
int x[2005], y[2005];
long long ans;
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> x[i] >> y[i];
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) if (x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]))
		hv[make_pair(x[i]-x[j], y[i]-y[j])]++;
	for (auto u: hv)
		ans += (u.second-1)*u.second/2;
	cout << ans/2 << endl;
	return 0;
}