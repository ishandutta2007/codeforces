#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

int d[1000005];

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

int a[1000005];
fenwick<ll, 300005> fe;
set<int> veliki;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	d[1] = 1;
	for (int i=2; i<=SITO_MAX; i++) {
		int p = f[i];
		int x = i;
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		d[i] = d[x] * (c+1);
	}

	int n, q;

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		fe.add(i, x);
		a[i] = x;
		if (x > 2)
			veliki.insert(i);
	}

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 2) {
			cout << fe.sum(r) - fe.sum(l-1) << '\n';
		} else {
			while (l <= r) {
				auto it = veliki.lower_bound(l);
				if (it == veliki.end())
					break;
				int i = *it;
				if (i > r)
					break;
				veliki.erase(it);
				fe.add(i, -a[i]);
				a[i] = d[a[i]];
				fe.add(i, +a[i]);
				if (a[i] > 2) veliki.insert(i);
				l = i + 1;
			}
		}
	}
}