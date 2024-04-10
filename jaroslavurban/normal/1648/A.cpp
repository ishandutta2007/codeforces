#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MX = 100100;

void ProGamerMove() {
	int n, m;
	cin >> n >> m;
	vector<ll> res(MX), price(MX), cnt(MX), lst(MX);
	vector<vector<int>> t(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> t[i][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int c = t[i][j];
			if (lst[c] != i) {
				price[c] += (i - lst[c]) * cnt[c];
				lst[c] = i;
			}
			res[c] += price[c];
			++cnt[c];
		}
	}
	price.assign(MX, 0);
	cnt.assign(MX, 0);
	lst.assign(MX, 0);
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			int c = t[i][j];
			if (lst[c] != j) {
				price[c] += (j - lst[c]) * cnt[c];
				lst[c] = j;
			}
			res[c] += price[c];
			++cnt[c];
		}
	}
	cout << accumulate(res.begin(), res.end(), 0ll) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	//cin >> tc;
	while (tc--) ProGamerMove();
}