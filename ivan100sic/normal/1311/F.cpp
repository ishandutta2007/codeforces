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

struct pt {
	int x, v;

	bool operator< (const pt& b) const {
		if (v != b.v)
			return v < b.v;
		return x < b.x;
	}
};

bool cmpx(pt a, pt b) {
	return a.x < b.x;
}

int n;
pt a[200005];
fenwick<ll, 200005> z;
fenwick<int, 200005> ct;
int p[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x;
	for (int i=0; i<n; i++)
		cin >> a[i].v;

	sort(a, a+n, cmpx);
	for (int i=0; i<n; i++)
		p[i] = a[i].x;

	sort(a, a+n);

	ll sol = 0;

	for (int i=0; i<n; i++) {
		// a[i].x
		int j = lower_bound(p, p+n, a[i].x) - p;
		ll sum = z.sum(j);
		int cnt = ct.sum(j);
		sol += a[i].x * 1ll * cnt - sum;
		z.add(j, a[i].x);
		ct.add(j, 1);
	}

	cout << sol << '\n';
}