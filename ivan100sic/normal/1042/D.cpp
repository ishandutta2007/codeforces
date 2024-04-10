#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[200005], z[200005], s[200005];
int n;
ll k;

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

fenwick<int, 200005> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}
	copy(z, z+n+1, s);
	sort(s, s+n+1);

	ll sol = 0;

	for (int i=0; i<=n; i++) {
		// proveri
		auto it = upper_bound(s, s+n+1, z[i] - k);
		int pos = it - s - 1;

		// cerr << z[i] << s[pos] << '\n';

		sol += i - drvo.sum(pos);

		drvo.add(lower_bound(s, s+n+1, z[i]) - s, 1);
	}

	cout << sol << '\n';

}