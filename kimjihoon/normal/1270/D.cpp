#include <iostream>
using namespace std;

int d[509];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	if (n == 1) {
		cout << "! " << 1 << endl;
		return 0;
	}
	cout << "? ";
	for (int i = 1; i <= k; i++)
		cout << i << " ";
	cout << endl;
	int pi, p; cin >> pi >> p;
	int t = 0;
	for (int i = 1; i <= k; i++) {
		if (i == pi) continue;
		cout << "? ";
		for (int j = 1; j <= k; j++) {
			if (i == j) cout << k + 1 << " ";
			else cout << j << " ";
		}
		cout << endl;
		int ai, a; cin >> ai >> a;
		if (ai == pi) d[i] = 1;
		else {
			d[i] = 2;
			if (p < a) t = 2;
			else t = 1;
		}
	}
	if (t == 0) {
		cout << "? ";
		for (int i = 1; i <= k; i++) {
			if (i < pi) cout << i << " ";
			else cout << i + 1 << " ";
		}
		cout << endl;
		int ai, a; cin >> ai >> a;
		if (a > p) cout << "! " << 1 << endl;
		else cout << "! " << k << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= k; i++)
		if (d[i] == t)
			ans++;
	cout << "! " << ans << endl;
	return 0;
}