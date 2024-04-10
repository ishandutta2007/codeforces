#include <bits/stdc++.h>
using namespace std;

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

int n, m;
int a[1000005];
mint d[1005][1005];

void readinput() {
	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> a[i];
}

void generate() {
	n = 500;
	m = 999;
	for (int i=0; i<m; i++)
		a[i] = 1 + min(i, m-1-i);
}

int prvi[555], zadnji[555];
bool ban[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	readinput();

	m = unique(a, a+m) - a;

	if (m >= 2*n) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<=m; i++)
		d[i][i] = 1;

	for (int x=1; x<=n; x++) {
		int p = -1, q = -1;
		for (int i=0; i<m; i++) {
			if (a[i] == x) {
				if (p == -1)
					p = i;
				q = i;
			}
		}
		q++;
		for (int i=p; i<q; i++)
			if (a[i] < x) {
				cout << "0\n";
				return 0;
			}
	}

	for (int l=m-1; l>=0; l--) {
		for (int r=l+1; r<=m; r++) {
			int vr = *min_element(a+l, a+r);
			memset(ban, 0, sizeof(ban));
			memset(prvi, 255, sizeof(prvi));
			memset(zadnji, 255, sizeof(zadnji));
			for (int i=l; i<r; i++) {
				zadnji[a[i]] = i;
				if (prvi[a[i]] == -1)
					prvi[a[i]] = i;
			}
			int p = prvi[vr], q = zadnji[vr] + 1;

			for (int x=vr+1; x<=n; x++)
				fill(ban+prvi[x]+1, ban+zadnji[x]+1, true);

			mint sl = 0, sr = 0, pm = 1;

			// l <= i <= p < q <= j <= r
			for (int i=l; i<=p; i++)
				if (!ban[i])
					sl += d[l][i] * d[i][p];

			for (int j=q; j<=r; j++)
				if (!ban[j])
					sr += d[q][j] * d[j][r];

			int aa = -1, bb = -1;
			for (int i=p; i<q; i++) {
				if (a[i] > vr) {
					if (aa == -1) {
						aa = i;
						bb = i+1;
					} else {
						bb++;
					}
				} else {
					if (aa != -1) {
						pm *= d[aa][bb];
						aa = bb = -1;
					}
				}
			}
			if (aa != -1)
				pm *= d[aa][bb];

			// cerr << l << ' ' << r << ' ' << (int)sl;
			// cerr << ' ' << (int)sr << ' ' << (int)pm << '\n';

			d[l][r] = sl*sr*pm;
		}
	}

	cout << (int)d[0][m] << '\n';
}