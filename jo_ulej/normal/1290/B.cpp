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
	#define DEBUG_OUTPUT_ENABLED 1
#else
	#define DEBUG_OUTPUT_ENABLED 0
#endif

#define dout   debug::instance
#define DBG(X) dout << #X << "=" << (X) << '\n';
#define SAY(X) dout << (X) << '\n';

using namespace std;

template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				if(DEBUG_OUTPUT_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};
	};
	DebugStream instance(true);
};

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
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int A = 26;
namespace stupid {
	int check_against(const string& s, const string& t) {
		int ok = 1;
		vector<int> cnt(A, 0);
		for(int i = 0; i < len(s); ++i) {
			int code = s[i] - 'a';
			++cnt[code];
			code = t[i] - 'a';
			--cnt[code];
			int flag = 0;
			for(auto& el: cnt) {
				if(el != 0) {
					flag = 1;
					break;
				}
			}
			if(!flag && i < len(s) - 1) {
				ok = 0;
				break;
			}
		}
		return ok;
	}
	int check(const string& s) {
		auto t = s;
		sort(t.begin(), t.end());
		do {
			if(check_against(s, t)) {
				DBG(t);
				return 1;
			}
		} while(next_permutation(t.begin(), t.end()));
		return 0;
	}

	int check2(const string& s) {
		if(s.front() != s.back()) return 1;
		set<int> setik;
		for(auto& ch: s) setik.insert(ch);
		return len(setik) >= 3;
	}
};

void research() {
	int n = fetch<int>();
	int m = fetch<int>();
	int cntGood = 0;
	string cur(n, 'a');
	while(true) {
		DBG(cur);
		int rez = stupid::check(cur);
		int rez2 = stupid::check2(cur);
		//DBG(rez);
		//DBG(rez2);
		assert(rez == rez2);
		cntGood += rez;
		int last = n - 1;
		while(last >= 0 && cur[last] == 'a' + m - 1) {
			cur[last] = 'a';
			--last;
		}
		if(last < 0) break;
		++cur[last];
	}

	DBG(cntGood);
}
const int MAXN = (int)2e5 + 7;
string S;
int n, q;
int pref[A][MAXN];
int check(int l, int r) {
	if(S[l] != S[r] || l == r) return 1;
	int uniq = 0;
	for(int code = 0; code < A; ++code) {
		int sum = pref[code][r + 1] - pref[code][l];
		uniq += sum > 0;
	}
	return uniq >= 3;
}
void solve() {
	cin >> S;
	n = len(S);
	for(int i = 1; i <= n; ++i) {
		for(int code = 0; code < A; ++code) {
			pref[code][i] = pref[code][i - 1] + (S[i - 1] - 'a' == code);
		}
	}
	for(cin >> q; q > 0; --q) {
		int l = fetch<int>() - 1;
		int r = fetch<int>() - 1;
		cout << (check(l, r) ? "Yes\n" : "No\n");
	}
}

int main() {
	fast_io();
	//research();
	solve();

	return 0;
}