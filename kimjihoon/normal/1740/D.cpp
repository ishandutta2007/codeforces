#include <iostream>
#include <algorithm>
using namespace std; 

bool vs[100009];
int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m, k; cin >> n >> m >> k;
		int c = 0, r = k;
		for (int i = 1; i <= k; i++) {
			vs[i] = false;
			cin >> a[i];
		}
		bool f = true;
		for (int i = 1; i <= k; i++) {
			if (r == a[i]) {
				r--;
				while (r >= 1 && vs[r]) {
					c--;
					r--;
				}
			}
			else {
				vs[a[i]] = true;
				c++;
				if (c >= n * m - 3) {
					f = false;
					break;
				}
			}
		}
		if (f) cout << "YA\n";
		else cout << "TIDAK\n";
	}
	return 0;
}