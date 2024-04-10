#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int a[109], b[109];
set<vector<int> > st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i]; a[i] = a[i] % (1 << 15);
		b[i] = (b[i] >> 15);
	}
	for (int i = 0; i < (1 << 15); i++) {
		int mn = 1000000000;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int t = (a[j] ^ i);
			int c = 0;
			while (t) {
				c += t % 2; t /= 2;
			}
			v.push_back(c);
			mn = min(mn, c);
		}
		if (mn)
			for (int j = 0; j < n; j++)
				v[j] -= mn;
		st.insert(v);
	}
	vector<int> v = vector<int>(n, 0);
	int ans = -1;
	for (int i = 0; i < (1 << 15); i++) {
		int mx = 0;
		for (int j = 0; j < n; j++) {
			int t = (b[j] ^ i);
			int c = 0;
			while (t) {
				c += t % 2; t /= 2;
			}
			v[j] = c;
			mx = max(mx, c);
		}
		for (int j = 0; j < n; j++)
			v[j] = mx - v[j];
		if (st.find(v) != st.end()) {
			ans = i * (1 << 15);
			break;
		}
	}
	if (ans == -1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> vt = vector<int>(n, 0);
	for (int i = 0; i < (1 << 15); i++) {
		int mn = 1000000000;
		for (int j = 0; j < n; j++) {
			int t = (a[j] ^ i);
			int c = 0;
			while (t) {
				c += t % 2; t /= 2;
			}
			vt[j] = c;
			mn = min(mn, c);
		}
		bool f = true;
		for (int j = 0; j < n; j++) {
			vt[j] -= mn;
			if (vt[j] != v[j]) {
				f = false;
				break;
			}
		}
		if (f) {
			ans += i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}