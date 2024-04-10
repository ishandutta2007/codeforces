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

const int MOD = 998244353;
typedef modint<MOD> mint;

mint sx, sx2, sy, sy2, c, sdp;

int n, m;
int a[1005][1005];
mint dp[1005][1005];

struct pt {
	int x, y;
};

vector< vector<pt> > pos;
vector<pt> govno_od_zadatka;

bool cmp(pt b, pt c) {
	return a[b.x][b.y] < a[c.x][c.y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			govno_od_zadatka.push_back({i, j});
		}

	sort(govno_od_zadatka.begin(), govno_od_zadatka.end(), cmp);
	
	vector<pt> tmp;
	for (pt b : govno_od_zadatka) {
		if (tmp.size() == 0 || !cmp(tmp.back(), b)) {
			// rip
		} else {
			pos.push_back(tmp);
			tmp.clear();
		}
		tmp.push_back(b);
	}
	pos.push_back(tmp);

	// cerr << pos.size() << '\n';

	for (auto& e : pos) {
		// racunaj dp
		for (auto& p : e) {
			int x = p.x;
			int y = p.y;

			mint val = sdp;
			val += c * (x * x + y * y);
			val += sx2;
			val += sy2;
			val -= sx * (2 * x);
			val -= sy * (2 * y);
			val *= c.inv();
			dp[x][y] = val;
		}

		for (auto& p : e) {
			int x = p.x;
			int y = p.y;

			c += 1;
			sx += x;
			sy += y;
			sx2 += x * x;
			sy2 += y * y;
			sdp += dp[x][y];
		}
	}

	int r, c;
	cin >> r >> c;
	cout << (int)dp[r][c] << '\n';
}