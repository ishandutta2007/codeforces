#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int SITO_MAX = 40000;

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

vpii factor(int x) {
	vpii v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

int m, k;
pair<int, int> m_factors[15];
int m_moduli[15];
int stepeni[15][35];

int getstepen(int i, int x) {
	if (x >= m_factors[i].second)
		return 0;
	return stepeni[i][x];
}

vpii vektorizuj(int x) {
	vpii v(k);
	for (int i=0; i<k; i++) {
		int& alpha = v[i].second;
		int t = x;
		while (t % m_factors[i].first == 0) {
			alpha++;
			t /= m_factors[i].first;
		}
		v[i].first = t % m_moduli[i];
	}
	return v;
}

vpii saberi(const vpii& a, const vpii& b) {
	vpii c(k);
	for (int i=0; i<k; i++) {
		pii p = a[i];
		pii q = b[i];
		if (p.second > q.second)
			swap(p, q);
		int r = (p.first + q.first * 1ll * getstepen(i, q.second-p.second))
			% m_moduli[i];
		c[i] = {r, p.second};
	}
	return c;
}

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll modinv(int x, int m) {
	int p, q;
	eea(x, m, p, q);
	p %= m;
	if (p < 0)
		p += m;
	return p;
}

ll eea_coeffs[15];

int sastavi(vpii a) {
	ll rez = 0;
	for (int i=0; i<k; i++) {
		ll q = a[i].first * 1ll * getstepen(i, a[i].second) % m
			* eea_coeffs[i] % m;
		rez += q;
	}
	rez %= m;
	if (rez < 0)
		rez += m;
	return rez;
}

void precompute() {
	auto v = factor(m);
	copy(v.begin(), v.end(), m_factors);
	k = v.size();
	for (int i=0; i<k; i++) {
		int p = v[i].first;
		int z = 1;
		for (int j=0; j<v[i].second; j++) {
			stepeni[i][j] = z;
			z *= p;
		}
		m_moduli[i] = z;
	}

	for (int i=0; i<k; i++) {
		int Mi = m / m_moduli[i];
		eea_coeffs[i] = modinv(Mi, m_moduli[i]) * 1ll * Mi % m;
		cerr << "eea " << i << ' ' << eea_coeffs[i] << '\n';		
	}
}

const int MAXN = 131072;
vpii a[2*MAXN];
vpii b[2*MAXN];

void postavi(int i, vpii v) {
	a[i + MAXN] = v;
}

void propagiraj() {
	for (int i=MAXN; i<2*MAXN; i++)
		if (a[i].size() == 0)
			a[i] = vpii(k, pii(1, 100'000'000));

	for (int i=1; i<2*MAXN; i++)
		b[i] = vpii(k, pii(1, 0));

	for (int i=MAXN-1; i>=1; i--)
		a[i] = saberi(a[2*i], a[2*i+1]);
}

void pomnozi(vpii& a, const vpii& b) {
	for (int i=0; i<k; i++) {
		a[i].second += b[i].second;
		a[i].first = (a[i].first * 1ll * b[i].first) % m_moduli[i];
	}
}

void push(int x) {
	if (x < MAXN) {
		pomnozi(b[2*x+0], b[x]);
		pomnozi(b[2*x+1], b[x]);
	}
	pomnozi(a[x], b[x]);
	fill(b[x].begin(), b[x].end(), pii(1, 0));
}

void update(int l, int r, const vpii& v, int x = 1, int xl = 0, int xr = MAXN-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}

	if (l <= xl && xr <= r) {
		pomnozi(b[x], v);
		push(x);
		return;
	}

	push(x);
	int xm = (xl + xr) >> 1;
	update(l, r, v, 2*x+0, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	a[x] = saberi(a[2*x], a[2*x+1]);
}

int query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	push(x);
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return sastavi(a[x]);
	int xm = (xl + xr) >> 1;
	int tmp = query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	if (tmp >= m)
		tmp -= m;
	return tmp;
}

void dbg(vpii a) {
	for (int i=0; i<k; i++)
		cerr << "(" << a[i].first << " x " <<
			m_factors[i].first << " ^ " << a[i].second << ") ";
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n >> m;
	precompute();
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		auto v = vektorizuj(x);
		// dbg(v);
		// cerr << sastavi(v) << '\n';
		postavi(i, v);
	}
	propagiraj();

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 3) {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		} else if (t == 2) {
			int p, x;
			cin >> p >> x;
			auto v = vektorizuj(x);
			for (int i=0; i<k; i++) {
				v[i].second *= -1;
				v[i].first = modinv(v[i].first, m_moduli[i]);
			}
			update(p, p, v);
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			auto v = vektorizuj(x);
			update(l, r, v);
		}
	}
}