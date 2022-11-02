#include <iostream>
#include <algorithm>
using namespace std;

int n, ans[100009];
bool vs[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long k; cin >> n >> k; k--;
		ans[0] = 0;
		for (int i = 0; i <= n; i++)
			vs[i] = false;
		int mx = 0;
		for (int i = 1; i <= n - 63; i++) {
			ans[i] = i; 
			mx = i; vs[i] = true;
		}
		for (int i = max(1, n - 62); i <= n; i++) {
			long long ws = 0;
			int ap = 0;
			for (int j = mx + 1; j <= n; j++) {
				int p = max(n - j - 1, 0);
				long long w = (1LL << p);
				if (ws + w > k) {
					ap = j;
					break;
				}
				ws += w;
			}
			if (ap == 0) {
				k = 1;
				break;
			}
			mx = ap; k -= ws;
			while (true) {
				ans[i] = ap; vs[ap] = true;
				ap--;
				if (ap < 1 || vs[ap]) break;
				i++;
			}
		}
		if (k != 0) cout << -1 << '\n';
		else {
			for (int i = 1; i <= n; i++)
				cout << ans[i] << " ";
			cout << '\n';
		}
	}
	return 0;
}