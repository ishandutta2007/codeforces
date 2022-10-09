// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T>
struct compressor {
	vector<T*> v;
	void operator+=(T& x) { v.push_back(&x); }
	~compressor() { (*this)(); }

	T operator() (T init = T()) {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		T last = 0, q = 0;
		for (size_t i=0; i<v.size(); i++) {
			if (!i || *v[i] != last) q++;
			last = *v[i];
			*v[i] = q - 1 + init;
		}
		return q;
	}
};

struct seg {
	int l, r, v;
	template<class T>
	auto operator< (const T& b) const {
		return r-l < b.r-b.l;
	}
};

int n;
seg a[3005];
int d[3005];

vector<seg> v;

void dod(seg s) {
	v.push_back(s);
}

int dp[6005];

int resi() {
	memset(dp, 224, sizeof dp);
	dp[0] = 0;
	sort(begin(v), end(v), [](seg u, seg v) { return u.l < v.l; });
	int pf = 0, sol = 0;
	for (auto [l, r, v] : v) {
		while (pf+1 < l) {
			dp[pf+1] = max(dp[pf+1], dp[pf]);
			pf++;
		}
		dp[r] = max(dp[r], (l ? dp[l-1] : 0) + v);
		sol = max(sol, dp[r]);
	}
	v = {};
	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		{
			compressor<int> c;
			for (int i=0; i<n; i++) {
				cin >> a[i].l >> a[i].r;
				c += a[i].l;
				c += a[i].r;
			}
			a[n] = {-5, 200005};
			c += a[n].l;
			c += a[n].r;
			n++;
		}

		sort(a, a+n);

		for (int i=0; i<n; i++) {
			// resi sve koji staju unutra
			for (int j=0; j<i; j++) {
				if (a[i].l <= a[j].l && a[j].r <= a[i].r) {
					dod(a[j]);
				}
			}

			a[i].v = resi() + 1;
		}

		cout << a[n-1].v - 1 << '\n';
	}
}