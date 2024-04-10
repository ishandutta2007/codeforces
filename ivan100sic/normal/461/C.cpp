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
		pos += 1;
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

fenwick<int, 111111> drvo;
int n, q, l, r;
bool rev;

int drvosum(int x) {
	if (rev) {
		return drvo.sum(r) - drvo.sum(r - x);
	} else {
		return drvo.sum(l + x) - drvo.sum(l);
	}
}

void drvoadd(int x, int y) {
	if (rev) {
		drvo.add(r-x-1, y);
	} else {
		drvo.add(l + x, y);
	}
}

void reduce(int f) {
	if (rev) {
		r -= f;
	} else {
		l += f;
	}
}

void drvorev() {
	rev = !rev;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<=n; i++)
		drvoadd(i, 1);
	l = 0, r = n;

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int p;
			cin >> p;
			if (2*p > r-l) {
				drvorev();
				p = (r-l) - p;
			}

			for (int i=1; i<=p; i++) {
				int t = drvosum(i) - drvosum(i-1);
				drvoadd(i-1, -t);
				drvoadd(2*p-i, t);
			}
			reduce(p);
		} else {
			int x, y;
			cin >> x >> y;
			cout << drvosum(y) - drvosum(x) << '\n';
		}
	}
}