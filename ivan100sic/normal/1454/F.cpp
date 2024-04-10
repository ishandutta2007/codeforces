// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct sparse_table {
	vector<vector<T>> d;
	T e;
	F f;

	sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
		d.push_back(a);
		int n = a.size();
		for (int h=1; h*2<=n; h<<=1) {
			int m = a.size() - h;
			vector<T> b(m);
			for (int i=0; i<m; i++)
				b[i] = f(a[i], a[i+h]);
			d.push_back(b);
			swap(a, b);
		}
	}

	T operator() (int l, int r) const {
		if (l >= r) return e;
		int i = 31 - __builtin_clz(r-l);
		return f(d[i][l], d[i][r-(1<<i)]);
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, f=0;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		sparse_table ht(a, 0, [](int x, int y) { return max(x, y); });
		sparse_table lt(a, int(1e9), [](int x, int y) { return min(x, y); });

		for (int x=1; x<=n-2; x++) {
			int l = 1, r = n-x-1, o = -1;

			int p1 = ht(0, x);

			while (l <= r) {
				int m = (l+r) / 2;

				int p2 = lt(x, x+m);
				int p3 = ht(x+m, n);

				if (p1 == p2 && p2 == p3) {
					o = m;
					break;
				}

				if (p2 > p1 || (p2 == p1 && p3 > p1)) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}

			if (o != -1 && lt(x, x+o) == ht(0, x)) {
				cout << "YES\n" << x << ' ' << o << ' ' << n-x-o << '\n';
				f = 1;
				break;
			}
		}

		if (!f) {
			cout << "NO\n";
		}
	}
}