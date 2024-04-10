#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <random>
#ifdef __LOCAL
#define DBG(X) cout << "[DBG] " << #X << ": " << (X) << '\n';
#else
#define DBG(X) 42;
#endif
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
const int INT_INT = (int)2e9;
const ll LL_INF = (ll)2e18;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	for(auto& el: vec) os << el << ' ';
	return os;
}
template<class T> T fetch() {
	T rez;
	cin >> rez;
	return rez;
}
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
const int MAXN = (int)1e6 + 7;
ll mod[4 * MAXN], mx[4 * MAXN];
inline ll read(int v) {
	return mod[v] + mx[v];
}
inline void relax(int v) {
	mx[v] = max(read(2*v+1), read(2*v+2));
}
inline void push(int v) {
	mod[2*v+1] += mod[v];
	mod[2*v+2] += mod[v];
	mx[v] += mod[v];
	mod[v] = 0;
}
void change(int v, int tl, int tr, int l, int r, ll x) {
	if(l < tl) l = tl;
	if(r > tr) r = tr;
	if(l > r) return;
	if(tl == l && tr == r) {
		mod[v] += x;
	} else {
		push(v);
		int tm = (tl+tr)/2;
		change(2*v+1, tl, tm, l, r, x);
		change(2*v+2, tm + 1, tr, l, r, x);
		relax(v);
	}
}
int n, m, p;
map<ll, ll> weapon, shield;
struct Monster {
	ll x, y, z;
};
Monster mstr[MAXN];
vector<int> open[MAXN];
ll a[MAXN];
inline void add(int l, int r, ll x) {
	//cout << "@add: " << l << ' ' << r << ' ' << x << '\n';
	//for(int i = l; i <= r; ++i) a[i] += x;
	change(0, 0, MAXN - 1, l, r, x);
}
inline ll getMX() {
	/*ll rez = -LL_INF;
	for(int i = 0; i < MAXN; ++i) rez = max(rez, a[i]);
	return rez*/
	return read(0);
}
void solve() {
	cin >> n >> m >> p;
	for(int i = 0; i < n; ++i) {
		ll a = fetch<ll>();
		ll cost = fetch<ll>();
		if(!weapon.count(a)) {
			weapon[a] = cost;
		} else {
			weapon[a] = min(weapon[a], cost);
		}
	}
	for(int i = 0; i < m; ++i) {
		ll b = fetch<ll>();
		ll cost = fetch<ll>();
		if(!shield.count(b)) {
			shield[b] = cost;
		} else {
			shield[b] = min(shield[b], cost);
		}
	}
	for(int i = 0; i < p; ++i) {
		cin >> mstr[i].x >> mstr[i].y >> mstr[i].z;
		open[mstr[i].x+1].emplace_back(i);
	}
	ll answ = -LL_INF;
	for(int i = 0; i < MAXN; ++i) {
		if(shield.count(i)) {
			add(i, i, -shield[i]);
		} else {
			add(i, i, -LL_INF);
		}
	}
	ll last = 0;
	for(int i = 0; i < MAXN; ++i) {
		for(auto& id: open[i]) {
			//cout << "@open: " << id + 1 << '\n';
			add(mstr[id].y + 1, MAXN - 1, mstr[id].z);
		}
		if(!weapon.count(i)) continue;
		add(0, MAXN - 1, last);
		add(0, MAXN - 1, -weapon[i]);
		last = weapon[i];
		answ = max(answ, getMX());
	}
	cout << answ << '\n';
}
int main() {
	fastIO();
	solve();
	return 0;
}