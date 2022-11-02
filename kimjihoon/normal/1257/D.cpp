#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> p[200009];
int n, m, a[200009];

bool cp(int x, int y)
{
	return (*lower_bound(p, p + m + 1, make_pair(x, -1))).second >= y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> p[i].first >> p[i].second;
		sort(p, p + m); p[m] = make_pair(2000000000, 0);
		for (int i = m - 2; i >= 0; i--)
			p[i].second = max(p[i].second, p[i + 1].second);
		bool f = false;
		int s = 0, r = 0, ans = 1;
		for (int i = 0; i < n; i++) {
			r = max(r, a[i]); s++;
			if (!cp(r, s)) {
				if (f) {
					ans = -1; break;
				}
				r = s = 0; ans++; i--; f = true; 
				continue;
			}
			f = false;
		}
		cout << ans << '\n';
	}
	return 0;
}