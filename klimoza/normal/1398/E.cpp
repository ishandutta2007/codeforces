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

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

void solve() {
	int n; cin >> n;
	ll ans = 0;
	set<pair<ll, int>> curx, cury, curd;
	vector<int> tp;
	int c = 0;
	tp.resize(n);
	map<int, int> idx;
	map<int, int> idy;
	for (int i = 0; i < n; i++) {
		int t, d; cin >> t >> d;
		tp[i] = t;
		/*if (i == 3) {
			cout << "kek\n";
			cout << c << endl;
			for (auto u : curd)
				cout << u.first << " " << u.second << endl;
			for (auto u : cury)
				cout << u.first << " " << u.second << endl;
			for (auto u : curx)
				cout << u.first << " " << u.second << endl;
			cout << "kek\n";
		}*/
		if (d > 0) {
			ans += d;
			if (t == 0) {
				idx[d] = i;
				if (!curd.empty() && (*curd.begin()).first < d) {
					pair<ll, int> tt = *curd.begin();
					curd.erase(curd.begin());
					ans -= tt.first;
					if (tp[tt.second] == 0)
						curx.insert(tt);
					else {
						c--;
						cury.insert(tt);
					}
					ans += d;
					curd.insert({ d,  i });
				}
				else {
					curx.insert({ d, i });
				}
			}
			else {
				idy[d] = i;
				if (!curx.empty() && (*curx.rbegin()).first > d && (cury.empty() || (*cury.rbegin()).first < (*curx.rbegin()).first)) {
					pair<ll, int> tt = *curx.rbegin();
					curx.erase(curx.find(tt));
					ans += tt.first;
					curd.insert(tt);
					cury.insert({ d, i });
				}
				else if (!cury.empty() && (*cury.rbegin()).first > d) {
					pair<ll, int> tt = *cury.rbegin();
					cury.erase(tt);
					ans += tt.first;
					c++;
					curd.insert(tt);
					cury.insert({ d, i });
				}
				else {
					c++;
					ans += d;
					curd.insert({ d, i });
				}
			}
		}
		else {
			//cout << ans << " " << curx.size() << " " << curd.size() << endl;
			d *= -1;
			if (t == 0) {
				if (curx.find({ d, idx[d] }) != curx.end()) {
					//cout << ans << " " << d << endl;
					ans -= d;
					curx.erase(curx.find({ d, idx[d] }));
				}
				else {
					ans -= 2 * d;
					curd.erase(curd.find({ d, idx[d] }));
					pair<ll, int> f1 = { -2e10, -2e9 };
					pair<ll, int> f2 = { -2e10, -2e9 };
					if (!curx.empty()) f1 = *curx.rbegin();
					if (!cury.empty()) f2 = *cury.rbegin();
					if (f1.first == f2.first && (f1.first == -2e10)) assert(false);
					if (f1.first > f2.first) {
						curd.insert(f1);
						curx.erase(curx.find(f1));
						ans += f1.first;
					}
					else {
						curd.insert(f2);
						cury.erase(cury.find(f2));
						c++;
						ans += f2.first;
					}
				}
			}
			else {
				if (cury.find({ d, idy[d] }) != cury.end()) {
					/*if (i == 6) {
						cout << "kek\n";
						for (auto u : cury)
							cout << u.first << " " << u.second << endl;
						cout << "kek\n";
						for (auto u : curd)
							cout << u.first << " " << u.second << endl;
						cout << "kek\n";
					}*/
					ans -= d;
					cury.erase(cury.find({ d, idy[d] }));
					ans -= (*curd.begin()).first;
					pair<ll, int> tt = *curd.begin();
					if (tp[tt.second] == 0)
						curx.insert(tt);
					else if (tp[tt.second] == 1) {
						c--;
						cury.insert(tt);
					}
					curd.erase(curd.begin());
				}
				else {
					ans -= 2 * d;
					c--;
					curd.erase(curd.find({d, idy[d]}));
				}
			}
		}
		if (c && (c == curd.size())) {
			ll tmp = ans;
			tmp -= (*curd.begin()).first;
			if (!curx.empty())
				tmp += (*curx.rbegin()).first;
			cout << tmp << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return;
}