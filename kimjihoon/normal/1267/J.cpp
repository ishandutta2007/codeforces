#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c[2000009], pc[2000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) { c[i] = 0; pc[i] = 0; }
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			c[a]++;
		}
		int tn = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= c[i] + 1; j++)
				if (j == 1 || c[i] / (j - 1) >= c[i] % (j - 1))
					pc[j]++;
			if (c[i] > 0) tn++;
		}
		int ms = 1;
		for (int i = 2; i <= n; i++)
			if (pc[i] == tn)
				ms = i;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			while (c[i] > 0) {
				if (c[i] >= ms && (ms == 1 || (c[i] - ms) / (ms - 1) >= (c[i] - ms) % (ms - 1))) c[i] -= ms;
				else c[i] -= ms - 1;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}