#include <iostream>
#include <algorithm>
using namespace std;

int h[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> h[i];
		h[n] = -1000000009;
		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans = -1;
			for (int j = 0; j < n; j++)
				if (h[j] < h[j + 1]) {
					h[j]++; ans = j + 1;
					break;
				}
			if (ans == -1)
				break;
		}
		cout << ans << '\n';
	}
	return 0;
}