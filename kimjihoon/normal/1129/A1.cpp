#include <iostream>
#include <algorithm>
using namespace std;

int c[5009], p[5009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;	
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		c[a]++;
		int t;
		if (a < b) t = b - a;
		else t = n - a + b;
		if (p[a] == 0) p[a] = t;
		else p[a] = min(p[a], t);
	}
	for (int i = 1; i <= n; i++) 
		if (c[i] > 0)
			p[i] += (c[i] - 1) * n;
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (c[j] == 0) continue;
			if (i <= j) ans = max(ans, p[j] + j - i);
			else ans = max(ans, p[j] + n - i + j);
		}
		cout << ans << " ";
	}
	cout << '\n';
	return 0;
}