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
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

vector<int> g[26];
int ans[26];

void dfs(int v, int id = 0, int last = -1) {
	ans[v] = id;
	for (int u : g[v]) {
		if (u != last) dfs(u, id + 1, v);
	}
}

ll check(vector<int> f, string s) {
	ll t = 0;
	for (int i = 0; i < (s.size() - 1); i++) {
		t += abs(f[s[i] - 'a'] - f[s[i + 1] - 'a']);
	}
	return t;
}

ll stupid(int n, int m, string s) {
	vector<int> f(m);
	for (int i = 0; i < m; i++) {
		f[i] = i + 1;
	}
	ll an = check(f, s);
	while (next_permutation(all(f))) {
		an = min(an, check(f, s));
	}
	return an;
}

void solve() {
	//int n, m;
	//cin >> n >> m;
	//string st;
	//cin >> st;
	//vector<pair<pair<char, char>, int>> f;
	//int num[26][26];
	//int id = 0;
	//for (int i = 0; i < m; i++) {
	//	for (int j = i + 1; j < m; j++) {
	//		f.push_back({ {'a' + i, 'a' + j}, 0 });
	//		num[i][j] = num[j][i] = id++;
	//	}
	//}
	////cout << f.size() << endl;
	//for (int i = 0; i < (n - 1); i++) {
	//	//cout << num[st[i] - 'a'][st[i + 1] - 'a'] << " " << endl;
	//	if (st[i] == st[i + 1]) continue;
	//	f[num[st[i] - 'a'][st[i + 1] - 'a']].second++;
	//}
	//sort(all(f), [](pair<pair<char, char>, int> a, pair<pair<char, char>, int> b) {
	//	return a.second > b.second;
	//});
	//int tt = 0;
	//char b;
	////cout << "lol\n";
	////cout << f.size() << endl;
	//for (auto u : f) {
	//	//cout << u.first.first << " " << u.first.second << " " << g[u.first.first - 'a'].size() << endl;
	//	if (g[u.first.first - 'a'].size() == 2) continue;
	//	if (g[u.first.second - 'a'].size() == 2) continue;
	//	if (g[u.first.second - 'a'].size() == 1 && g[u.first.first - 'a'].size() == 1) continue;
	//	//cout << tt << " " << u.first.first << " " << u.first.second << " " << u.second << endl;
	//	g[u.first.first - 'a'].push_back(u.first.second - 'a');
	//	g[u.first.second - 'a'].push_back(u.first.first - 'a');
	//	tt++;
	//}
	//for (int i = 0; i < m; i++) {
	//	if (g[i].size() == 1) {
	//		b = 'a' + i;
	//		break;
	//	}
	//}
	//dfs(b - 'a');
	//ll an = 0;
	//for (int i = 0; i < (n - 1); i++) {
	//	an += abs(ans[st[i] - 'a'] - ans[st[i + 1] - 'a']);
	//}
	//cout << an << endl;
	//cout << stupid(n, m, st) << endl;
	int q;
	cin >> q;
	while (q--) {
		int h, n;
		cin >> h >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		sort(all(p));
		p.pop_back();
		n--;
		vector<int> ed;
		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (p[i] == (p[i - 1] + 1)) cur++;
			else {
				ed.push_back(cur);
				cur = 1;
			}
		}
		ed.push_back(cur);
		int ans = 0;
		if (p[0] == 1 && ed[0] % 2 == 1) ans--;
		for (int i : ed) ans += (i % 2);
		cout << ans << endl;
	}
}