#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], s[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == k) c++;
		}
		if (c == 0) {
			cout << "no" << '\n';
			continue;
		}
		if (n == 1) {
			cout << "yes" << '\n';
			continue;	
		}
		int mn = 1000000000;
		bool f = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= k) s[i] = s[i - 1] + 1;
			else s[i] = s[i - 1] - 1;
			if (s[i] - mn > 0 && i > 1) {
				f = true;
				break;
			}
			mn = min(mn, s[i - 1]);
		}
		if (f) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}