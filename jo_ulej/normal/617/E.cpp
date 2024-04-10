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
	#define DBG(X) cout << "[DBG] " << #X << "=" << (X) << '\n';
	#define SAY(X) cout << "[SAY] " << (X) << '\n';
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

const int MAXN = (int)1e5 + 7;
const int MAXC = (int)2e6 + 7;
int a[MAXN], n, m, k, B;
ll answ[MAXN];
struct Query {
	int l, r, id;
	bool operator<(const Query& other) const {
		return make_pair(l / B, r) < make_pair(other.l / B, other.r);
	}
};
Query q[MAXN];
int cnt[MAXC], L = 0, R = 0;
ll cur = 0;
ll calc(int val) {
	if(k == 0) {
		return (cnt[val] * 1LL * (cnt[val] - 1)) / 2;
	} else {
		return cnt[val] * 1LL * cnt[val ^ k];
	}
}
void addR() {
	int val = a[R++];
	cur -= calc(val);
	++cnt[val];
	cur += calc(val);
}
void addL() {
	int val = a[L++];
	cur -= calc(val);
	--cnt[val];
	cur += calc(val);
}
void subR() {
	int val = a[--R];
	cur -= calc(val);
	--cnt[val];
	cur += calc(val);
}
void subL() {
	int val = a[--L];
	cur -= calc(val);
	++cnt[val];
	cur += calc(val);
}
void solve() {
	cin >> n >> m >> k;
	++n;
	B = sqrt(n);
	for(int i = 1; i < n; ++i) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
	for(int id = 0; id < m; ++id) {
		cin >> q[id].l >> q[id].r;
		--q[id].l;
		q[id].id = id;
	}
	sort(q, q + m);
	for(int i = 0; i < m; ++i) {
		while(L > q[i].l) subL();
		while(R < q[i].r + 1) addR();
		while(L < q[i].l) addL();
		while(R > q[i].r + 1) subR(); 
		assert(L <= R);
		answ[q[i].id] = cur;
	}
	for(int id = 0; id < m; ++id) {
		cout << answ[id] << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}