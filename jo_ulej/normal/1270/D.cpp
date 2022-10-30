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
//inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
//template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int N = 5;
const int K = 4;
const int M = 4;

const vector<ll> a = {1, 0, 4, 5, 2};
//const vector<ll> a = {1, 2, 4, 6, 8};

pll query(const vector<ll>& pos) {
#ifdef __LOCAL
	vector<pll> temp;
	for(auto& ps: pos) {
		temp.emplace_back(a[ps], ps);
	}

	sort(temp.begin(), temp.end());
	pll rez;
	rez.first = temp[M - 1].second;
	rez.second = temp[M - 1].first;

	return rez;
#else
	cout << "?";

	for(auto& el: pos) {
		cout << ' ' << el + 1;
	}

	cout << endl;
	pll rez;
	cin >> rez.first >> rez.second;
	--rez.first;

	return rez;
#endif
}

void solve() {
#ifdef __LOCAL
	ll n = N;
	ll k = K;
#else
	ll n, k;
	cin >> n >> k;
#endif

	ll hero = NIL;
	ll hero_pos = NIL;

	{
		vector<ll> a;
		for(ll i = 0; i < k; ++i) {
			a.push_back(i);
		}

		auto rez = query(a);
		hero_pos = rez.first;
		hero     = rez.second;
	}

	ll cntA = 0, cntB = 0;
	for(ll i = 0; i < k; ++i) {
		if(i == hero_pos) continue;
		vector<ll> a;
		for(ll j = 0; j < k; ++j) {
			if(j != i) {
				a.push_back(j);
			}
		}

		a.push_back(k);
		ll princess = query(a).second;
		cntA += princess == hero;
		cntB += princess != hero;
	}

	vector<ll> a;
	for(ll i = 0; i < k; ++i) {
		if(i != hero_pos) {
			a.push_back(i);
		}
	}

	a.push_back(k);
	ll dragon = query(a).second;

	DBG(cntA); DBG(cntB);
	if(dragon < hero) {
		cout << "! " << cntA + 1 << endl;
	} else {
		cout << "! " << cntB + 1 << endl;
	}
}

int main() {
	//fast_io();
	solve();

	return 0;
}