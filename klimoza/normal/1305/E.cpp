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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
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


void solve() {
	int n, m;
	cin >> n >> m;
	int lol = 1e9 - n;
	if (m == 0) {
		for (int i = lol; i < lol + n; i++)
			cout << i << " ";
		return;
	}
	vector<int> ans(n, -1);
	int f = n;
	for (int i = 0; i < n; i++) {
		int t = i / 2;
		if (m < t) break;
		f = i + 1;
		ans[i] = i + 1;
		m -= t;	
		//cout << m << " " << i << endl;
	}
	if (m) {
		if (ans.back() != -1) {
			cout << -1 << endl;
			return;
		}
		else {
			int kek = ans[f - 1] + ans[f - 2] + 1 - 2 * m;
			ans[f] = kek;
			f++;
		}
	}
	lol = 1e9;
	for (int i = n - 1; i >= f; i--) {
		ans[i] = lol;
		lol -= ans[f - 1] + 1;
	}
	for (int i : ans)
		cout << i << " ";
	return;
}