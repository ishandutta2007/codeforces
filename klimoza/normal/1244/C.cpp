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

#define int long long

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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

const int N = 1e5 + 7;

int mm[N];

void solve() {
	ll n, p, w, d;
	fill(mm, mm + N, -1);
	cin >> n >> p >> w >> d;
	if (p == 0) {
		cout << 0 << " " << 0 << " " << n << endl;
		return;
	}
	ll cur = d;
	for (int i = 1; i < N; i++) {
		if (mm[cur % w] != -1) break;
		mm[cur % w] = i;
		cur += d;
	}
	if (mm[p % w] == -1) {
		cout << -1 << endl;
		return;
	}
	ll y = mm[p % w];
	if (p < y * d) {
		cout << -1 << endl;
		return;
	}
	ll x = (p - y * d) / w;
	ll g = x + y;
	ll t = min(g / (w - d), y / w);
	x += t * d;
	y -= t * w;
	if ((x + y) > n) cout << -1 << endl;
	else cout << x << " " << y << " " << n - x - y << endl;
}