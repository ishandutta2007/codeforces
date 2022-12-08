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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

struct Item {
	char a, b, c;
	Item() {}
	Item(char a, char b, char c) : a(a), b(b), c(c){}
};
bool operator<(Item a, Item b) {
	return mp(mp(a.a, a.b), a.c) < mp(mp(b.a, b.b), b.c);
}

map<int, Item> to;
map<Item, int> fr;

void solve() {
	string t; cin >> t;
	int n = t.size();
	int cc = 0;
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = 'a'; b <= 'z'; b++) {
			for (char c = 'a'; c <= 'z'; c++) {
				to[cc] = Item(a, b, c);
				fr[Item(a, b, c)] = cc++;
				if (cc == n) goto kek;
			}
		}
	} kek:
	vector<Item> g(n);
	string s1 = "", s2 = "", s3 = "";
	for (int i = 0; i < n; i++) {
		s1 += to[i].a;
		s2 += to[i].b;
		s3 += to[i].c;
	}
	cout << "? " << s1 << endl;
	cin >> s1;
	cout << "? " << s2 << endl;
	cin >> s2;
	cout << "? " << s3 << endl;
	cin >> s3;
	cout << "! ";
	vector<char> ans(n);
	for (int i = 0; i < n; i++) {
		g[i] = Item(s1[i], s2[i], s3[i]);
		ans[fr[g[i]]] = t[i];
	}
	for (char c : ans)
		cout << c;
	cout << endl;
	return;
}