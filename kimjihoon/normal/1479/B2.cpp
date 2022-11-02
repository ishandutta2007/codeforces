#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009], d[100009], mx[100009], rmx;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int rn = 0;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx[i] = -1000000000;
		if (v.empty() || v.back() != a[i]) {
			v.push_back(a[i]);
			rn++;
		}
	}
	rmx = -1000000000;
	int ans = 0;
	for (int i = 1; i <= rn; i++) {
		d[i] = max(0, max(mx[v[i]] + 1, rmx));
		if (i > 1) {
			mx[v[i - 1]] = max(mx[v[i - 1]], d[i]);
			rmx = max(rmx, d[i]);
		}
		ans = max(ans, d[i]);
	}
	cout << rn - ans << '\n';
	return 0;
}