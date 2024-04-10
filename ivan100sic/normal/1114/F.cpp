// jebem vam mater

#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

const int SITO_MAX = 300;

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

mint precalc[64];
mint precalc_pows[64][20];

mint marsupickumaterinu1[65536];
mint marsupickumaterinu2[65536];
mint marsupickumaterinu3[65536];
mint marsupickumaterinu4[65536];

mint jebemvamsveglupo1[65536][20];
mint jebemvamsveglupo2[65536][20];
mint jebemvamsveglupo3[65536][20];
mint jebemvamsveglupo4[65536][20];

struct pvec {
	bitset<62> mask;
	mint tot;

	pvec() {
		tot = 1;
	}
	
	pvec operator+ (const pvec& b) const {
		return pvec(*this) += b;
	}

	pvec& operator+= (const pvec& b) {
		tot *= b.tot;
		ull jbg = (mask & b.mask).to_ullong();
		tot *= marsupickumaterinu1[(jbg >> 00) & 65535];
		tot *= marsupickumaterinu2[(jbg >> 16) & 65535];
		tot *= marsupickumaterinu3[(jbg >> 32) & 65535];
		tot *= marsupickumaterinu4[(jbg >> 48) & 65535];
		mask |= b.mask;
		return *this;
	}
};

pvec pw(pvec a, int order) {
	if (order == 0)
		return a;
	a.tot = a.tot ^ (1 << order);
	ull jbg = a.mask.to_ullong();
	a.tot *= jebemvamsveglupo1[(jbg >> 00) & 65535][order];
	a.tot *= jebemvamsveglupo2[(jbg >> 16) & 65535][order];
	a.tot *= jebemvamsveglupo3[(jbg >> 32) & 65535][order];
	a.tot *= jebemvamsveglupo4[(jbg >> 48) & 65535][order];
	return a;
}

pvec factor(int x) {
	pvec tmp;
	int tot = 1;
	for (int i=0; i<62; i++) {
		if (x % prosti[i] == 0) {
			while (x % prosti[i] == 0) {
				tot *= prosti[i];
				x /= prosti[i];
			}
			tot = tot / prosti[i] * (prosti[i] - 1);
			tmp.mask[i] = 1;
		}
	}
	tmp.tot = tot;
	return tmp;
}

const int MAXN = 524288;
pvec a[2*MAXN], b[2*MAXN];

int lg2[524289];

void push(int x, int w) {
	if (b[x].mask == 0)
		return;
	if (x < MAXN) {
		b[2*x] += b[x];
		b[2*x+1] += b[x];
	}
	a[x] += pw(b[x], lg2[w]);
	b[x] = pvec();
}

void update(int l, int r, pvec v, int x, int xl, int xr) {
	if (r < xl || xr < l) {
		push(x, xr-xl+1);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x] += v;
		push(x, xr-xl+1);
		return;
	}
	push(x, xr-xl+1);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = a[2*x] + a[2*x+1];
}

pvec query(int l, int r, int x, int xl, int xr) {
	push(x, xr-xl+1);
	if (r < xl || xr < l)
		return pvec();
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}

pvec factored[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<62; i++) {
		precalc[i] = mint(prosti[i] - 1).inv() * prosti[i];
		for (int j=0; j<20; j++)
			precalc_pows[i][j] = precalc[i] ^ ((1 << j) - 1);
	}

	for (int mask=0; mask<65536; mask++) {
		marsupickumaterinu1[mask] = 1;
		marsupickumaterinu2[mask] = 1;
		marsupickumaterinu3[mask] = 1;
		marsupickumaterinu4[mask] = 1;
		for (int i=0; i<16; i++) {
			if (mask & (1 << i)) {
				marsupickumaterinu1[mask] *= precalc[i + 00];
				marsupickumaterinu2[mask] *= precalc[i + 16];
				marsupickumaterinu3[mask] *= precalc[i + 32];
				marsupickumaterinu4[mask] *= precalc[i + 48];
			}
		}

		for (int i=0; i<20; i++) {
			jebemvamsveglupo1[mask][i] = marsupickumaterinu1[mask] ^ ((1 << i) - 1);
			jebemvamsveglupo2[mask][i] = marsupickumaterinu2[mask] ^ ((1 << i) - 1);
			jebemvamsveglupo3[mask][i] = marsupickumaterinu3[mask] ^ ((1 << i) - 1);
			jebemvamsveglupo4[mask][i] = marsupickumaterinu4[mask] ^ ((1 << i) - 1);
		}
	}

	for (int i=1; i<=300; i++)
		factored[i] = factor(i);

	for (int i=0; i<=19; i++)
		lg2[1 << i] = i;

	int n, q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i + MAXN - 1] = factored[x];
	}
	for (int i=MAXN-1; i>=1; i--)
		a[i] = a[2*i] + a[2*i+1];

	while (q--) {
		string s;
		cin >> s;
		if (s[0] == 'M') {
			int l, r, x;
			cin >> l >> r >> x;
			update(l, r, factored[x], 1, 1, MAXN);
		} else {
			int l, r;
			cin >> l >> r;
			cout << (int)query(l, r, 1, 1, MAXN).tot << '\n';
		}
	}
}