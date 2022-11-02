#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int w[100009], dg[100009];
pair<int, int> p[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
			dg[i] = 0;
			ans += w[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b;
			dg[a]++; dg[b]++;
		}
		for (int i = 1; i <= n; i++) {
			p[i] = make_pair(w[i], dg[i]);
		}
		sort(p + 1, p + n + 1); reverse(p + 1, p + n + 1);
		int pi = 1;
		for (int i = 1; i < n; i++) {
			cout << ans << " ";
			while (pi < n && p[pi].second <= 1) 
				pi++;
			ans += p[pi].first; p[pi].second--;
		}
		cout << '\n';
	}
	return 0;
}