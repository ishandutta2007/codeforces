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

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

void solve() {
	string st;
	cin >> st;
	int n = st.size();
	int ch[26];
	fill(ch, ch + 26, 0);
	for (int i = 0; i < n; i++) {
		bool fl = false;
		for (int j = 0; j < (st[i] - 'a'); j++) {
			if (ch[j] > 0) {
				cout << "Ann\n";
				fl = true;
				break;
			}
		}
		if (!fl) {
			cout << "Mike\n";
		}
		ch[st[i] - 'a'] = 1;
	}
}