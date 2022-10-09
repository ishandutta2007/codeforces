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

fenwick<int, 100005> drvo[26];
string s;
int q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> q;
	int n = s.size();
	s = string(" ") + s;
	for (int i=1; i<=n; i++)
		drvo[s[i] - 'a'].add(i, 1);

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			char c;
			cin >> i >> c;
			drvo[s[i] - 'a'].add(i, -1);
			s[i] = c;
			drvo[s[i] - 'a'].add(i, +1);
		} else {
			int l, r;
			cin >> l >> r;
			int c = 0;
			for (int i=0; i<26; i++) {
				c += drvo[i].sum(r) != drvo[i].sum(l-1);
			}
			cout << c << '\n';
		}
	}
}