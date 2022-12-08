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

const int L = 30;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> ans(L);
	for (int l = 0; l < L; l++) {
		vector<int> b(n);
		for (int i = 0; i < n; i++)
			b[i] = (a[i] % (1 << (l + 1)));
		sort(all(b));
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			int l1 = max(i + 1, lower_bound(all(b), (1 << l) - b[i]) - b.begin());
			int r1 = lower_bound(all(b), (1 << (l + 1)) - b[i]) - b.begin();
			int l2 = max(i + 1, lower_bound(all(b), (1 << l) + (1 << (l + 1)) - b[i]) - b.begin());
			int r2 = n;
			cnt += (ll)max(0, r1 - l1) + (ll)max(0, r2 - l2);
		}
		cnt = cnt & 1;
		ans[l] ^= cnt;
	}
	int t = 0;
	for (int i = 0; i < L; i++) {
		t += ans[i] * (1 << i);
	}
	cout << t << endl;
	return;
}