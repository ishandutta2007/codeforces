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
		pos++;
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		pos++;
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 1000005> z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	basic_string<int> his;
	int brima = 0;
	for (int i=0; i<n; i++) {
		int l;
		cin >> l;
		int lo = 2e9, ima = 0, hi = -2e9;
		for (int i=0; i<l; i++) {
			int x;
			cin >> x;
			if (lo < x) {
				ima = 1;
			}
			lo = min(lo, x);
			hi = max(hi, x);
		}
		if (ima)
			brima++;
		else {
			his += hi;
			z.add(lo, 1);
		}
	}
	ll sol = n*1ll*n - (n-brima)*1ll*(n-brima);
	for (int x : his) {
		if (x) sol += z.sum(x-1);
	}
	cout << sol << '\n';
}