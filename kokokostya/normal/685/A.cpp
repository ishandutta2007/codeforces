#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k1 = 1, k2 = 1;
int ans = 0;

int main() {
	int n, m;
	cin >> n >> m;
	int res1 = 7, res2 = 7;
	while (res1 < n) { res1 *= 7; k1++; }
	while (res2 < m) { res2 *= 7; k2++; }
	if (k1 + k2 > 7) { cout << 0; return 0; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vector<char> used(7);
			bool is = 1;
			int now = i;
			for (int q = 0; q < k1; q++) {
				int x = now % 7;
				if (used[x]) { is = 0; }
				else { used[x] = 1; }
				now /= 7;
			}
			now = j;
			for (int q = 0; q < k2; q++) {
				int x = now % 7;
				if (used[x]) { is = 0; }
				else { used[x] = 1; }
				now /= 7;
			}
			if (is) { 
				ans++; }
		}
	}
	cout << ans;
	return 0;
}