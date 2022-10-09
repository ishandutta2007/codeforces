#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 100005> drvo[4][11][10];
map<char, int> mp = {{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};
int a[100005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	n = s.size();
	for (int i=0; i<n; i++) {
		a[i+1] = mp[s[i]];
		for (int r=1; r<=10; r++) {
			drvo[a[i+1]][r][(i+1)%r].add(i+1, 1);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			char c;
			cin >> x >> c;
			int ol = a[x], nu = mp[c];
			for (int r=1; r<=10; r++) {
				drvo[ol][r][x%r].add(x, -1);
				drvo[nu][r][x%r].add(x, +1);
			}
			a[x] = nu;
		} else {
			int l, r;
			cin >> l >> r;
			string e;
			cin >> e;
			int m = e.size();
			int ans = 0;
			for (int j=0; j<m; j++) {
				int k = mp[e[j]];
				int u = (j+l) % m;
				ans += drvo[k][m][u].sum(r) - drvo[k][m][u].sum(l-1);
			}
			cout << ans << '\n';
		}
	}
}