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
const ll mod1 = 998244353;
const ll mod2 = 777777773;
const ll P1 = 239;
const ll P2 = 241;

mt19937 mrand(random_device{} ());


signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	

	vector<ll> p1(1e6 + 1, 1);
	vector<ll> p2(1e6 + 1, 1);
	for (int i = 1; i <= 1e6; i++) {
		p1[i] = (p1[i - 1] * P1) % mod1;
		p2[i] = (p2[i - 1] * P2) % mod2;
	}
	int n;
	cin >> n;
	string ans;
	cin >> ans;
	for (int i = 1; i < n; i++) {
		string st;
		cin >> st;
		pair<ll, ll> h1 = { 0, 0 };
		pair<ll, ll> h2 = { 0, 0 };
		ll mm = 0;
		for (int i = 0; i < (int)size(st); i++) {
			if ((int)size(ans) - 1 - i < 0) break;
			h1 = { (h1.first * P1 + ans[(int)size(ans) - 1 - i] - '0' + 1) % mod1,
				(h1.second * P2 + ans[(int)size(ans) - 1 - i] - '0' + 1) % mod2 };
			h2 = { (h2.first + (st[i] - '0' + 1) * p1[i]) % mod1,
				(h2.second + (st[i] - '0' + 1) * p2[i]) % mod2 };
			if (h1 == h2) mm = i + 1;
		}
		ans += st.substr(mm, (int)size(st));
	}
	cout << ans << endl;
	return 0;
}