//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

vector<ll> a[3] = { {}, {}, {} };

void solve() {
	int n[3];
	cin >> n[0] >> n[1] >> n[2];
	ll st[3] = { 0, 0, 0 };
	vector<pair<ll, int>> kek;
	ll s = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n[j]; i++) {
			ll x; cin >> x;
			s += x;
			st[j] += x;
			a[j].push_back(x);
			kek.push_back(mp(x, j));
		}
	}
	sort(all(kek));
	ll ans = -inf0;
	ll mem1 = kek[0].first;
	ll mem2 = -1;
	for (int i = 1; i < kek.size(); i++) {
		if(kek[i].second != kek[0].second){
			mem2 = kek[i].first;
			break;
		}
	}
	ans = s - 2 * (mem1 + mem2);
	for (int i = 0; i < 3; i++) {
		ans = max(ans, s - 2 * st[i]);
	}
	cout << ans << endl;
	return;
}