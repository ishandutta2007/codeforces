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
		x = (x * 1ull * other.x) % m;
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

const int MOD = 998244353;
typedef modint<MOD> mint;

string podeli(string a, int x) {
	int n = a.size();
	for (int i=0; i<n; i++) {
		if (i < n-1) {
			a[i+1] += a[i] % x * 10;
		}
		a[i] /= x;
	}
	return a;
}

string smanji(string s) {
	for (char& x : s)
		x -= '0';
	return s;
}

string povecaj(string s) {
	for (char& x : s)
		x += '0';
	return s;
}

mint broj(string s) {
	mint z = 0;
	for (char x : s) {
		z = z*10 + x;
	}
	return z;
}

mint dp[111][16][16][10][10];

void inc(string& s) {
	int i = s.size() - 1;
	s[i]++;
	while (s[i] == 10) {
		s[i] = 0;
		i--;
		s[i]++;
	}
}

void mul(string& s, int x) {
	int n = s.size();
	for (int i=n-1; i>=0; i--) {
		s[i] *= x;
	}
	for (int i=n-1; i>=0; i--) {
		if (i)
			s[i-1] += s[i] / 10;
		s[i] %= 10;
	}
}

mint resi(string s, string s0, int px, int py, vector<int> dx, vector<int> dy) {
	inc(s);
	int m = dx.size();
	int n = s.size();

	int M = (1 << m)-1;

	auto add_mask = [&](const vector<int>& d, int e) {
		e = find(d.begin(), d.end(), e) - d.begin();
		return (1 << e) & M;
	};

	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0] = 1;

	for (int i=0; i<n; i++) { // proveri
		for (int mx=0; mx<(1<<m); mx++) {
			for (int my=0; my<(1<<m); my++) {
				for (int cx=0; cx<10; cx++) {
					for (int cy=0; cy<10; cy++) {
						// dodavam cifru u
						for (int u=0; u<10; u++) {
							int ex = (u*px+cx)%10;
							int fx = (u*px+cx)/10;

							int ey = (u*py+cy)%10;
							int fy = (u*py+cy)/10;
							
							int mx0 = mx | add_mask(dx, ex);
							int my0 = my | add_mask(dy, ey);

							dp[i+1][mx0][my0][fx][fy] += dp[i][mx][my][cx][cy];
						}
					}
				}
			}
		}
	}

	mint sol;

	for (int i=0; i<n; i++) {
		for (int j=0; j<int(s[i]); j++) {
			string q = s.substr(0, i) + char(j);
			for (int cx=0; cx<10; cx++) {
				for (int cy=0; cy<10; cy++) {
					string qx = q, qy = q;

					mul(qx, px);
					mul(qy, py);

					for (int _=0; _<cx; _++)
						inc(qx);
					for (int _=0; _<cy; _++)
						inc(qy);

					int mx0 = 0, my0 = 0;
					for (int x : qx)
						mx0 |= add_mask(dx, x);
					for (int y : qy)
						my0 |= add_mask(dy, y);

					// cerr << "kreten " << povecaj(qx) << ' ' << povecaj(qy) << ' '
					// 	<< mx0 << ' ' << my0 << '\n';

					for (int mx=0; mx<(1<<m); mx++) {
						for (int my=0; my<(1<<m); my++) {
							int mfx = mx | mx0;
							int mfy = my | my0;

							mint val = dp[n-i-1][mx][my][cx][cy];
							// if (val != 0) {
							// 	cerr << povecaj(q) << ' ' << povecaj(qx) << ' ' << povecaj(qy) << ' ' << mfx << mfy << cx << cy << ' ' << (int)val << '\n';
							// }

							if (mfx & mfy)
								sol += val;
						}
					}
				}
			}
		}
	}

	// cerr << "resi " << px << ' ' << py << ' ' << povecaj(s) << ' ' << (int)sol << '\n';
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// resi(smanji("0021"), smanji("0042"), 1, 2, {1,2,3,4}, {2,4,6,8});
	// return 0;

	string s;
	cin >> s;
	s = string("00") + s; // sigurica
	s = smanji(s);

	mint sol;

	for (int xp=1; xp<=9; xp++) {
		for (int yp=1; yp<=9; yp++) {

			if (xp+yp == 2) {
				sol += broj(s);
				continue;
			}

			if (gcd(xp, yp) == 1) {
				string p = podeli(s, max(xp, yp));

				vector<int> dx, dy;
				for (int i=1; i<=9/max(xp, yp); i++) {
					dx.push_back(i*xp);
					dy.push_back(i*yp);
				}

				sol += resi(p, s, xp, yp, dx, dy);
			}
		}
	}

	cout << (int)sol << '\n';
}