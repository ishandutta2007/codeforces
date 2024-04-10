#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m, g, r;
int a[10009], d[10009][1009];
pair<int, int> p[10009][1009];
vector<pair<int, int> > v[20009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + m);
	cin >> g >> r;
	int md = (g + r + 1);
	v[0].push_back(make_pair(1, 0));
	p[1][0] = make_pair(0, 0);
	d[1][0] = 0;
	for (int i = 0; i <= (r + g) * m; i++) {
		int mi = (i % md);
		while (!v[mi].empty()) {
			int hn = v[mi].back().first, hk = v[mi].back().second;
			if (hn == -1) continue;
			if (hn == m) {
				cout << i - r << '\n';
				return 0;
			}
			for (int pm = -1; pm <= 1; pm += 2) {
				int ds = a[max(hn, hn + pm)] - a[min(hn, hn + pm)];
				int tn = hn + pm, tk = hk + ds;
				if (tn < 1 || tn > m || tk > g) continue;
				if (tk == g) tk = 0;
				int pds = d[hn][hk] + ds;
				if (hk == 0) pds += r;
				if (pds > (r + g) * m) continue;
				if ((tn != 1 || tk != 0) && d[tn][tk] == 0) {
					d[tn][tk] = pds;
					p[tn][tk] = make_pair(pds, v[pds].size());
					v[pds % md].push_back(make_pair(tn, tk));
				}
				else if (d[tn][tk] > pds) {
					v[p[tn][tk].first % md][p[tn][tk].second].first = -1;
					p[tn][tk] = make_pair(pds, v[pds].size());
					v[pds % md].push_back(make_pair(tn, tk));
				}
			}
			v[mi].pop_back();
		}
	}
	cout << -1 << '\n';
	return 0;
}