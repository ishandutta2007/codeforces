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

const int MAXK = 16;
const int MAXN = 5007;

ll vals[MAXK][MAXN], sum[MAXK], X = 0;
pii go[MAXK][MAXN];
int cnt[MAXK], k;
map<ll, pii> pos;

int used[MAXK], mark = 13;
int dp[1 << MAXK], parent[1 << MAXK];
pii start[1 << MAXK];

int cycle[MAXK][MAXN];

pii Q[MAXK];
int head = 0;

int chosen[MAXK], after[MAXK];

void run(pii cur) {
	head = 0;
	++mark;

	while(true) {
		used[cur.first] = mark;
		auto nxt = go[cur.first][cur.second];

		after[nxt.first] = cur.first;
		chosen[cur.first] = cur.second;

		cur = nxt;
		if(used[cur.first] == mark) {
			break;
		}
	}
}

void dfs(int msk) {
	DBG(msk);

	if(msk == 0) {
		exit(-1);
	}

	if(start[msk].first != NIL && start[msk].second != 	NIL) {
		run(start[msk]);
	} else {
		int submsk = parent[msk];
		DBG(parent[msk]);
		
		dfs(submsk);
		dfs(msk ^ submsk);
	}
}

void solve() {
	cin >> k;

	for(int i = 0; i < k; ++i) {
		cin >> cnt[i];

		for(int j = 0; j < cnt[i]; ++j) {
			cin >> vals[i][j];
			sum[i] += vals[i][j];
			X += vals[i][j];

			pos[vals[i][j]] = make_pair(i, j);
		}
	}

	if(X % k != 0) {
		cout << "No\n";
		return;
	}

	X /= k; DBG(X);

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			ll to_find = X - sum[i] + vals[i][j];

			if(pos.count(to_find)) {
				go[i][j] = pos[to_find];
			} else {
				go[i][j] = make_pair(NIL, NIL);
			}
		}
	}

	for(int msk = 0; msk < (1 << k); ++msk) {
		start[msk] = make_pair(NIL, NIL);
	}

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			if(cycle[i][j] > 0) {
				continue;
			}

			head = 0;
			++mark;

			pii cur = make_pair(i, j);
			int ok = 1;

			while(true) {
				used[cur.first] = mark;
				Q[head++] = cur;

				cur = go[cur.first][cur.second];

				if(cur.first == NIL || cur.second == NIL) {
					ok = 0;
					break;
				}

				if(used[cur.first] == mark) {
					if(cur != Q[0]) {
						ok = 0;
					}	

					break;
				}
			}

			if(ok) {
				for(int ptr = 0; ptr < head; ++ptr) {
					cycle[i][j] |= (1 << Q[ptr].first);
				}

				for(int ptr = 0; ptr < head; ++ptr) {
					cycle[Q[ptr].first][Q[ptr].second] = cycle[i][j];
				}

				dp[cycle[i][j]] = 1;
				start[cycle[i][j]] = make_pair(i, j);
			}
		}
	}

	for(int msk = 0; msk < (1 << k); ++msk) {
		if(dp[msk]) {
			continue;
		}

		for(int submsk = msk; submsk > 0; submsk = (submsk - 1) & msk) {
			if(dp[submsk] && dp[msk ^ submsk]) {
				dp[msk] = 1;
				parent[msk] = submsk;

				break;
			}
		}
	}

	int fmask = (1 << k) - 1;

	if(dp[fmask]) {
		cout << "Yes\n";
		dfs(fmask);

		for(int i = 0; i < k; ++i) {
			cout << vals[i][chosen[i]] << ' ' << after[i] + 1 << '\n';
		}
	} else {
		cout << "No\n";
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}