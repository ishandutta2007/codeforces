#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	string st;
	cin >> st;
	vector<vector<ll>> cnt(n + 1, vector<ll>(n));
	for (int len = 1; len <= n; len++) {
		for (int i = 0; i < n; i++) {
			int ind = i - 1;
			for (; ind >= 0; ind--) {
				if (st[ind] == st[i]) break;
			}
			if (len == 1) {
				if (ind == -1) cnt[len][i] = 1;
			}
			else {
				for (int j = 0; j < i; j++) {
					cnt[len][i] += cnt[len - 1][j];
					if (st[j] == st[i]) cnt[len][i] -= cnt[len][j];
				}
			}
			//cout << len << " " << i << " " << cnt[len][i] << endl;
		}
	}
	ll ans = 0;
	for (int len = n; len > 0; len--) {
		for (int i = 0; i < n; i++) {
			if (cnt[len][i] >= m) {
				ans += m * (n - len);
				m = 0;
				break;
			}
			else {
				ans += cnt[len][i] * (n - len);
				m -= cnt[len][i];
			}
		}
		if (!m) break;
	}
	if (m == 1) {
		ans += n;
		m--;
	}
	if (m) cout << -1 << endl;
	else cout << ans << endl;
	//system("pause");
	return 0;
}