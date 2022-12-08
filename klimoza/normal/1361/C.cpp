/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

const int L = 20;
const int N = 10e5 + 7;
const int K = 1 << L;

vector<pair<int, int>> g[K];

bool used[N];
int a[N], b[N];

int n;

int p[K], sz[K];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

map<pair<int, int>, vector<pair<int, int>>> mem;

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[2 * i] >> a[2 * i + 1];
	}
	int m = 2 * n;
	for(int k = L; k >= 0; k--){
		for (int i = 0; i < K; i++)
			g[i].clear();
		fill(used, used + N, false);
		mem.clear();
		build(K);
		for (int i = 0; i < m; i++)
			b[i] = a[i] & ((1 << k) - 1);
		for (int i = 0; i < m; i += 2) {
			merge(b[i], b[i + 1]);			
			g[b[i]].push_back({ b[i + 1], i / 2 });
			g[b[i + 1]].push_back({ b[i], i / 2 });
		}
		bool fl = true;
		for (int i = 0; i < K; i++) {
			if ((int)(g[i].size()) & 1) {
				fl = false;
				break;
			}
		}
		int kek = -1;
		for (int i = 0; i < K; i ++ ) {
			if (!g[i].empty()) {
				if (kek == -1) kek = get_par(i);
				else if (kek != get_par(i)) {
					fl = false;
					break;
				}
			}
		}
		if (!fl) continue;
		for (int i = 0; i < m; i += 2) {
			mem[{b[i], b[i + 1]}].push_back({ i, i + 1 });
			mem[{b[i + 1], b[i]}].push_back({ i + 1, i });
		}
		stack<int> s;
		vector<int> ans;
		for (int i = 0; i < K; i++) {
			if (!g[i].empty()) {
				s.push(i);
				break;
			}
		}
		while (!s.empty()) {
			int v = s.top();
			while (!g[v].empty() && used[g[v].back().second])
				g[v].pop_back();
			if (g[v].empty()) {
				ans.push_back(v);
				s.pop();
			}
			else {
				used[g[v].back().second] = true;
				s.push(g[v].back().first);
			}
		}
		cout << k << endl;
		vector<int> ansa;
		for (int i = 0; i < (ans.size() - 1); i++) {
			int v = ans[i], u = ans[i + 1];
			ansa.push_back({ mem[{v, u}].back().first });
			ansa.push_back({ mem[{v, u}].back().second });
			mem[{v, u}].pop_back();
			mem[{u, v}].pop_back();
		}
		for (int i : ansa)
			cout << i + 1 << " ";
		break;
	}
	return;
}