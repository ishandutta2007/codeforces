#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m, q;
string s[100005];

struct tree {
	int c[100005], p[100005], o[100005];

	void init() {
		for (int i=1; i<=n; i++) {
			c[i] = 1;
			p[i] = i;
			o[i] = 0;
		}
	}

	int endp(int x) {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	bool check_same(int a, int b) {
		return endp(a) == endp(b);
	}

	bool check_opposite(int a, int b) {
		a = endp(a);
		b = endp(b);
		return o[a] == b;
	}

	bool join_same(int a, int b) {
		a = endp(a);
		b = endp(b);

		if (a == b) {
			// ok, nothing happens
			return true;
		}

		if (o[a] == b) {
			return false;
		}

		if (c[a] < c[b]) {
			swap(a, b);
		}

		// ako imaju razlicite opposite moras i te opozite da spojis
		if (o[a] != o[b] && o[a] && o[b]) {
			int x = o[a];
			int y = o[b];

			if (c[x] < c[y]) {
				swap(x, y);
			}
			c[x] += c[y];
			p[y] = x;
			
			o[y] = 0;
			o[x] = a;

			c[a] += c[b];
			p[b] = a;
			o[b] = 0;
			o[a] = x;
		} else if (o[a]) {
			c[a] += c[b];
			p[b] = a;
		} else if (o[b]) {
			o[a] = o[b];
			o[o[a]] = a;
			o[b] = 0;
			c[a] += c[b];
			p[b] = a;
		} else {
			c[a] += c[b];
			p[b] = a;
		}

		return true;
	}

	bool join_opposite(int a, int b) {
		a = endp(a);
		b = endp(b);

		if (a == b) {
			// ovi su ustvari isti, sto ne valja
			return false;
		}

		if (o[a] == b) {
			// vec su opposite
			return true;
		}

		if (o[a] && o[b] && o[a] != o[b]) {
			int x = o[a];
			int y = o[b];

			// spoji by, ax

			if (c[b] < c[x]) {
				swap(b, x);
			}
			c[b] += c[x];
			p[x] = b;

			//

			if (c[a] < c[y]) {
				swap(a, y);
			}
			c[a] += c[y];
			p[y] = a;

			o[a] = b;
			o[b] = a;
			o[x] = 0;
			o[y] = 0;
		} else if (o[a]) {
			int x = o[a];

			if (c[b] < c[x]) {
				swap(b, x);
			}
			c[b] += c[x];
			p[x] = b;

			o[a] = b;
			o[b] = a;
			o[x] = 0;
		} else if (o[b]) {
			int y = o[b];

			if (c[a] < c[y]) {
				swap(a, y);
			}
			c[a] += c[y];
			p[y] = a;

			o[a] = b;
			o[b] = a;
			o[y] = 0;
		} else {
			o[a] = b;
			o[b] = a;
		}

		return true;
	}


};

tree drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	drvo.init();

	sort(s, s+n);

	for (int i=1; i<=m; i++) {
		int t;
		string a, b;
		int p, q;

		cin >> t >> a >> b;
		p = lower_bound(s, s+n, a) - s + 1;
		q = lower_bound(s, s+n, b) - s + 1;

		if (t == 1) {
			bool r = drvo.join_same(p, q);
			cout << (r ? "YES\n" : "NO\n");
		} else {
			bool r = drvo.join_opposite(p, q);
			cout << (r ? "YES\n" : "NO\n");
		}
	}

	for (int i=1; i<=q; i++) {
		string a, b;
		int p, q;

		cin >> a >> b;
		p = lower_bound(s, s+n, a) - s + 1;
		q = lower_bound(s, s+n, b) - s + 1;

		bool rs = drvo.check_same(p, q);
		bool ro = drvo.check_opposite(p, q);

		if (!rs && !ro) {
			cout << "3\n";
		} else if (rs) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}