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

mt19937 mrand(239);

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

string f = "abacaba";
int m = 7;

void solve(){
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i <= (n - m); i++) {
			if (s.substr(i, m) == f)
				cnt++;
		}
		if (cnt > 1) cout << "No\n";
		else {
			bool bl = false;
			for (int i = 0; i <= (n - m); i++) {
				bool fl = true;
				for (int j = i; j < i + m; j++) {
					if (s[j] != '?' && (s[j] != f[j - i]))
						fl = false;
				}
				if (!fl) continue;
				vector<char> tmp(n);
				for (int j = 0; j < n; j++)
					tmp[j] = s[j];
				for (int j = i; j < i + m; j++)
					tmp[j] = f[j - i];
				int tt = 0;
				for (int j = 0; j <= (n - m); j++) {
					bool cc = true;
					for (int k = j; k < j + m; k++) {
						if (tmp[k] != f[k - j])
							cc = false;
					}
					tt += cc;
				}
				if (tt == 1) {
					bl = true;
					cout << "Yes\n";
					for (char c : tmp) {
						if (c == '?') c = 'z';
						cout << c;
					}
					cout << endl;
					break;
				}
			}
			if (!bl) cout << "No\n";
		}
	}
	return;
}