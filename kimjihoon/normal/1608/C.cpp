#include <iostream>
#include <algorithm>
using namespace std;

pair<pair<int, int>, int> p[100009];

int mx[100009];
bool f[100009], ans[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].first.first;
			p[i].second = i;
		}
		for (int i = 1; i <= n; i++)
			cin >> p[i].first.second;
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++)
			mx[i] = max(mx[i - 1], p[i].first.second);
		int mn = p[n].first.second, mi = n;
		f[n] = true;
		for (int i = n - 1; i >= 1; i--) {
			if (mx[i] < mn) f[i] = false;
			else f[i] = f[mi];
			if (p[i].first.second < mn) {
				mn = p[i].first.second;
				mi = i;
			}
		}
		for (int i = 1; i <= n; i++)
			ans[p[i].second] = f[i];
		for (int i = 1; i <= n; i++) {
			if (ans[i]) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
	return 0;
}