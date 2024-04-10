// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct elem {
	ll l, mid, r;
	bool prod;

	elem operator+ (const elem& b) const {
		elem res;
		res.prod = false;
		if (prod && b.prod) {
			res.l = mid;
			res.mid = 0;
			res.r = b.mid;
		} else if (prod) {
			res.l = mid;
			res.mid = b.l + b.mid;
			res.r = r;
		} else if (b.prod) {
			res.l = l;
			res.mid = mid + r;
			res.r = b.mid;
		} else {
			res.l = l;
			res.mid = mid + r + b.l + b.mid;
			res.r = b.r;
		}
		return res;
	}

	elem operator* (const elem& b) const {
		elem res;
		if (prod && b.prod) {
			res.prod = true;
			res.mid = mid * b.mid;
			res.l = res.r = 0;
		} else if (prod) {
			res.l = mid * b.l;
			res.mid = b.mid;
			res.r = b.r;
			res.prod = false;
		} else if (b.prod) {
			res.l = l;
			res.mid = mid;
			res.r = r * b.mid;
			res.prod = false;
		} else {
			res.l = l;
			res.mid = mid + r * b.l + b.mid;
			res.r = b.r;
			res.prod = false;
		}
		return res;
	}

	ll val() const {
		if (prod) {
			return mid;
		} else {
			return l + mid + r;
		}
	}

	void dbg() {
		cerr << l << ' ' << mid << ' ' << r << ' ' << prod << '\n';
	}

	elem (ll x = 0) : l(0), mid(x), r(0), prod(true) {}
};

int n;
string s;
int a[5005];
char op[5005];

elem pref[5005], suff[5005];

elem xxx(elem l, elem r, char o) {
	if (o == '+') {
		return l + r;
	} else {
		return l * r;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;

	n = s.size() / 2 + 1;
	for (int i=0; i<n; i++) {
		a[i] = s[2*i] - '0';
	}

	for (int i=0; i<n-1; i++) {
		op[i] = s[2*i+1];
	}

	pref[1] = elem(a[0]);
	for (int i=2; i<=n; i++) {
		pref[i] = xxx(pref[i-1], elem(a[i-1]), op[i-2]);
	}

	reverse(a, a+n);
	reverse(op, op+n-1);

	suff[1] = elem(a[0]);
	for (int i=2; i<=n; i++) {
		suff[i] = xxx(suff[i-1], elem(a[i-1]), op[i-2]);
	}
	for (int i=2; i<=n; i++) {
		swap(suff[i].l, suff[i].r);
	}

	reverse(a, a+n);
	reverse(op, op+n-1);

	ll sol = 0;
	for (int i=0; i<=n; i++) {
		elem tmp;
		for (int j=i+1; j<=n; j++) {
			if (j == i+1) {
				tmp = elem(a[i]);
			} else {
				tmp = xxx(tmp, elem(a[j-1]), op[j-2]);
			}

			elem tmpzag(tmp.val()), sum;
			if (i > 0) {
				sum = xxx(pref[i], tmpzag, op[i-1]);
			} else {
				sum = tmpzag;
			}

			if (j < n) {
				sum = xxx(sum, suff[n-j], op[j-1]);
			}

			sol = max(sol, sum.val());
		}
	}

	cout << sol << '\n';
}