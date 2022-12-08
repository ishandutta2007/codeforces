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

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod2 = 998244353;

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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < (a - 1)) cout << "NO\n";
	else if (b == (a - 1) && (c || d)) cout << "NO\n";
	else if (b == (a - 1)) {
		cout << "YES\n";
		for (int i = 0; i < b; i++) {
			cout << "0 1 ";
		}
		cout << "0\n";
	}
	else if (c < (d - 1)) cout << "NO\n";
	else if (c == (d - 1) && (a || b)) cout << "NO\n";
	else if (c == (d - 1)) {
		cout << "YES\n";
		for (int i = 0; i < c; i++) {
			cout << "3 2 ";
		}
		cout << "3\n";
	}
	else {
		b -= a;
		c -= d;
		string s1 = "";
		for (int i = 0; i < a; i++) s1 += "0 1 ";
		string s2 = "";
		for (int i = 0; i < d; i++) s2 += "2 3 ";
		if (abs(b - c) > 1) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		if (b == c + 1) {
			s1 = "1 " + s1;
			b--;
		}
		if (c == b + 1) {
			s2 = s2 + "2";
			c--;
		}
		string s3 = "";
		for (int i = 0; i < b; i++) {
			s3 += "2 1 ";
		}
		cout << s1 + s3 + s2 << endl;
	}
	return;
}