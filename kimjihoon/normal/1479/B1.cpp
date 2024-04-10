#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009];
vector<int> v, rv;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int c = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		c++;
		if (i == n - 1 || a[i] != a[i + 1]) {
			if (c == 1) {
				if (v.empty() || v.back() > 0) {
					v.push_back(-1);
					rv.push_back(i);
				}
				else v.back()--;
			}
			else {
				v.push_back(a[i]);
				rv.push_back(i);
			}
			c = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			ans -= v[i];
			if (v[i] == -1 || (-v[i]) % 2 == 0) continue;
			if (i + 1 == v.size() || a[rv[i] + 1] != v[i + 1]) continue;
			bool f = true;
			int t = a[rv[i] + 1];
			for (int j = 1; j < (-v[i]); j += 2)
				if (t != a[rv[i] + j]) {
					f = false;
					break;
				}
			if (f) v[i] = -1;
		}
		else {
			if (i < 2 || v[i - 1] > 0 || v[i - 2] != v[i] || v[i - 1] < -1) ans += 2;
			else ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}