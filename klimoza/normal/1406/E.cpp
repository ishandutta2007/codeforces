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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e5 + 1;

bool pr[N];

bool del[N];

void solve() {
	fill(pr, pr + N, true);
	fill(del, del + N, false);
	int n; cin >> n;
	int cnt = 0;
	vector<int> kek;
	for (int i = 2; i <= n; i++) {
		if (pr[i]) {
			for (ll j = i * 1ll* i; j <= n; j += i) {
				pr[j] = false;
			}
			cnt++;
			kek.push_back(i);
		}
	}
	int K = sqrt(cnt);
	int tot = n;
	vector<int> mem;
	bool fnd = false;
	int id = -1;
	for (int i = 0; i < cnt; i++) {
		if (!fnd && (i % K) == 0 && i) {
			cout << "A " << 1 << endl;
			int x; cin >> x;
			if (x != tot) {
				id = i;
				fnd = true;
			}
		}
		int tt = 0;
		for (ll j = kek[i]; j <= n; j += kek[i]) {
			if (!del[j]) {
				tt++;
				tot--;
			}
			del[j] = true;
		}
		cout << "B " << kek[i] << endl;
		int x; cin >> x;
		if (x != tt)
			mem.push_back(kek[i]);
	}
	if (id == -1) {
		id = cnt;
	}
	for (int i = id - K; i < id; i++) {
		cout << "A " << kek[i] << endl;
		int x; cin >> x;
		if (x) {
			mem.push_back(kek[i]);
			break;
		}
	}
	sort(all(kek));
	ll s = 1;
	for (ll i : mem) {
		ll x = 1;
		for (ll j = i; j <= n; j *= i) {
			cout << "A " << j << endl;
			int y; cin >> y;
			if (!y) break;
			x = j;
		}
		s *= x;
	}
	cout << "C " << s << endl;
	return;
}