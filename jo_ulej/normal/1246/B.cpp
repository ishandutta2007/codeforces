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
#else
	#define DBG(X)
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

const int MAXN = (int)1e5 + 777;

vector<pii> a[MAXN];
vector<int> st[MAXN];
vector<vector<pii>> by_lbl[MAXN];

int lbl[MAXN];
int n, k;
ll answ = 0;

void solve() {
	cin >> n >> k;

	for(int pos = 0; pos < n; ++pos) {
		int value = fetch<int>();

		for(int i = 2; i * i <= value; ++i) {
			if(value % i == 0) {
				int cnt = 0;

				while(value % i == 0) {
					value /= i;
					++cnt;
				}

				cnt %= k;

				if(cnt) {
					a[pos].emplace_back(i, cnt);
				}
			}
		}

		if(value > 1) {
			a[pos].emplace_back(value, 1);
		}

		//sort(a[pos].begin(), a[pos].end());
		DBG(a[pos]);
	}

	vector<vector<int>> sets;

	for(int i = 0; i < n; ++i) {
		for(auto& pr: a[i]) {
			st[i].push_back(pr.first);
		}

		sets.push_back(st[i]);
	}

	sort(sets.begin(), sets.end());

	for(int i = 0; i < n; ++i) {
		lbl[i] = lower_bound(sets.begin(), sets.end(), st[i]) - sets.begin();
		by_lbl[lbl[i]].push_back(a[i]);
	}

	for(int lb = 0; lb < n; ++lb) {
		sort(by_lbl[lb].begin(), by_lbl[lb].end());

		for(auto& elem: by_lbl[lb]) {
			vector<pii> comp;

			for(auto& pr: elem) {
				comp.emplace_back(pr.first, k - pr.second);
			}

			auto fst = lower_bound(by_lbl[lb].begin(), by_lbl[lb].end(), comp);
			auto lst = upper_bound(by_lbl[lb].begin(), by_lbl[lb].end(), comp);

			answ += lst - fst;

			if(comp == elem) {
				--answ;
			}
		}
	}

	cout << answ / 2 << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}