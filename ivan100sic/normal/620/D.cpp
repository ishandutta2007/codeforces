#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// aleksa smaras

struct sol {
	ll vr;
	int i, j, k, l;

	bool operator< (const sol& b) const {
		return vr < b.vr;
	}
};

int n, m;
int a[2005], b[2005];
ll rz;

sol resi01() {
	sol t = {abs(rz), -1, -1, -1, -1};
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			t = min(t, sol{abs(rz + 2*b[j] - 2*a[i]), i, j, -1, -1});
	return t;
}

struct stvar {
	ll v;
	int i, j;
	bool operator< (const stvar& b) const {
		return v < b.v;
	}
};

sol resi2() {
	vector<stvar> c, d;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			c.push_back({a[i] + a[j], i, j});
	for (int i=0; i<m; i++)
		for (int j=i+1; j<m; j++)
			d.push_back({b[i] + b[j], i, j});
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	auto it = d.begin();
	
	sol ret = {(ll)1e18, -1, -1, -1, -1};

	for (stvar st : c) {
		// rz + 2*it->v - 2*st.v = 0
		while (it != d.end() && 2*it->v < 2*st.v - rz)
			++it;
		if (it != d.end()) { // znak
			ret = min(ret, sol{abs(rz + 2*it->v - 2*st.v), st.i, it->i, st.j, it->j});
		}
		if (it != d.begin()) {
			--it;
			ret = min(ret, sol{abs(rz + 2*it->v - 2*st.v), st.i, it->i, st.j, it->j});
			++it;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i], rz += a[i];
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> b[i], rz -= b[i];

	auto z = min(resi01(), resi2());
	cout << z.vr << '\n';
	cout << (z.i >= 0) + (z.l >= 0) << '\n';
	if (z.i >= 0)
		cout << z.i+1 << ' ' << z.j+1 << '\n';
	if (z.l >= 0)
		cout << z.k+1 << ' ' << z.l+1 << '\n';
}