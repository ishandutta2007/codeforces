#include <iostream>
using namespace std;

int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int mx = -1000000009, mi = -1, mc = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0 && mx < a[i]) {
			mx = a[i]; mi = i;
		}
		if (a[i] < 0)
			mc++;
	}
	int ri = -1;
	if (mc % 2 == 1)
		ri = mi;
	int ti = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0 || (i != ri && a[i] < 0)) {
			ti = i;
			break;
		}
	}
	int tz = -1, tc = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0 || i == ri) {
			if (tz == -1) tz = i;
			else {
				cout << 1 << " " << tz << " " << i << '\n';
				tz = i; tc++;
			}
			continue;
		}
		if (i == ti) continue;
		cout << 1 << " " << i << " " << ti << '\n';
		tc++;
	}
	if (tc < n - 1)
		cout << 2 << " " << tz << '\n';
	return 0;
}