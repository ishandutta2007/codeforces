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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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

void solve() {
	int n; cin >> n;
	vector<pair<ll, char>> a1;
	vector<pair<ll, char>> a2;
	ll ans = 0;
	vector<ll> b;
	pair<int, char> f = { 0, 'l' };
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; char c; cin >> c;
		if (c == 'R') a1.push_back({ t, c });
		else if (c == 'B') a2.push_back({ t, c });
		else {
			cnt++;
			a1.push_back({ t, c });
			a2.push_back({ t, c });
			b.push_back(t);
		}
		f = { t, c };
	}
	for (int i = 0; i < (int)(b.size() - 1); i++) {
		int id1 = lower_bound(all(a1), make_pair(b[i], 'A')) - a1.begin();
		int id2 = lower_bound(all(a1), make_pair(b[i + 1], 'A')) - a1.begin();
		//cout << id1 << " " << id2 << endl;
		ll ans1 = 0, ans2 = 0;
		ll maxi1 = 0, maxi2 = 0;
		for (int j = id1; j < id2; j++) maxi1 = max(maxi1, a1[j + 1].first - a1[j].first);
		id1 = lower_bound(all(a2), make_pair(b[i], 'A')) - a2.begin();
		id2 = lower_bound(all(a2), make_pair(b[i + 1], 'A')) - a2.begin();
		//cout << id1 << " " << id2 << endl;
		for (int j = id1; j < id2; j++) maxi2 = max(maxi2, a2[j + 1].first - a2[j].first);
		//cout << maxi1 << " " << maxi2 << endl;
		ans1 = b[i + 1] - b[i] + (b[i + 1] - b[i] - maxi1) + (b[i + 1] - b[i] - maxi2);
		if (!maxi1 && !maxi2) ans2 = b[i + 1] - b[i];
		else ans2 = 2 * (b[i + 1] - b[i]);
	//	cout << ans1 << " loool " << ans2 << endl;
		ans += min(ans1, ans2);
	}
	for (int i = 0; i < (int)(a1.size() - 1) && a1[i].second != 'P'; i++) {
		ans += a1[i + 1].first - a1[i].first;
	}
	if(cnt)
	for (int i = (int)(a1.size() - 1); i > 0 && a1[i].second != 'P'; i--) {
		ans += a1[i].first - a1[i - 1].first;
	}
	if(cnt)
	for (int i = 0; i < (int)(a2.size() - 1) && a2[i].second != 'P'; i++) {
		ans += a2[i + 1].first - a2[i].first;
	}
	for (int i = (int)(a2.size() - 1); i > 0 && a2[i].second != 'P'; i--) {
		ans += a2[i].first - a2[i - 1].first;
	}
	cout << ans << endl;
}