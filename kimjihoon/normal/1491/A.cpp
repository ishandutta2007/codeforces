#include <iostream>
#include <algorithm>
using namespace std;

int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) c++;
	}
	for (int i = 0; i < q; i++) {
		int t, x; cin >> t >> x;
		if (t == 1) {
			if (a[x]) c--;
			else c++;
			a[x] = 1 - a[x];
		}
		else {
			if (x <= c) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	return 0;
}