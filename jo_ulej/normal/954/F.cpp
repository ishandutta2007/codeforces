#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)1e5 + 77;
const int MOD  = (int)1e9 + 7;
const int N    = 3;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int n;
ll m;
ll L[MAXN], R[MAXN], a[MAXN];
vector<ll> ord;
int sz;
int ban[MAXN][N];

struct Matrix {
	int v[N][N];

	Matrix() {
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				v[i][j] = 0;
			}
		}
	}

	Matrix operator*(const Matrix& other) const {
		Matrix rez;

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				for(int k = 0; k < N; ++k) {
					rez.v[i][j] = add(rez.v[i][j], mult(v[i][k], other.v[k][j]));
				}
			}
		}

		return rez;
	}

	void apply(vector<int>& dp) const {
		vector<int> ndp(N, 0);

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				ndp[j] = add(ndp[j], mult(v[i][j], dp[i]));
			}
		}

		dp = ndp;
	}
};

Matrix binpow(const Matrix& x, ll y) {
	if(y == 1) {
		return x;
	}

	Matrix rez = binpow(x, y / 2);
	rez = rez * rez;

	if(y & 1) {
		rez = rez * x;
	}

	return rez;
}

void go(vector<int>& dp, int msk_in, int msk_out, ll cnt) {
	/*while(cnt--) {
		vector<int> ndp(N, 0);

		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if((msk >> j) & 1) {
					continue;
				}

				if(abs(j - i) > 1) {
					continue;
				}

				ndp[j] = add(ndp[j], dp[i]);
			}
		}

		dp = ndp;
	}*/

	if(cnt == 0) {
		return;
	}

	Matrix matr;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if((msk_in >> j) & 1) {
				continue;
			}

			if((msk_out >> i) & 1) {
				continue;
			}

			if(abs(j - i) > 1) {
				continue;
			}

			matr.v[i][j] = 1;
		}
	}

	auto pw = binpow(matr, cnt);
	pw.apply(dp);
}

void solve() {
	cin >> n >> m;
	ord.push_back(1);
	ord.push_back(m);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> L[i] >> R[i];
		--a[i];
		ord.push_back(L[i]);
		ord.push_back(R[i]);

		ord.push_back(L[i] - 1);
		ord.push_back(R[i] + 1);
	}

	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());
	sz = len(ord);
	for(int i = 0; i < n; ++i) {
		L[i] = lower_bound(ord.begin(), ord.end(), L[i]) - ord.begin();
		R[i] = lower_bound(ord.begin(), ord.end(), R[i]) - ord.begin();

		++ban[L[i]][a[i]];
		--ban[R[i] + 1][a[i]];
	}

	for(int i = 1; i < sz; ++i) {
		for(int c = 0; c < N; ++c) {
			ban[i][c] += ban[i - 1][c];
		}
	}

	vector<int> dp(N, 0);
	dp[1] = 1;
	DBG(ord);

	for(int i = 1; i < sz; ++i) {
		ll cnt = ord[i] - ord[i - 1];
		int msk = 0;

		for(int j = 0; j < N; ++j) {
			if(ban[i - 1][j] > 0) {
				msk |= 1 << j;
			}
		}

		if(cnt > 1) {
			go(dp, msk, msk, cnt - 1);
			DBG(dp);
		}

		int msk2 = 0;
		for(int j = 0; j < N; ++j) {
			if(ban[i][j] > 0) {
				msk2 |= 1 << j;
			}
		}

		go(dp, msk2, msk, 1);
		DBG(dp);
	}

	cout << dp[1] << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}