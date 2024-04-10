#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int R = 1003;
const long long md = 998244353;

int a[1009], d[1009][1009], id[1009];
long long p[1009];
bool vs[1009];
vector<int> v[1009];

void dp(int n)
{
	vs[n] = true;
	d[n][0] = a[n];
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (!vs[tn]) dp(tn);
		for (int j = 1; j <= R; j++)
			d[n][j] += d[tn][j - 1];
		p[n] = (p[n] + p[tn] + 1LL * d[tn][R]) % md;
	}
	for (int i = 0; i < R; i++) {
		if (d[n][i] > 1) {
			d[n][i + 1] += d[n][i] - 1;
			d[n][i] = 1;
		}
	}
	if (d[n][R] > 1) {
		p[n] = (p[n] + 1LL * (d[n][R] - 1)) % md;
		d[n][R] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			v[i].clear();
			id[i] = 0; p[i] = 0;
			vs[i] = false;
			for (int j = 0; j <= R; j++)
				d[i][j] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[b].push_back(a);
			id[a]++;
		}
		int rt = 0;
		for (int i = 1; i <= n; i++) {
			if (!id[i]) rt = i;
			if (!vs[i]) dp(i);
		}
		if (p[rt]) cout << (p[rt] + 1LL * R + 1LL) % md << '\n';
		else {
			int ans = 0;
			for (int i = R; i >= 0; i--) {
				if (d[rt][i]) {
					ans = i + 1;
					break;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}