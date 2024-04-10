#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int p[200009], a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n; cin >> n;
		int ans = 1000000000;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (p[a[i]]) ans = min(ans, i - p[a[i]] + 1);
			p[a[i]] = i;
		}
		if (ans == 1000000000) cout << -1 << '\n';
		else cout << ans << '\n';
		for (int i = 1; i <= n; i++)
			p[a[i]] = 0;
	}
	return 0;
}