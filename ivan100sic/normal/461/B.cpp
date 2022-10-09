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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n;
basic_string<int> e[100005];

mint nula[100005], jedan[100005];
int a[100005];

mint v[100005], pref[100005], suff[100005];

void dfs(int x) {
	for (int y : e[x])
		dfs(y);

	if (a[x]) {
		nula[x] = 0;
		jedan[x] = 1;
		for (int y : e[x])
			jedan[x] *= nula[y] + jedan[y];
	} else {
		int m = 0;
		for (int y : e[x]) {
			v[m++] = nula[y] + jedan[y];
		}

		pref[0] = v[0];
		for (int i=1; i<m; i++)
			pref[i] = pref[i-1] * v[i];
		suff[m-1] = v[m-1];
		for (int i=m-2; i>=0; i--)
			suff[i] = suff[i+1] * v[i];

		if (m == 0)
			nula[x] = 1;
		else
			nula[x] = suff[0];

		for (int i=0; i<m; i++) {
			mint ostalo = 1;
			if (i > 0)
				ostalo *= pref[i-1];
			if (i < m-1)
				ostalo *= suff[i+1];
			jedan[x] += ostalo * jedan[e[x][i]];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x;
		cin >> x;
		e[x] += i;
	}

	for (int i=0; i<n; i++)
		cin >> a[i];

	dfs(0);

	cout << (int)jedan[0] << '\n';
}