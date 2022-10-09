#include <bits/stdc++.h>
using namespace std;

template<unsigned long long m>
struct modint {

	unsigned long long x;

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
		x = (x * other.x) % m;
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

	explicit operator unsigned long long () const {
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

	modint operator^ (unsigned long long arg) const {
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

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
typedef modint<MOD> mint;


int n;

struct pt {
	int x, y, id;
};

pt a[100005];
int xx[100005], yy[100005];
vector<int> e[100005];

bool vis[100005];
int edges;
int nodes;

set<int> razx, razy;

void dfs(int x) {
	vis[x] = true;
	nodes++;
	razx.insert(xx[x]);
	razy.insert(yy[x]);

	for (int y : e[x]) {
		edges++;
		if (!vis[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> xx[i] >> yy[i];
		a[i] = {xx[i], yy[i], i};
	}

	// prvi levo/desno
	sort(a, a+n, [](pt u, pt v) {
		return make_pair(u.x, u.y) < make_pair(v.x, v.y);
	});

	map<int, int> preth_x;

	for (int i=0; i<n; i++) {
		int y = a[i].y;
		int ii = a[i].id;

		if (preth_x.count(y)) {
			int j = preth_x[y];
			e[ii].push_back(j);
			e[j].push_back(ii);
		}
		preth_x[y] = ii;
	}

	sort(a, a+n, [](pt u, pt v) {
		return make_pair(u.y, u.x) < make_pair(v.y, v.x);
	});

	map<int, int> preth_y;

	for (int i=0; i<n; i++) {
		int x = a[i].x;
		int ii = a[i].id;

		if (preth_y.count(x)) {
			int j = preth_y[x];
			e[ii].push_back(j);
			e[j].push_back(ii);
		}
		preth_y[x] = ii;
	}

	mint sol = 1;

	for (int i=0; i<n; i++) {
		if (!vis[i]) {
			edges = 0;
			nodes = 0;
			razx.clear();
			razy.clear();
			dfs(i);
			if (edges == 2*nodes - 2) {
				// drvo
				sol *= (mint(2) ^ (nodes+1)) - 1;
			} else {
				// izbroji razlicite koordinate
				sol *= mint(2) ^ (razx.size() + razy.size());
			}
		}
	}

	cout << (unsigned long long)sol << '\n';
}