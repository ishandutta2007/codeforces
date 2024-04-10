#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int mod = 1e9 + 7;

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int binpow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			mul(ans, a);
		}
		n >>= 1;
		mul(a, a);
	}
	return ans;
}

vector<int> BM(vector<int> s) {
	int N = sz(s);
	vector<int> c = {1};
	vector<int> b = {1};
	int l = 0;
	int m = 1;
	int bb = 1;
	for (int n = 0; n < N; ++n) {
		int d = s[n];
		for (int i = 1; i <= l; ++i) {
			int val = c[i];
			mul(val, s[n - i]);
			add(d, val);
		}
		if (d == 0) {
			++m;
			continue;
		}
		vector<int> t = c;
		vector<int> tt = b;
		b.insert(b.begin(), m, 0);
		int val = binpow(bb, mod - 2);
		mul(val, d);
		for (int j = 0; j < sz(b); ++j) {
			mul(b[j], val);
		}
		while (sz(c) < sz(b)) {
			c.pb(0);
		}
		for (int j = 0; j < sz(b); ++j) {
			sub(c[j], b[j]);
		}
		if (2 * l <= n) {
			l = n + 1 - l;
			b = t;
			bb = d;
			m = 1;
		} else {
			b = tt;
			++m;
		}
	}
	return c;
}

const int s = 1000;
const int shift = 500;
const int inf = 1e9;

int dist[s][s];

int dx[8] = {-1, -1, -2, -2, 2, 2, 1, 1};
int dy[8] = {-2, 2, -1, 1, -1, 1, -2, 2};

typedef vector<vector<int> > matrix;

matrix operator*(const matrix& a, const matrix& b) {
	int n = sz(a);
	int m = sz(a[0]);
	int k = sz(b[0]);
	matrix c(n, vector<int>(k));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int z = 0; z < k; ++z) {
				int val = a[i][j];
				mul(val, b[j][z]);
				add(c[i][z], val);
			}
		}
	}
	return c;
}

matrix binpow(matrix a, ll n) {
	int k = sz(a);
	matrix ans(k, vector<int>(k));
	for (int i = 0; i < k; ++i) {
		ans[i][i] = 1;
	}
	/*for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}*/
	//cout << "\n";
	while (n) {
		if (n & 1) {
			ans = ans * a;
		}
		n >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll z;
	int n;
	cin >> z >> n;

	memset(dist, -1, sizeof(dist));
	dist[shift][shift] = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		x += shift, y += shift;
		dist[x][y] = inf;
	}

	queue<pii> q;
	q.push({shift, shift});
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		for (int k = 0; k < 8; ++k) {
			int i = x + dx[k], j = y + dy[k];
			if (i >= 0 && i < s && j >= 0 && j < s && dist[i][j] == -1) {
				dist[i][j] = dist[x][y] + 1;
				q.push({i, j});
			}
		}
	}

	vector<int> ss(shift / 3);

	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			if (dist[i][j] != -1 && dist[i][j] < shift / 3) {
				//cout << dist[i][j] << endl;
				++ss[dist[i][j]];
			}
		}
	}

	for (int i = 1; i < sz(ss); ++i) {
		add(ss[i], ss[i - 1]);
	}

	vector<int> c = BM(ss);
	//cout << sz(c) << endl;
	//cout << ss[2] << endl;

	int k = sz(c);
	if (k == 2) {
		cout << ss[1] << endl;
		return 0;
	}
	//cout << "!" << k << endl;
	matrix base(k - 1, vector<int>(k - 1));
	for (int i = 0; i < k - 2; ++i) {
		base[i][i + 1] = 1;
	}
	for (int i = 0; i < k - 1; ++i) {
		int val = (mod - c[k - i - 1]) % mod;
		base[k - 2][i] = val;
	}
	//return 0;
	//cout << ss[0] << " " << ss[1] << " " << ss[2] << endl;


	matrix m = binpow(base, z);
	/*for (int i = 0; i < sz(m); ++i) {
		for (int j = 0; j < sz(m); ++j) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}*/
	//cout << k << endl;
	int ans = 0;
	for (int i = 0; i < k - 1; ++i) {
		int val = m[0][i];
		//cout << val << " " << ss[i] << endl;
		mul(val, ss[i]);
		add(ans, val);
	}
	//cout << ss[z] << endl;
	cout << ans << "\n";

}