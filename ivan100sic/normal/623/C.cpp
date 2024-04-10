/*
	Ugly piece of trash problem, never again
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
binarno po D:
Za fiksno Lx:
Trazimo najmanje Rx takvo da se spolja ne javlja par takav da je (Ymax-Ymin)^2 > D
Takodje zahtevamo da je (Rx-Lx)^2 <= D
Sad vise ne razmisljamo o tim uslovima i cak mozemo da uzmemo samo vrednosti y^2
Za sve tacke levo od L imamo jedno ogranicenje za R i to je jos jedan uslov za R^2
Obavezno proveriti i da y^2 + L^2 <= D ne puca za tacke levo od L

U ovom trenutku imamo segment mogucih vrednosti za R

da li postoji R koje zadovoljava uslove gore i:
za svaku tacku (x, y) iz spoljasnjosti treba da vazi y^2+R^2 <= D
odnosno to ili x <= R
*/

const int inf = 1e9;
const int hii = 1e8;
int n, m, x[100005], a[100005], b[100005];

int af[100005], ar[100005], bf[100005], br[100005];

void read_input() {
	cin >> n;
	vector<pair<int, int>> t(n);
	for (auto& [x, y] : t)
		cin >> x >> y;
	sort(t.begin(), t.end());
	for (auto [p, q] : t) {
		if (m && p == x[m-1]) {
			a[m-1] = min(a[m-1], q);
			b[m-1] = max(b[m-1], q);
		} else {
			a[m] = b[m] = q;
			x[m++] = p;
		}
	}
}

ll isqrt(ll x) {
	// x >= 0
	ll t = sqrt(ld(x));
	while ((t+1)*(t+1) <= x)
		t++;
	while (t*t > x)
		t--;
	return t;
}

ll kv(ll x) {
	return x*x;
}

struct node {
	int l, r;
};

struct piif {
	int first, second;
	bool operator< (const piif& b) const {
		return first < b.first;
	}
};

struct impl {
	set<piif> s;
	int lastl, lastr, lastw;

	impl() {
		lastl = 0, lastr = 0, lastw = 0;
	}

	void mark(int l, int r) {
		// cerr << "markiram " << l << ' ' << r << '\n';
		auto it = s.lower_bound({l, 0});
		while (it != s.end() && it->first <= r+1) {
			r = max(r, it->second);
			s.erase(it++);
		}
		while (it != s.begin() && prev(it)->second >= l-1) {
			l = min(l, prev(it)->first);
			r = max(r, prev(it)->second);
			s.erase(prev(it));
		}
		s.insert({l, r});
		if (r-l > lastr-lastl || lastw == 0) {
			lastl = l, lastr = r, lastw = 1;
		}

		// cerr << "sadrzaj:\n";
		// for (auto [x, y] : s)
		// 	cerr << "    " << x << ' ' << y << '\n';
	}

	void add(int x, int y, ll D) {
		D -= kv(y);
		if (D >= 0) {
			int rad = isqrt(D);
			if (rad+1 <= x-1) {
				mark(rad+1, x-1);
				mark(-inf, -rad-1);
			} else {
				mark(-inf, -rad-1);				
			}
		} else {
			mark(-inf, x-1);
		}
	}

	int query1(int l, int r) {
		if (lastw && lastl <= l && r <= lastr)
			return 0;
		// da li je [l, r] ceo u nekom segmentu?
		auto it = s.lower_bound({l+1, 0});
		if (it != s.begin()) {
			--it;
			if (it->first <= l && r <= it->second)
				return 0;
			else
				return 1;
		}
		return 1;
	}

	int query(int l, int r) {
		return l <= r && query1(l, r);
	}
};

bool moze(ll D) {
	impl drvo;
	if (kv(bf[m] - af[m]) <= D)
		return true;
	// cerr << "resavam " << D << "\n\n";
	for (int i=m-1; i>=0; i--) {
		int L = x[i];
		int Rlo = L, Rhi = L + isqrt(D);
		if (i) {
			ll q = D - max(kv(af[i]), kv(bf[i]));
			if (kv(L) > q)
				Rhi = -inf;
			else {
				int rad = isqrt(q);
				Rhi = min(Rhi, rad);
				Rlo = max(Rlo, -rad);
			}
		}
		
		{
			int l = i, r = m-1, o = -1;
			while (l <= r) {
				int j = (l+r) >> 1;
 
				int ly = min(af[i], ar[m-j-1]);
				int ry = max(bf[i], br[m-j-1]);
 
				if (ly > ry || (kv(ly-ry) <= D && max(kv(ly), kv(ry)) + kv(L) <= D)) {
					o = j;
					r = j - 1;
				} else {
					l = j + 1;
				}
			}
 
			// cerr << "o = " << o << '\n';
 
			if (o == -1)
				Rhi = -inf;
			else
				Rlo = max(Rlo, x[o]);
		}

		// cerr << "pitam drvo " << Rlo << ' ' << Rhi << '\n';

		if (drvo.query(Rlo, Rhi))
			return true;

		// update drvo
		drvo.add(x[i], max(abs(a[i]), abs(b[i])), D);
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	read_input();
	af[0] = ar[0] = inf;
	bf[0] = br[0] = -inf;
	for (int i=0; i<m; i++) {
		af[i+1] = min(af[i], a[i]);
		ar[i+1] = min(ar[i], a[m-1-i]);
		bf[i+1] = max(bf[i], b[i]);
		br[i+1] = max(br[i], b[m-1-i]);
	}

	ll lo = 0, hi = 4.0001e16, sol = -1;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (moze(mid)) {
			sol = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}