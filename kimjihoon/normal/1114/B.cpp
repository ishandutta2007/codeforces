#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> p[200009];
bool r[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p, p + n); reverse(p, p + n);
	long long ans = 0;
	for (int i = 0; i < m * k; i++) {
		r[p[i].second] = true;
		ans += p[i].first;
	}
	cout << ans << '\n';
	int c = 0, p = 0;
	for (int i = 0; i < n; i++) {
		if (r[i]) 
			c++;
		if (c == m) {
			if (p < k - 1)
				cout << i + 1 << " ";
			c = 0; p++;
		}
	}
	cout << '\n';
	return 0;
}