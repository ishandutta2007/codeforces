#include<bits/stdc++.h>
using namespace std;
bitset<3005>bit[3005];
bitset<3005>x[3005];
bitset<3005>h[3005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'z')bit[i][j] = 1;
			else bit[i][j] = 0;
		}
	}
	for (int i = 0; i < 3005; i++)h[i].set(), x[i].set();
	long long ans = 0;
	for (int i = 0; i <= m; i++) {

		for (int j  = 0; j < n; j++) {
			h[j] = h[j] & (bit[j] >> i);
			if (j - i >= 0)
				x[j] = x[j] & (bit[j - i] >> i);
		}
		for (int j = 0; j < n; j++) {
			if (j - i >= 0)
				ans += (x[j] & h[j] & h[j - i]).count();
		}
	}
	cout << ans << endl;
	return 0;
}