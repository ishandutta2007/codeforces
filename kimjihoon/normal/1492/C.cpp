#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l[200009], r[200009];

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int pi = 0;
	for (int i = 0; i < n && pi < m; i++) {
		if (a[i] == b[pi]) {
			l[pi] = i;
			pi++;
		}
	}
	pi = m - 1;
	for (int i = n - 1; i >= 0 && pi >= 0; i--) {
		if (a[i] == b[pi]) {
			r[pi] = i;
			pi--;
		}
	}
	int ans = 0;
	for (int i = 0; i < m - 1; i++)
		ans = max(ans, r[i + 1] - r[i]);
	for (int i = 0; i < m - 1; i++) {
		ans = max(ans, r[i + 1] - l[i]);
		if (i > 0) ans = max(ans, l[i] - l[i - 1]);
	}
	for (int i = 0; i < m - 1; i++)
		ans = max(ans, l[i + 1] - l[i]);
	cout << ans << '\n';
	return 0;
}