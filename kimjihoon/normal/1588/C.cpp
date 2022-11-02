#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long s[300009];
int rn, c[300009], ft[300009][2], ep[300009][20], pr[300009];
vector<pair<long long, int> > v;

void up(int i, int w, int t)
{
	while (i <= rn) {
		ft[i][t] = min(ft[i][t], w);
		i += (i & (-i));
	}
}

int qry(int i, int t) 
{
	int s = rn + 10;
	while (i) {
		s = min(s, ft[i][t]);
		i -= (i & (-i));
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		rn = n + 4;
		v.clear();
		v.push_back(make_pair(0, 0));
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (i & 1) a *= -1;
			s[i] = s[i - 1] + 1LL * a;
			v.push_back(make_pair(s[i], i));
		}
		sort(v.begin(), v.end());
		int cc = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!i || v[i].first != v[i - 1].first)
				cc++;
			c[v[i].second] = cc;
		}
		for (int i = 0; i <= rn; i++) {
			ft[i][0] = ft[i][1] = rn + 10;
			pr[i] = n + 1;
			for (int j = 0; j <= 19; j++)
				ep[i][j] = n + 1;
		}
		pr[c[n]] = n;
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (i + 2 <= n) {
				if (i & 1)
					up(rn - c[i + 2], i + 2, 1);
				else
					up(c[i + 2], i + 2, 0);
			}
			int rp = min(qry(c[i] - 1, 0), qry(rn - (c[i] + 1), 1));
			rp = min(rp - 1, n);
			ep[i][0] = pr[c[i]];
			for (int l = 0; l < 19; l++)
				ep[i][l + 1] = ep[ep[i][l]][l];
			int pp = i, sr = 0;
			for (int l = 19; l >= 0; l--)
				if (ep[pp][l] <= rp) {
					pp = ep[pp][l];
					ans += (1 << l);
				}
			pr[c[i]] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}