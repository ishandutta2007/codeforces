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

#define min(A, B) ((A) < (B) ? (A) : (B))
#define max(A, B) ((A) > (B) ? (A) : (B))

const int MAXN = (int)1e6 + 77;
ll a[MAXN], b[MAXN], total = 0;
int n;

ll get(ll* p, int l, int r) {
	if(l <= r) {
		return p[r] - (l == 0 ? 0 : p[l - 1]);
	} else {
		return 0;
	}
}

int head = 0;
pll BL[MAXN];
ll p[MAXN], p2[MAXN];

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		total += a[i];
	}

	DBG(total);
	vector<ll> F;

	for(ll i = 2; i * i <= total; ++i) {
		if(total % i == 0) {
			F.push_back(i);

			while(total % i == 0) {
				total /= i;
			}
		}
	}

	if(total > 1) {
		F.push_back(total);
	}

	ll answ = LL_INF;

	for(auto& d: F) {
		DBG(d);
		for(int i = 0; i < n; ++i) {
			b[i] = a[i] % d;
		}

		int cur = 0;
		ll local = 0;

		while(cur < n) {
			while(cur < n && b[cur] == 0) {
				++cur;
			}

			if(cur == n) {
				break;
			}

			ll sum = 0;
			head = 0;

			while(sum != d) {
				while(b[cur] == 0) {
					++cur;
				}	

				ll take = min(d - sum, b[cur]);
				BL[head++] = make_pair(take, cur);

				b[cur] -= take;
				sum += take;
			}

			for(int i = 0; i < head; ++i) {
				p[i] = BL[i].first + (i == 0 ? 0 : p[i - 1]);
				p2[i] = BL[i].first * BL[i].second + (i == 0 ? 0 : p2[i - 1]);
			}

			ll opt = LL_INF;

			for(int med = 0; med < head; ++med) {
				ll med_idx = BL[med].second;
				ll temp = med_idx * get(p, 0, med - 1) - get(p2, 0, med - 1);
				temp += get(p2, med + 1, head - 1) - med_idx * get(p, med + 1, head - 1);
				DBG(temp);

				opt = min(opt, temp);
			}

			local += opt;
		}

		DBG(local);
		answ = min(answ, local);
	}

	cout << (answ == LL_INF ? NIL : answ) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}