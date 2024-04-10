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

const int N = 47;
const int SZ = 1024 * 1024 + 777;
int ban[N][N];
int n;
int dp[SZ];

void solve() {
	int cnt = fetch<int>();
	cin >> n;
	vector<pair<int, string>> data(cnt);
	vector<string> names;
	for(auto& el: data) {
		cin >> el.first;
		if(el.first == 2) {
			cin >> el.second;
			names.push_back(el.second);
		}
	}

	sort(names.begin(), names.end());
	names.erase(unique(names.begin(), names.end()), names.end());
	DBG(names);

	for(int i = 0; i < cnt;) {
		if(data[i].first == 2) {
			set<int> verts;
			int j = i;
			while(j < cnt && data[j].first == 2) {
				int v = lower_bound(names.begin(), names.end(), data[j].second) - names.begin();
				verts.insert(v);
				++j;
			}

			for(auto& v: verts) {
				for(auto& u: verts) {
					if(v != u) ban[v][u] = 1;
				}
			}

			i = j;
		} else {
			++i;
		}
	}

#ifdef __LOCAL
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) cout << ban[i][j];
		cout << '\n';
	}
#endif

	int half = n / 2, rem = n - half;
	for(int msk = 0; msk < (1<<half); ++msk) {
		int ok = 1;
		int sz = 0;

		for(int i = 0; i < half; ++i) {
			if((msk>>i)&1) {
				++sz;
				for(int j = 0; j < half; ++j) {
					if((msk>>j)&1) {
						if(ban[i][j]) {
							ok = 0;
							break;
						}
					}
				}

				if(!ok) break;
			}
		}

		if(ok) {
			dp[msk] = sz;
		}
	}

	for(int j = 0; j < half; ++j) {
		int bit = 1<<j;
		for(int msk = 0; msk < (1<<half); ++msk) {
			if(msk&bit) {
				dp[msk] = max(dp[msk], dp[msk^bit]);
			}
		}
	}

	int answ = 0;
	for(int msk = 0; msk < (1<<rem); ++msk) {
		int ok = 1;
		int sz = 0;
		int msk2 = (1<<half)-1;

		for(int i = 0; i < rem; ++i) {
			if((msk>>i)&1) {
				++sz;
				for(int j = 0; j < rem; ++j) {
					if((msk>>j)&1) {
						if(ban[half+i][half+j]) {
							ok = 0;
							break;
						}
					}
				}

				if(!ok) break;
				for(int j = 0; j < half; ++j) {
					if(ban[half+i][j]) {
						msk2 &= ((1<<half)-1)^(1<<j);
					}
				}
			}
		}

		if(ok) {
			answ = max(answ, sz + dp[msk2]);
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}