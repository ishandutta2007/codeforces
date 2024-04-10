#include <iostream>
#include <algorithm>
using namespace std;

int p[200009], rp[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i <= 2 * n + 1; i++) {
			p[i] = rp[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			p[a]++;
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n + 1; i++) {
			if (p[i] || rp[i]) ans++;
			if (p[i] && p[i] + rp[i] > 1) rp[i + 1]++;
		}
		cout << ans << '\n';
	}
	return 0;
}