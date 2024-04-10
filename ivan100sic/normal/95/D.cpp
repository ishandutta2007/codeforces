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

int k;
mint dp[1005][2][1005];
bool vis[1005][2][1005];


// gap za 4700 je 3
// gap za stringove koji ni nemaju ovo je 0
void advance(int& gap, int& done, char t) {
	if (gap == 0) {
		if (t == '4' || t == '7')
			gap = 1;
	} else {
		if (t == '4' || t == '7') {
			done |= gap <= k;
			gap = 1;
		} else {
			gap++;
		}
	}
}

mint go(int gap, int done, int left) {
	// cerr << "called go " << gap << ' ' << done << ' ' << left << '\n';
	mint& z = dp[gap][done][left];
	if (vis[gap][done][left])
		return z;
	vis[gap][done][left] = 1;

	if (left == 0) {
		z = done;
	} else {
		int gap1 = gap, gap4 = gap;
		int done1 = done, done4 = done;
		advance(gap1, done1, '1');
		advance(gap4, done4, '4');
		z += go(gap1, done1, left-1) * 8;
		z += go(gap4, done4, left-1) * 2;
	}

	// cerr << gap << ' ' << done << ' ' << left << ' ' << (int)z << '\n';
	return z;
}

string bump(string s) {
	if (count(s.begin(), s.end(), '9') == (int)s.size())
		return string("1") + string(s.size(), '0');

	int t = s.size() - 1;
	s[t]++;
	while (s[t] == '9' + 1) {
		s[t] = '0';
		t--;
		s[t]++;
	}
	return s;
}


mint solve(string s) {
	mint z = 0;
	int gap = 0;
	int done = 0;
	for (int i=0; i<(int)s.size(); i++) {
		for (char t='0'; t<s[i]; t++) {
			int tgap = gap;
			int tdone = done;
			advance(tgap, tdone, t);
			z += go(tgap, tdone, s.size() - i - 1);
		}
		advance(gap, done, s[i]);
	}
	// cerr << "solving " << s << ' ' << (int)z << '\n';
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t >> k;
	while (t--) {
		string l, r;
		cin >> l >> r;
		r = bump(r);
		cout << (int)(solve(r) - solve(l)) << '\n';
	}
}