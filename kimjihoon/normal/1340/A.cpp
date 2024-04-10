#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], r[100009];
bool vs[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			r[a[i]] = i;
			vs[i] = false;
		}
		bool f = true;
		for (int i = 1; i <= n; i++) {
			if (vs[i]) continue;
			int j = r[i];
			while (j <= n) {
				if (vs[j]) break;
				if (r[i] < j && a[j] != a[j - 1] + 1) {
					f = false;
					break;
				}
				vs[j] = true;
				j++;
			}
			if (!f) break;
		}
		if (f) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}