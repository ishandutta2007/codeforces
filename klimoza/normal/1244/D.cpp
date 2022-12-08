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

const int N = 1e5 + 7;
ll c[N][3];
vector<int> g[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i][0];
	}for (int i = 0; i < n; i++) {
		cin >> c[i][1];
	}for (int i = 0; i < n; i++) {
		cin >> c[i][2];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (g[i].size() > 2) {
		//	cout << i << endl;
			cout << -1 << endl;
			return;
		}
		if (g[i].size() == 1) {
			root = i;
		}
	}
	vector<int> ob;
	ob.push_back(root);
	root = g[root].back();
	while (true) {
		ob.push_back(root);
		if (g[root].size() == 1) break;
		if (ob[ob.size() - 2] == g[root][0]) root = g[root][1];
		else root = g[root][0];
	}
	pair<int, int> ans = { -1, -1 };
	ll maxi = 1e18;
	for (int f1 = 0; f1 < 3; f1++) {
		for (int f2 = 0; f2 < 3; f2++) {
			if (f1 == f2) continue;
			ll cur = c[ob[0]][f1] + c[ob[1]][f2];
			int col1 = f1;
			int col2 = f2;
			for (int j = 2; j < n; j++) {
				for (int k = 0; k < 3; k++) {
					if (k != col1 && k != col2) {
						cur += c[ob[j]][k];
						swap(col1, col2);
						col2 = k;
						break;
					}
				}
			}
			if (cur < maxi) {
				maxi = cur;
				ans = { f1, f2 };
			}
		}
	}
	vector<int> an(n);
	an[0] = ans.first;
	an[1] = ans.second;
	int col1 =ans.first;
	int col2 = ans.second;
	for (int j = 2; j < n; j++) {
		for (int k = 0; k < 3; k++) {
			if (k != col1 && k != col2) {
				an[j] = k;
				swap(col1, col2);
				col2 = k;
				break;
			}
		}
	}
	cout << maxi << endl;
	vector<int> pr(n);
	for (int i = 0; i < n; i++) {
		pr[ob[i]] = an[i];
	}
	for (int i : pr) cout << i + 1 << " ";
}