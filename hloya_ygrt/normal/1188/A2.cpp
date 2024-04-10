#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <random>
#include <chrono>
 

using namespace std;

 
// hloya template v26
 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

using namespace std;
 
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))
 
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
  
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);
 
template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }
 
// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
 
template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e6 + 100, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

int d[maxn];

vector<int> g[maxn];
map<pii, ll> cur;

int any_leaf;
void dfs(int v, int p) {
	if (d[v] == 1)
		any_leaf = v;
	for (auto e : g[v])
		if (e != p)
			dfs(e, v);
}

vector<int> st;

void dfs2(int v, int p, int u, int val) {
	st.pb(v);
	if (v == u) {
		for (int i = 0; i + 1 < st.size(); i++) {
			cur[minmax(st[i], st[i + 1])] += val;
		}
		st.pop_back();
		return;
	}

	for (auto e : g[v])
		if (e != p)
			dfs2(e, v, u, val);

	st.pop_back();
}

int main() {
	// files1;
	fast_io;
	int n;
	cin >> n;

	vector<tuple<int, int, int> > e;
	int mx = -inf, mn = inf;
	for (int i = 0; i + 1 < n; i++) {
		int u, v, val;
		cin >> u >> v >> val;
		u--, v--;
		upmax(mx, val);
		upmin(mn, val);
		e.eb(u, v, val);
		g[u].pb(v);
		g[v].pb(u);
		d[u]++;
		d[v]++;
	}
	vector<int> leafes;
	for (int i = 0; i < n; i++) {
		if (d[i] == 1)
			leafes.pb(i);
	}
	if (leafes.size() == 2) {
		if (mn != mx) {
			cout << "NO";
			return 0;
		}
		cout << "YES\n";
		cout << 1 << endl;
		cout << leafes[0] + 1 << ' ' << leafes[1] + 1 << ' ' << mn;
		return 0;
	}
	vector<tuple<int, int, int> > op;

	for (auto [u, v, val] : e) {
		if (val == 0) continue;
		if (d[u] >= 3 || d[v] >= 3) {
			vector<int> v_leaves, u_leaves;
			for (auto to : g[v]) {
				if (to != u) {
					dfs(to, v);
					v_leaves.pb(any_leaf);
				}
				if (v_leaves.size() == 2)
					break;
			}
			for (auto to : g[u]) {
				if (to != v) {
					dfs(to, u);
					u_leaves.pb(any_leaf);
				}
				if (u_leaves.size() == 2)
					break;
			}

			if (d[u] == 1)
				u_leaves.pb(u);
			if (d[v] == 1)
				v_leaves.pb(v);

			if (u_leaves.size() == 1)
				swap(u, v), swap(u_leaves, v_leaves);
			if (v_leaves.size() == 1) {
				op.eb(v_leaves[0], u_leaves[0], val / 2);
				op.eb(v_leaves[0], u_leaves[1], val / 2);
				op.eb(u_leaves[0], u_leaves[1], -val/2);
			} else {
				op.eb(v_leaves[0], u_leaves[0], val / 2);
				op.eb(v_leaves[1], u_leaves[1], val / 2);
				op.eb(u_leaves[0], u_leaves[1], -val/2);
				op.eb(v_leaves[0], v_leaves[1], -val/2);
			}
		}
	}

	cur.clear();
	for (auto [u, v, val] : op) {
		dfs2(u, -1, v, val);
	}

	for (auto [u, v, val] : e) {
		if (cur[minmax(u, v)] != val) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES\n";
	cout << op.size() << endl;
	for (auto [u, v, val] : op) {
		cout << u + 1 << ' ' << v + 1 << ' ' << val << endl;
	}
	return 0;
}