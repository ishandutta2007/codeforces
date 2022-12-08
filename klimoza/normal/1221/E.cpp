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

int a, b;
int type(int l) {
	if (l < b) return 0;
	if (b <= l && l < a) return 1;
	if (a <= l && l < 2 * b) return 2;
	return 3;
}

void solve() { 
	int q; cin >> q;
	while (q--) {
		cin >> a >> b;
		string s; cin >> s;
		int cur = 0;
		int ed[4];
		fill(ed, ed + 4, 0);
		int ll = -1;
		for (char c : s) {
			if (c == 'X') {
				if (cur) ed[type(cur)]++;
				if (type(cur) == 3) ll = cur;
				cur = 0; 
			}
			else {
				cur++;
			}
		}
		if (cur) ed[type(cur)]++;
		if (type(cur) == 3) ll = cur;
		if (ed[1]) cout << "NO\n";
		else if (ed[3] > 1) cout << "NO\n";
		else if (ed[3] == 1) {
			bool fl = false;
			for (int i = 0; i <= ll - a; i++) {
				int b = ll - i - a;
				if (type(i) == 1 || type(b) == 1 || type(i) == 3 || type(b) == 3) continue;
				ed[type(i)]++;
				ed[type(b)]++;
				if (ed[2] % 2 == 0) {
					fl = true;
					break;
				}
				ed[type(i)]--;
				ed[type(b)]--;
			}
			if (fl) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if (ed[2] % 2 == 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}