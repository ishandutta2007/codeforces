#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	

	ll n, m, q;
	cin >> n >> m >> q;
	ll g = gcd(n, m);
	ll t1 = n / g;
	ll t2 = m / g;
	while (q--) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sy--; ey--;
		ll d1 = 0;
		if (sx == 1) d1 = sy / t1;
		else d1 = sy / t2;
		ll d2 = 0;
		if (ex == 1) d2 = ey / t1;
		else d2 = ey / t2;
		if (d1 == d2)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}