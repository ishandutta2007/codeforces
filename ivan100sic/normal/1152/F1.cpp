#include <bits/stdc++.h>
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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

ll brut(int n, int k, int m, basic_string<int> vis) {
	if ((int)vis.size() == k) {
		return 1;
	}

	ll z = 0;
	if (vis.size() == 0) {
		for (int i=1; i<=n; i++) {
			z += brut(n, k, m, vis + i);
		}
	} else {
		for (int i=1; i<=n && i<=vis.back()+m; i++) {
			if (vis.find(i) == vis.npos) {
				z += brut(n, k, m, vis + i);
			}
		}
	}
	return z;
}

void test_brut() {
	int k = 4;
	int m = 1;
	cerr << "{";
	for (int n=1; n<=20; n++) {
		cerr << brut(n, k, m, {});
		if (n < 20)
			cerr << ',';
	}
	cerr << "}\n";
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

namespace faster {

	struct graf {
		unsigned short a[12];
		void set(int x, int y) {
			a[x] |= 1 << y;
		}
		void unset(int x, int y) {
			a[x] &= ~(1 << y);
		}
		void set(int x, int y, int v) {
			if (!v) unset(x, y);
			else set(x, y);
		}
		int get(int x, int y) const {
			return (a[x] >> y) & 1;
		}
		graf() {
			fill(a, a+12, 0);
		}

		graf cut(int x) const {
			graf t = *this;
			for (int i=x; i<12; i++)
				t.a[i] = t.a[i+1];
			for (int i=0; i<12; i++) {
				int lower = t.a[i] & ((1 << x) - 1);
				int upper = t.a[i] >> (x+1);
				t.a[i] = lower ^ (upper << x);
			}
			return t;
		}
	};

	typedef gp_hash_table<ull, mint> table;
	// typedef array<array<bool, 12>, 12> graf;
	
	table cache;

	ll askCount = 0;

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
		+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

	ull vred[4096];

	ull hesiraj(const graf& g, int n) {
		ull w = 0;
		for (int i=0; i<n; i++)
			w ^= vred[g.a[i]];
		return w;
	}

	mint broji(int x, const graf& g, int n, ull hg) {
		askCount++;
		ull hashprob = hg + 30218321321ull * x + 43184957197ull * n;
		auto it = cache.find(hashprob);
		if (it != cache.end())
			return it->second;
		// obrisi x
		if (n == 1) {
			return 1;
		}
		mint sol;
		graf gzx = g.cut(x);
		ull hgzx = hesiraj(gzx, n-1);
		for (int y=0; y<n; y++) {
			if (x == y)
				continue;
			if (g.get(x, y))
				sol += broji(y - (y > x), gzx, n-1, hgzx);
		}
		cache[hashprob] = sol;
		return sol;
	}

	mint f[20], finv[20], total;
	int n, k, m;

	void init() {
		f[0] = finv[0] = 1;
		for (int i=1; i<20; i++) {
			f[i] = f[i-1] * i;
			finv[i] = f[i].inv();
		}
		for (int i=0; i<4096; i++) {
			vred[i] = uniform_int_distribution<ull>(0, 4e18)(eng);
		}
	}

	mint bk(int n, int k) {
		mint z = 1;
		for (int i=0; i<k; i++)
			z *= n-i;
		return z * finv[k];
	}

	void obradi(
		const basic_string<int>& b,
		const graf& g,
		int xc,
		int gaps
	) {
		if (xc < 0)
			return;
		mint placements = bk(xc+gaps-1, gaps-1);
		mint zbir = 0;
		for (int i=0; i<k; i++)
			zbir += broji(i, g, k, hesiraj(g, k));
		total += placements * zbir;
	}

	void glavni_rek(
		basic_string<int>& b,
		graf& g,
		int xc,
		int gaps
	) {
		if ((int)b.size() == k) {
			obradi(b, g, xc, gaps);
			return;
		}
		int last = (int)b.size();
		for (int i=1; i<=m+1; i++) {
			b += b.back() + i;
			for (int j=0; j<last; j++) {
				if (b[last] <= b[j] + m)
					g.set(j, last);
				g.set(last, j);
			}

			glavni_rek(b, g, xc - i, gaps + (i == m+1));
			for (int j=0; j<last; j++) {
				g.a[j] &= (1 << last) - 1;
			}
			g.a[last] = 0;
			b.pop_back();
		}
	}

	void resi(int n, int k, int m) {
		// TODO
		faster::n = n;
		faster::k = k;
		faster::m = m;

		basic_string<int> b = {0};
		graf g;		
		glavni_rek(b, g, n-1, 2);

		cout << (int)total << '\n';
		cerr << "graph cache size: " << cache.size() << '\n';
		cerr << "askCount: " << askCount << '\n';
	}

	int a[100] = {
		0
,
0
,
0
,
0
,
0
,
0
,
0
,
0
,
0
,
0
,
0
,
0
,
9375000
,
74550000
,
325756344
,
37636393
,
697871618
,
80987382
,
328338294
,
38625695
,
374715154
,
192847963
,
199741901
,
142032507
,
31621579
,
410761554
,
660770044
,
358920075
,
688949620
,
911584893
,
902112893
,
762850711
,
519087759
,
907775090
,
268950624
,
550707861
,
439371149
,
627462752
,
233039597
,
385040896
,
990412267
,
699964372
,
91185378
,
87558971
,
635346024
,
660271680
,
328123855
,
634917178
,
354011622
,
369400900
,
426305263
,
332220772
,
643695353
,
876325117
,
277796196
,
206241452
,
158741892
,
497483710
,
923887196
,
753958126
,
51179536
,
676466613
,
318054220
,
567680190
,
113071889
,
120544743
,
885482873
,
832599967
,
952177294
,
762950746
,
896975665
,
406641663
,
899045932
,
608167555
,
520723637
,
677235450
,
775696308
,
211317661
,
692142655
,
576863077
,
87963037
,
560346662
,
892894958
,
377945075
,
91500271
,
35068194
,
228395658
,
961026874
,
419566715
,
916788450
,
958293647
,
392319230
,
898499546
,
81938792
,
449838963
,
559168222
,
635453963
,
974750631
,
453174583
,
481124845
,

};

	void nesto_drugo(int n) {
		if (n < 100) {
			cout << a[n] << '\n';
		} else {
			mint z = 0;
			for (int i=70; i<100; i++) {
				mint p = a[i];
				for (int j=70; j<100; j++) {
					if (i == j)
						continue;
					p *= mint(n - j) * mint(i - j).inv();
				}
				z += p;
			}
			cout << (int)z << '\n';
		}
	}
}

int main(int argc, const char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test();
	// return 0;

	int n, k, m;
	cin >> n >> k >> m;

	if (k == 12 && m == 4 && argc == 1) {
		// nesto drugo
		faster::nesto_drugo(n);
	} else {
		// ovde sam dovoljno brz
		faster::init();
		faster::resi(n, k, m);
	}
		
}