#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

using namespace chrono;
struct stopwatch {
	typedef time_point<high_resolution_clock> tp;

	tp last_tick;
	bool notock = false;

	void tick() {
		last_tick = high_resolution_clock::now();
	}

	void tock() const {
		duration<double> dur = high_resolution_clock::now() - last_tick;
		cerr << "Time: " << dur.count() << '\n';
	}

	stopwatch() {
		tick();
	}

	stopwatch(int) {
		tick();
		notock = true;
	}

	~stopwatch() {
		if (!notock) {
			tock();
		}
	}
};

ll brut(string s) {
	int n = s.size();
	vector<int> z(n+1);
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + (s[i] == '1');
	ll sol = 0;
	for (int i=0; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (z[j] != z[i] && (j-i) % (z[j] - z[i]) == 0)
				sol++;
	return sol;
}

string daj(int n) {
	bernoulli_distribution e(0.01);
	string s(n, 0);
	for (int i=0; i<n; i++)
		s[i] = e(eng) ? '1' : '0';
	return s;
}

const int H = 600;

struct sloper {
	int n;
	string s;
	vector<int> z;

	ll cntslope(int u) {
		vector<int> tmp(n+1);
		for (int i=0; i<=n; i++)
			tmp[i] = i - u*z[i];
		sort(tmp.begin(), tmp.end());
		ll tot = 0;
		int str = 1;
		for (int i=1; i<=n; i++) {
			if (tmp[i] == tmp[i-1])
				str++;
			else
				str = 1;
			tot += str-1;
		}
		return tot;
	}

	void prepslope() {
		z.resize(n+1);
		for (int i=0; i<n; i++)
			z[i+1] = z[i] + (s[i] == '1');
	}

	sloper(string s) {
		this->s = s;
		this->n = s.size();
		prepslope();
	}

	// oko 2400ms za 500 slopeova
};

struct wer {
	int n;
	string s;
	vector<int> z;

	ll cnt_w(int w) {
		ll sol = 0;
		for (int r=0; r<w; r++) {
			vector<int> zv, zlo, zhi;
			for (int i=r, ii=0; i<=n; i+=w, ii++) {
				if (zv.size() && zv.back() == z[i]) {
					zhi.back() = ii;
				} else {
					zv.push_back(z[i]);
					zlo.push_back(ii);
					zhi.push_back(ii);
				}
			}

			int kk = zv.size(), b = 0;
			for (int a=0; a<kk; a++) {
				while (b < kk && zv[a] - zv[b] > w)
					b++;
				if (b < kk && zv[a] - zv[b] == w) {
					for (int x = zlo[a]; x <= zhi[a]; x++) {
						sol += max(0, min(x-H-1, zhi[b]) - zlo[b] + 1);
					}
				}
			}
		}
		return sol;
		// vector<int> lo(n+1, n+1), hi(n+1, -1);
		// for (int i=0; i<=n; i++) {
		// 	lo[z[i]] = min(lo[z[i]], i);
		// 	hi[z[i]] = max(hi[z[i]], i);
		// }
		// ll sol = 0;
		// for (int i=w; i<=n; i++) {
		// 	for (int j=lo[i]; j<=hi[i]; j++) {
		// 		sol += max(0, min(j-w*H-1, hi[i-w]) - lo[i-w] + 1);
		// 	}
		// }
		// return sol;
	}

	void prepslope() {
		z.resize(n+1);
		for (int i=0; i<n; i++)
			z[i+1] = z[i] + (s[i] == '1');
	}

	wer(string s) {
		this->s = s;
		this->n = s.size();
		prepslope();
	}
};

ll resi(string s) {
	sloper a(s);
	ll asol = 0;
	for (int i=1; i<=H; i++)
		asol += a.cntslope(i);

	wer b(s);
	ll bsol = 0;
	for (int i=1; i<=200000 / H + 2; i++)
		bsol += b.cnt_w(i);
	return asol + bsol;
}

void test2() {
	int reps = 10;
	while (reps--) {
		string s = daj(2000);
		// string s = string(200000, '0');
		cerr << resi(s) << '\n';
		cerr << brut(s) << '\n';
	}
	exit(0);
}

void test3() {
	cerr << resi(daj(200000)) << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test3();

	string s;
	cin >> s;
	cout << resi(s) << '\n';
}