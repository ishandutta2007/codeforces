#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct ulll {
	unsigned a[3];

	ulll(ull x = 0) {
		a[0] = x & 0xfffffff;
		a[1] = (x >> 28) & 0xfffffff;
		a[2] = x >> 56;
	}

	// bool sgn() {
	// 	return a[2] & 0x80000000u;
	// }

	bool operator<= (const ulll& b) const {
		return tie(a[2], a[1], a[0]) <= tie(b.a[2], b.a[1], b.a[0]);
	}

	ulll& operator+= (const ulll& b) {
		for (int i=0; i<3; i++)
			a[i] += b.a[i];

		a[1] += a[0] >> 28;
		a[0] &= 0xfffffff;
		a[2] += a[1] >> 28;
		a[1] &= 0xfffffff;
		a[2] &= 0xfffffff;

		return *this;
	}

	ulll operator+ (const ulll& b) const {
		ulll t = *this;
		t += b;
		return t;
	}

	ulll operator* (const ulll& b) {
		ulll t;
		ull g[3] = {0, 0, 0};
		g[0] = 1ull * a[0] * b.a[0];
		g[1] = 1ull * a[0] * b.a[1] + 1ull * a[1] * b.a[0];
		g[2] = 1ull * a[0] * b.a[2] + 1ull * a[1] * b.a[1] + 1ull * a[2] * b.a[0];

		g[1] += g[0] >> 28;
		g[0] &= 0xfffffff;
		g[2] += g[1] >> 28;
		g[1] &= 0xfffffff;
		g[2] &= 0xfffffff;

		t.a[0] = g[0];
		t.a[1] = g[1];
		t.a[2] = g[2];

		return t;
	}

	ulll flip() const {
		ulll a = *this;
		for (int i=0; i<3; i++)
			a.a[i] ^= 0xfffffff;
		if (++a.a[0] == 0x10000000u) {
			a.a[0] = 0;
			if (++a.a[1] == 0x10000000u) {
				a.a[1] = 0;
				if (++a.a[2] == 0x10000000u) {
					a.a[2] = 0;
				}
			}
		}
		return a;
	}

	ulll operator- (ulll b) {
		b = b.flip();
		b += *this;
		return b;
	}
};

vector<ll> b;

int n;
ll l[100005], r[100005], minw;
int sl[100005], sr[100005];
ulll zl[100005], zr[100005], k;

bool cmpl(int i, int j) {
	return l[i] < l[j];
}

bool cmpr(int i, int j) {
	return r[i] < r[j];
}

int pl, pr;

ulll cost(ll u, ll v) {
	if (v-u > minw)
		return 4e18;
	// svima kojima je levi kraj veci od u hocu da
	// naplatim L-u
	ulll z = 0;
	while (pl < n && l[sl[pl]] < u)
		pl++;
	z += (zl[n] - zl[pl]) - ulll(n-pl) * u;

	// cerr << u << ' ' << v << ' ' << (int)z.a[0] << '\n';

	// svi kojima je desni kraj manji od v hocu da
	// naplatim v-R
	while (pr < n && r[sr[pr]] < v)
		pr++;

	// cerr << u << ' ' << v << ' ' << (int)z.a[0] << '\n';
	
	z += ulll(pr) * v - zr[pr];

	// cerr << u << ' ' << v << ' ' << (int)z.a[0] << '\n';

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	const int H =
#ifdef LOCAL
		8
#else
		18
#endif
		;

	for (int l=1; l<=H; l++) {
		for (int m=0; m<(1<<l); m++) {
			ll z = 0;
			for (int i=0; i<l; i++) {
				if (m & (1 << i)) {
					z = 10*z + 7;
				} else {
					z = 10*z + 4;
				}
			}
			b.push_back(z);
		}
	}
	sort(b.begin(), b.end());

	cin >> n;
	{
		ull k;
		cin >> k;
		::k = k;
	}
	minw = 4e18;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
		sl[i] = sr[i] = i;
		minw = min(minw, r[i] - l[i]);
	}

	sort(sl, sl+n, cmpl);
	sort(sr, sr+n, cmpr);
	int o = 0;

	for (int i=0; i<n; i++) {
		zl[i+1] = zl[i] + l[sl[i]];
		zr[i+1] = zr[i] + r[sr[i]];
	}

	for (int l=0, r=0; l<(int)b.size(); l++) {
		r = max(l, r);
		ll u = b[l];
		while (r < (int)b.size()) {
			ll v = b[r];
			if (cost(u, v) <= k)
				r++;
			else
				break;
		}
		o = max(o, r-l);
	}

	cout << o << '\n';
}