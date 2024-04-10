#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; long long s; cin >> n >> s;
		long long sp = 0, mx = 0;
		int mi = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			sp += a;
			if (mx < a) {
				mx = a; mi = i;
			}
			if (sp - mx > s) continue;
			ans = mi;
		}
		if (sp <= s) cout << 0 << '\n';
		else cout << ans + 1 << '\n';
	}
	return 0;
}