#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e6 + 7;

int p[N], sz[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int k) {
	if (k == p[k]) return k;
	return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}

struct Item {
	int id, x, tp;
	Item() {}
	Item(int id, int x, int tp) : id(id), x(x), tp(tp) {}
};

void solve() {
	int n; cin >> n;
	build(n);
	vector<Item> f;
	vector<pair<int, int>> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		k.push_back({ a, b });
		f.push_back({ i, a, 0 });
		f.push_back({ i, b, 1 });
	}
	sort(all(f), [](Item a, Item b) {return a.x < b.x; });
	set<pair<int, int>> bg;
	for (auto u : f) {
		if (u.tp == 0) {
			bg.insert({ -u.x, u.id });
		}
		else {
			auto it = bg.begin();
			while (true) {
				if (it == bg.end()) break;
				if ((*it).first >= (-k[u.id].first)) break;
				//cout << u.id + 1 << " " << (*it).second << endl;
				if (get_par((*it).second) == get_par(u.id)) {
					cout << "NO\n";
					return;
				}
				else {
					merge((*it).second, u.id);
				}
				it++;
			}
			bg.erase({ -k[u.id].first, u.id });
		}
	}
	if (sz[get_par(0)] != n) cout << "NO\n";
	else cout << "YES\n";
	return;
}