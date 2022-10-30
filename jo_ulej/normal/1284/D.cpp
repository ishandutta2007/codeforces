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

struct Data {
	int L1, R1, L2, R2;
};

struct ByL1 {
	bool operator()(const Data& lhs, const Data& rhs) const {
		return lhs.L1 < rhs.L1;
	}
};

struct ByR1 {
	bool operator()(const Data& lhs, const Data& rhs) const {
		return lhs.R1 < rhs.R1;
	}
};

int check_forward(vector<Data> a) {
	int n = len(a);
	auto byL1 = a;
	auto byR1 = a;
	sort(byL1.begin(), byL1.end(), ByL1());
	sort(byR1.begin(), byR1.end(), ByR1());
	set<int> setik;
	int j = 0;

	for(int i = 0; i < n; ++i) {
		while(j < n && byR1[j].R1 < byL1[i].L1) {
			setik.insert(byR1[j].L2);
			setik.insert(byR1[j].R2);
			++j;
		}

		auto iter = setik.lower_bound(byL1[i].L2);
		if(iter != setik.end()) {
			int val = *iter;
			if(val <= byL1[i].R2) {
				DBG(byL1[i].L1); DBG(byL1[i].R1);
				DBG(byL1[i].L2); DBG(byL1[i].R2);
				DBG(val);
				return 0;
			}
		}
	}

	return 1;
}

int check_both_ways(vector<Data> a) {
	if(!check_forward(a)) return 0;
	for(auto& el: a) {
		el.L1 = -el.L1;
		el.R1 = -el.R1;

		swap(el.L1, el.R1);
	}

	return check_forward(a);
}

int check(vector<Data> a) {
	if(!check_both_ways(a)) return 0;
	for(auto& el: a) {
		swap(el.L1, el.L2);
		swap(el.R1, el.R2);
	}

	return check_both_ways(a);
}

void solve() {
	int n = fetch<int>();
	vector<Data> a(n);
	for(auto& el: a) {
		cin >> el.L1 >> el.R1 >> el.L2 >> el.R2;
	}

	int rez = check(a);
	cout << (rez ? "YES\n" : "NO\n");
}

int main() {
	fast_io();
	solve();

	return 0;
}