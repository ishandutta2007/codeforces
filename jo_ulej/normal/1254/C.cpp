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

ll ask_sign(int i, int j, int k) {
	ll rez;
	cout << "2 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	cin >> rez;

	return -rez;
}

ll ask_area(int i, int j, int k) {
	ll rez;
	cout << "1 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	cin >> rez;

	return rez;
}

void finish(const vector<int>& answ) {
	cout << "0 ";

	for(auto& i: answ) {
		cout << i + 1 << ' ';
	}

	cout << endl;
}

void order(vector<int>& p) {
	if(p.empty()) {
		return;
	}

	int sz = len(p);
	vector<pair<int, ll>> info(sz);

	for(int i = 0; i < sz; ++i) {
		info[i].first = p[i];
		info[i].second = ask_area(p[i], 0, 1);
	}

	int mx = 0;

	for(int i = 1; i < sz; ++i) {
		if(info[i].second > info[mx].second) {
			mx = i;
		}
	}

	vector<pair<ll, int>> L, R;

	for(int i = 0; i < sz; ++i) {
		if(i != mx) {
			if(ask_sign(info[i].first, 0, info[mx].first) == +1) {
				L.emplace_back(info[i].second, info[i].first);
			} else {
				R.emplace_back(info[i].second, info[i].first);
			}
		}
	}

	p.clear();
	sort(L.begin(), L.end());
	sort(R.rbegin(), R.rend());

	for(auto& pr: L) {
		p.push_back(pr.second);
	}

	p.push_back(info[mx].first);

	for(auto& pr: R) {
		p.push_back(pr.second);
	}
}

void solve() {
	int n = fetch<int>();
	vector<int> U, D;

	for(int i = 2; i < n; ++i) {
		if(ask_sign(i, 0, 1) == +1) {
			U.push_back(i);
		} else {
			D.push_back(i);
		}
	}

	order(U);
	order(D);
	//reverse(D.begin(), D.end());

	vector<int> answ;
	answ.push_back(0);

	for(auto& i: U) {
		answ.push_back(i);
	}

	answ.push_back(1);

	for(auto& i: D) {
		answ.push_back(i);
	}

	finish(answ);
}

int main() {
	//fast_io();
	solve();

	return 0;
}