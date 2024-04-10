#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rac {
	ll x, y;

	rac() : x(0), y() {}

	rac(ll p, ll q) {
		x = p;
		y = q;
		ll g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		// cerr << "created " << x << ' ' << y << '\n';
	}

	bool operator< (const rac& b) const {
		return tie(x, y) < tie(b.x, b.y);
	}
};

int n;
int p[100005];
rac w[300005];

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		pos++;
		// cerr << pos << ' ' << val << '\n';

		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		pos++;
		// cerr << "ask " << pos << '\n';
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 1000005> drvo;

struct upit {
	int id, l;
};

int ans[100005];
vector<upit> e[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		p[i+1] = p[i]+k;
		vector<pair<int, int>> v(k+1);
		for (int i=0; i<k; i++) {
			cin >> v[i].first >> v[i].second;
		}
		v[k] = v[0];
		for (int j=0; j<k; j++) {
			w[j+p[i]] = rac(
				v[j].first - v[j+1].first,
				v[j].second - v[j+1].second);
		}
	}
	int q;
	cin >> q;
	// dquery
	for (int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		l = p[l-1];
		r = p[r];
		e[r].push_back({i, l});
	}

	map<rac, int> seen;
	for (int i=0; i<=p[n]; i++) {
		for (auto [j, l] : e[i]) {
			ans[j] = drvo.sum(i) - drvo.sum(l-1);
		}

		if (i < p[n]) {
			if (seen.count(w[i])) {
				drvo.add(seen[w[i]], -1);
			}
			drvo.add(i, 1);
			seen[w[i]] = i;
		}
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}