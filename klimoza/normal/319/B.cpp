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

const int N = 1e5 + 7;

int a[N], nxt[N];

int n;

int rec(int v, int m) {
	//if(m == 2)	cout << v << " " << c << " " << nxt[v] << endl;
	//cout <<  nxt[v] << " " << n << endl;
	for(int c=  1; c <= m; c++){
		if (nxt[v] == n || a[nxt[v]] >= a[v]) break;
		//if(m == 2)cout << v << " " << nxt[v] << " " << c << " LOL" << endl;
		nxt[v] = rec(nxt[v], c);
	}
	return nxt[v];
}

int smart(vector<int> b) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	int l = -1, r = n;
	while (r - l > 1) {
		int m = l + r >> 1;
		for (int i = 0; i < n; i++)
			nxt[i] = i + 1;
		if (m) {
			int x = 0;
			while (x != n) {
				rec(x, m);
				x = nxt[x];
			}
		}
		/*if (m == 3) {
			for (int i = 0; i < n; i++)
				cout << nxt[i] << " ";
			cout << endl;
		}*/
		bool fl = true;
		int x = 0;
		while (nxt[x] < n) {
			if (a[nxt[x]] < a[x]) {
				fl = false;
			}
			x = nxt[x];
		}
		if (fl) r = m;
		else l = m;
	}
	return r;
}

int stupid(vector<int> b) {
	int tmp = 0;
	//cout << "lol\n";
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	for (int i = 0; i < n; i++)
		nxt[i] = i + 1;
	vector<bool> del(n, false);
	while (true) {
		bool fl = false;
		for (int i = n - 1; i >= 0; i--) {
			if (del[i]) continue;
			if (nxt[i] != n && a[nxt[i]] < a[i])
				fl = true;
		}
		if (!fl)
			break;
		tmp++;
		for (int i = n - 1; i >= 0; i--) {
			if (del[i]) continue;
			if (nxt[i] != n && a[nxt[i]] < a[i]) {
				del[nxt[i]] = true;
				nxt[i] = nxt[nxt[i]];
			}
		}
		if (tmp == 2) {
			for (int i = 0; i < n; i++)
				cout << nxt[i] << " ";
			cout << endl;
		}
	}
	return tmp;
}

void stress() {
	int cnt = 0;
	while (true) {
		cnt++;
		n = rand() % 20 + 1;
		vector<int> b(n);
		for (int i = 0; i < n; i++)
			b[i] = i + 1;
		shuffle(all(b), mrand);
		/*cout << n << endl;
		for (int i : b)
			cout << i << " ";
		cout << endl;*/
		int m1 = smart(b);
		int m2 = stupid(b);
		if (m1 == m2)
			cout << "TEST# " << cnt << " OK\n";
		else {
			cout << "TEST# " << cnt << " FAILED\n";
			cout << n << endl;
			for (int i : b)
				cout << i << " ";
			cout << endl;
			cout << m1 << " " << m2 << endl;
			return;
		}
	}
}

void solve() {
	//stress(); return;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << smart(b) << endl;
	return;

}