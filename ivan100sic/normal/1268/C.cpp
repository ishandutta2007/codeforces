#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

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

	T sum(int pos1, int pos2) {
		return sum(pos2) - sum(pos1 - 1);
	}
};

typedef fenwick<ll, 200005> fw;

fw d1, d2;
ordered_set os;

int n;
int a[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i], b[a[i]] = i;

	ll invs = 0;
	for (int i=1; i<=n; i++) {
		invs += d1.sum(n) - d1.sum(b[i]);
		d1.add(b[i], 1);
		d2.add(b[i], b[i]);
		
		os.insert(b[i]);
		auto m = *os.find_by_order(i/2);

		ll rs = d1.sum(m+1, n);
		ll ls = d1.sum(1, m-1);

		ll t = invs + d2.sum(m+1, n) - m*rs;
		t += ls * m - d2.sum(1, m-1);
		t -= rs*(rs+1)/2;
		t -= ls*(ls+1)/2;
		cout << t << " \n"[i == n];
	}
}