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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
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

const int N = 2e5;

int sz[N], leaf[N];
vector<int> g[N], cc[N];
bool del[N];

void solve(){
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) {
			sz[i] = 0, leaf[i] = 0;
			g[i].clear(); cc[i].clear();
			del[i] = false;
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b; a--; b--;
			sz[a] ++; sz[b]++;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		set<pair<int, int>> f;
		for (int i = 0; i < n; i++) {
			for (int j : g[i]) {
				if (sz[j] == 1) {
					leaf[i]++;
					cc[i].push_back(j);
				}
			}
			f.insert({ leaf[i], i });
		}
		int ans = 0;
		while (!f.empty()) {
			auto v = *f.rbegin();
			f.erase(v);
			if (v.first < k) break;
			//cout << v.first << " " << v.second << endl;
			int x = v.second;
			if (del[x]) continue;
			sz[x] -= k;
			for (int i = 0; i < k; i++) {
				//cout << cc[i].back() << endl;
				del[cc[x].back()] = true;
				cc[x].pop_back();
			}
			//cout << "lol\n";
			ans++;
			leaf[x] -= k;
			if (sz[x] == 1) {
				for (int i : g[x]) {
					if (!del[i]) {
						f.erase({ leaf[i], i });
						leaf[i]++; cc[i].push_back(x);
						f.insert({ leaf[i], i });
					}
				}
			}
			else {
				f.insert({ leaf[x], x });
			}
		}
		cout << ans << endl;
	}
	return;
}