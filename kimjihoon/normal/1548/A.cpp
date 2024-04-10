#include <iostream>
#include <algorithm>
using namespace std;

int c[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	int ans = n;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		if (!c[a]) ans--;
		c[a]++;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 3) 
			cout << ans << '\n';
		else {	
			int a, b; cin >> a >> b;
			if (a > b) swap(a, b);
			if (t == 1) {
				if (!c[a]) ans--;
				c[a]++;
			}
			else {
				if (c[a] == 1) ans++;
				c[a]--;
			}
		}
	}
	return 0;
}