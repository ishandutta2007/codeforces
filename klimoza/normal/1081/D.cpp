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
const ld eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;

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

struct Edge {
	int v, to, w;
	Edge() {}
	Edge(int v, int to, int w) : v(v), to(to), w(w) {}
};

const int N = 1e5 + 6;

int p[N], sz[N], lol[N];
bool mem[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
		if (mem[i])
			lol[i] = 1;
		else
			lol[i] = 0;
	}
}

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

int cnt;

void merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	lol[a] += lol[b];
	p[b] = a;
	if (lol[a] == cnt)
		cnt = 1;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	fill(mem, mem + n, false);
	vector<int> x(k);
	for (int i = 0; i < k; i++) {
		cin >> x[i]; x[i]--;
		mem[x[i]] = true;
	}
	vector<Edge> ed(m);
	for (int i = 0; i < m; i++) {
		cin >> ed[i].v >> ed[i].to >> ed[i].w;
		ed[i].v--; ed[i].to--;
	}
	sort(all(ed), [](Edge a, Edge b) {return a.w < b.w; });
	cnt = k;
	build(n);
	int kek = -1;
	for (auto u : ed) {
		merge(u.v, u.to);
		if (cnt == 1) {
			kek = u.w;
			break;
		}
	}
	for (int i : x) {
		cout << kek << " ";
	}
	cout << endl;
	return;
}