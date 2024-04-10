#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000;
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> a(n), h(n - 1);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; ++i) h[i] = abs(a[i + 1] - a[i]);
	//for (int i = 0; i < n - 1; ++i) cin >> h[i];
	vector<int> left(n - 1), right(n - 1);
	stack<int> res;
	for (int i = 0; i < n - 1; ++i) {
		while (!res.empty() && h[res.top()] < h[i]) {
			right[res.top()] = i;
			//cerr << res.top() << '\n';
			res.pop();
		}
		res.push(i);
	}
	while (!res.empty()) {
		right[res.top()] = n - 1;
		res.pop();
	}
	for (int i = n - 2; i >= 0; --i) {
		while (!res.empty() && h[res.top()] <= h[i]) {
			left[res.top()] = i;
			//cerr << res.top() << '\n';
			res.pop();
		}
		res.push(i);
	}
	while (!res.empty()) {
		left[res.top()] = - 1;
		res.pop();
	}
	/*int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		cerr << left[i] << ' ' << i << ' ' << right[i] << ' ' << (i -
		left[i]) * (right[i] - i) << '\n';
		//sum += (i - left[i]) * (right[i] - i);
	}
	//cout << sum << '\n';
	*/
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		--l;
		--r;
		--r;
		ll ans = 0;
		for (int j = l; j <= r; ++j) ans += (ll)h[j] * (min(right[j], r +
			1) - j) *
			(j - max(left[j], l - 1));
		cout << ans << '\n';
	}

	/*for (int i = 0; i < n - 1; ++i) cout << h[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n - 1; ++i) cout << right[i] << ' ';*/
}