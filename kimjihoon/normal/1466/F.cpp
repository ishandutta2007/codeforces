#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

long long md = 1000000007;
int ds[500009], sz[500009], rsz[500009];
bool vs[500009], avs[500009];
pair<int, int> p[500009];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ds[i] = i;
		sz[i] = 1; rsz[i] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		cin >> p[i].first;
		if (k == 1) p[i].second = p[i].first;
		else
			cin >> p[i].second;
		int a = p[i].first, b = p[i].second;
		a = uf(a); b = uf(b);
		if (rsz[a] == sz[a] && rsz[b] == sz[b]) continue;
		if (a == b && p[i].first != p[i].second) continue;
		ans++;
		avs[i] = true;
		if (a == b) rsz[a]++;
		else {
			ds[a] = b;
			sz[b] += sz[a]; rsz[b] += rsz[a];
			rsz[b]++;
		}
	}
	long long tans = 1;
	for (int i = 0; i < ans; i++)
		tans = (tans * 2) % md;
	cout << tans << " " << ans << '\n';
	for (int i = 1; i <= n; i++)
		if (avs[i])
			cout << i << " ";
	cout << '\n';
	return 0;
}