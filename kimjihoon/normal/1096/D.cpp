#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

vector<pair<int, ll> > v;
int rp[999];
ll a[100009], d[9][100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	rp['h'] = 1; rp['a'] = 2; rp['r'] = 3; rp['d'] = 4;
	for (int i = 0; i < n; i++) {
		if (rp[s[i]] == 0) continue;
		v.push_back(make_pair(rp[s[i]], a[i]));
	}
	n = v.size();
	ll ts = 0;
	for (int j = 0; j < n; j++) {
		if (v[j].first == 1) ts += v[j].second;
		d[1][j] = ts;
	}
	for (int i = 2; i <= 4; i++) {
		d[i][0] = 0;
		for (int j = 1; j < n; j++) {
			if (v[j].first != i) {
				d[i][j] = d[i][j - 1];
				continue;
			}
			d[i][j] = min(min(d[i][j - 1] + v[j].second, d[i - 1][j - 1] + v[j].second), d[i - 1][j]);
		}
	}
	if (n < 4) cout << 0 << '\n';
	else cout << d[4][n - 1] << '\n';
	return 0;
}