#include <iostream>
#include <algorithm>
using namespace std;

int ca[209], cb[209], r[209];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i <= 200; i++) {
			ca[i] = cb[i] = r[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			a += 100;
			ca[a]++;
		}
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			a += 100;
			cb[a]++;
		}
		bool f = true;
		for (int i = 0; i <= 200; i++) {
			if (r[i] + ca[i] < cb[i] || r[i] > cb[i]) {
				f = false;
				break;
			}
			r[i + 1] += r[i] + ca[i] - cb[i];
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}