#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> p[300009];
int al[300009][3], ar[300009][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n0, n1, n2; cin >> n0 >> n1 >> n2;
		for (int i = 1; i <= n0; i++) {
			cin >> p[i].first;
			p[i].second = 0;
		}
		for (int i = 1; i <= n1; i++) {
			cin >> p[n0 + i].first;
			p[n0 + i].second = 1;
		}
		for (int i = 1; i <= n2; i++) {
			cin >> p[n0 + n1 + i].first;
			p[n0 + n1 + i].second = 2;
		}
		int n = n0 + n1 + n2;
		sort(p + 1, p + n + 1);
		al[0][0] = al[0][1] = al[0][2] = ar[n + 1][0] = ar[n + 1][1] = ar[n + 1][2] = 0;
		for (int i = 1; i <= n; i++) {
			al[i][0] = al[i - 1][0]; al[i][1] = al[i - 1][1]; al[i][2] = al[i - 1][2];
			al[i][p[i].second] = p[i].first;
		}
		for (int i = n; i >= 1; i--) {
			ar[i][0] = ar[i + 1][0]; ar[i][1] = ar[i + 1][1]; ar[i][2] = ar[i + 1][2];
			ar[i][p[i].second] = p[i].first;
		}
		long long ans = 6LL * 1e18;
		for (int i = 1; i <= n; i++) {
			int t = p[i].second, a = (t + 1) % 3, b = (a + 1) % 3;
			for (int j = 0; j < 2; j++) {
				if (al[i][a] && ar[i][b]) {
					long long p1 = p[i].first - al[i][a], p2 = ar[i][b] - p[i].first;
					ans = min(ans, 2LL * (p1 * p1 + p1 * p2 + p2 * p2));
				}
				swap(a, b);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}