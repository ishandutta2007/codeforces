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

int n, m, k;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];
	sparse_table t(a, vector<int>(m), [](vector<int> a, vector<int> b) {
		for (int i=0; i<(int)a.size(); i++)
			a[i] = max(a[i], b[i]);
		return a;
	});

	int l = 1, r = n;
	vector<int> sol(m);
	while (l <= r) {
		int mid = (l+r) / 2;
		bool found = false;
		for (int i=0; i+mid<=n; i++) {
			auto g = t(i, i+mid);
			if (accumulate(begin(g), end(g), 0) <= k) {
				l = mid + 1;
				sol = g;
				found = true;
				break;
			}
		}
		if (!found)
			r = mid - 1;
	}
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}