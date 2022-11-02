#include <iostream>
#include <vector>
using namespace std;

vector<int> v[300009];
long long d[300009][2], r[300009], md = 998244353;

void dp(int n, int p)
{
	d[n][0] = d[n][1] = 1;
	r[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		dp(tn, n);
		d[n][0] = (d[n][0] * ((d[tn][0] + d[tn][1]) * 2 - r[tn] + md)) % md;
		d[n][1] = (d[n][1] * (2 * d[tn][0] + d[tn][1] - r[tn] + md)) % md;
		r[n] = (r[n] * (d[tn][0] + d[tn][1] - r[tn] + md)) % md;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	dp(1, -1);
	long long ans = 0;
	cout << (d[1][0] + d[1][1] - r[1] - 1 + 2 * md) % md << '\n';
	return 0;
}