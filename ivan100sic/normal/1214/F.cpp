#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<int> a, b;
vector<pair<int, int>> c, ku;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> n;
	if (m == 1) {
		cout << "0\n";
		for (int i=1; i<=n; i++)
			cout << i << " \n"[i == n];
		return 0;
	}
	a.resize(n);
	b.resize(n);
	for (int& x : a)
		cin >> x;
	for (int& y : b)
		cin >> y;
	c.resize(2*n);
	for (int i=0; i<n; i++)
		c[i] = {a[i], i};
	for (int i=0; i<n; i++)
		c[i+n] = {b[i], i+n};
	sort(c.begin(), c.end());
	ku = c;
	for (int i=0; i<2*n; i++)
		ku[i].second = ku[i].second < n ? 1 : -1;
	for (int i=1; i<2*n; i++)
		ku[i].second += ku[i-1].second;
	ku.insert(ku.begin(), {1, 0});
	ku.emplace_back(m+1, 0);
	// wt median
	int l = -1e8, r = 1e8, o = -123123123;
	while (l <= r) {
		int mid = (l+r) / 2;
		int br = 0;
		for (int i=0; i<=2*n; i++) {
			if (ku[i].second >= mid) {
				br += ku[i+1].first - ku[i].first;
			}
		}
		if (br >= (m +1)/2) {
			o = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cerr << "median = " << o << '\n';
	// spari abs(o) preko granice
	vector<int> p(n);
	vector<int> q(abs(o));
	vector<bool> used(2*n);
	if (o > 0) {
		for (int i=0, j=abs(o); i<2*n && j>0; i++) {
			if (c[i].second < n) {
				q[--j] = c[i].second;
				used[c[i].second] = true;
			}
		}
		for (int i=2*n-1, j=abs(o); i>=0 && j>0; i--) {
			if (c[i].second >= n) {
				p[q[--j]] = c[i].second - n;
				used[c[i].second] = true;
			}
		}
	} else if (o < 0) {
		for (int i=2*n-1, j=abs(o); i>=0 && j>0; i--) {
			if (c[i].second < n) {
				q[--j] = c[i].second;
				used[c[i].second] = true;
			}
		}
		for (int i=0, j=abs(o); i<2*n && j>0; i++) {
			if (c[i].second >= n) {
				p[q[--j]] = c[i].second - n;
				used[c[i].second] = true;
			}
		}
	}
		
	// for (int i=0; i<2*n; i++)
	// 	cerr << used[i];
	// cerr << '\n';
	vector<int> s;
	for (int i=0; i<2*n; i++) {
		if (!used[c[i].second]) {
			if (s.empty() || ((s.back() < n) == (c[i].second < n))) {
				// cerr << "guram " << c[i].second << '\n';
				s.push_back(c[i].second);
			} else {
				// cerr << "spajam " << c[i].second << ' ' << s.back() << '\n';
				p[min(c[i].second, s.back())] = max(c[i].second, s.back()) - n;
				s.pop_back();
			}
		}
	}
	ll z = 0;
	for (int i=0; i<n; i++) {
		ll d = abs(a[i] - b[p[i]]);
		z += min(d, m-d);
	}
	cout << z << '\n';
	for (int x : p)
		cout << x+1 << ' ';
	cout << '\n';

}