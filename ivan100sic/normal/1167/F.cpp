#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[500005], as[500005], rnk[500005];

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

fenwick<ll, 500005> drvo;
const int mod = 1'000'000'007;

ll sol;
int n;

void solve_once() {
	memset(drvo.a, 0, sizeof(drvo.a));
	copy(a, a+n, as);
	sort(as, as+n);
	for (int i=0; i<n; i++)
		rnk[i] = lower_bound(as, as+n, a[i]) - as + 1;

	for (int i=0; i<n; i++) {
		drvo.add(rnk[i], i+1);
		ll g = drvo.sum(rnk[i]);
		sol += g * (n-i) % mod * a[i] % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	solve_once();
	reverse(a, a+n);
	solve_once();
	for (int i=0; i<n; i++)
		sol -= a[i] * (i+1ll) % mod * (n-i) % mod;
	sol = (sol % mod + mod) % mod;
	cout << sol << '\n';
}