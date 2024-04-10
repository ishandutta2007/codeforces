#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[300009];
vector<vector<int> > v, tv;
vector<int> v0, v1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	v.push_back(vector<int>());
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.back().push_back(a[i]);
	}
	int x = 0;
	long long ans = 0;
	for (int i = 30; i >= 0; i--) {
		long long p0 = 0, p1 = 0;
		tv.clear();
		for (int j = 0; j < v.size(); j++) {
			int c0 = 0, c1 = 0;
			v0.clear(); v1.clear();
			for (int k = 0; k < v[j].size(); k++) {
				int t = (bool)((1 << i) & v[j][k]);
				if (t) {
					p0 += c0;
					c1++;
					v1.push_back(v[j][k]);
				}
				else {
					p1 += c1;
					c0++;
					v0.push_back(v[j][k]);
				}
			}
			if (!v0.empty()) tv.push_back(v0);
			if (!v1.empty()) tv.push_back(v1);
		}
		if (p0 < p1) x += (1 << i);
		ans += min(p0, p1);
		v = tv;
	}
	cout << ans << " " << x << '\n';
	return 0;
}