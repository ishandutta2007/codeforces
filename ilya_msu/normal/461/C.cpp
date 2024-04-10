#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;

struct Fenwick {
	int n;
	vector<int> a;
	Fenwick(int nn) {
		n = nn;
		a.assign(n, 0);
	}
	int sum(int r) {
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += a[r];
		return res;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	void inc(int pos, int d) {
		for (; pos < n; pos = pos | (pos + 1))
			a[pos] += d;
	}
};

void print(Fenwick tr) {
	
	for (int i = 0; i < tr.n; ++i)
		cout << tr.sum(i, i) << " ";
	cout << endl;
}

void solve() {
	int n, q;
	cin >> n >> q;
	Fenwick tr(n);
	for (int i = 0; i < n; ++i)
		tr.inc(i, 1);
	//print(tr);
	int sh = 0;
	bool rev = false;
	int sz = n;
	for (int qq = 0; qq < q; ++qq) {
		int t;
		cin >> t;
		if (t == 1) {
			int p;
			cin >> p;
			
			if (2 * p <= sz) {
				if (!rev) {
					for (int i = 0; i < p; ++i) {
						tr.inc(sh + p + i, tr.sum(sh - i + p - 1, sh - i + p - 1));
					}
					//print(tr);
					for (int i = sh; i < sh + p; ++i) {
						tr.inc(i, -tr.sum(i, i));
					}
					//print(tr);
					sh += p;
				}
				else {
					for (int i = 0; i < p; ++i) {
						tr.inc(sh + sz - 1 - p - i, tr.sum(sh + sz - 1 - p + i + 1, sh + sz - 1 - p + i + 1));
					}
					//print(tr);
					for (int i = 0; i < p; ++i) {
						tr.inc(i + sh + sz - 1 - p + 1, -tr.sum(i + sh + sz - 1 - p + 1, i + sh + sz - 1 - p + 1));
					}
					//print(tr);
				}
				sz -= p;
			} else {
				p = sz - p;
				rev = !rev;
				if (!rev) {
					for (int i = 0; i < p; ++i) {
						tr.inc(sh + p + i, tr.sum(sh - i + p - 1, sh - i + p - 1));
					}
					//print(tr);
					for (int i = sh; i < sh + p; ++i) {
						tr.inc(i, -tr.sum(i, i));
					}
					//print(tr);
					sh += p;
				}
				else {
					for (int i = 0; i < p; ++i) {
						tr.inc(sh + sz - 1 - p - i, tr.sum(sh + sz - 1 - p + i + 1, sh + sz - 1 - p + i + 1));
					}
					//print(tr);
					for (int i = 0; i < p; ++i) {
						tr.inc(i + sh + sz - 1 - p + 1, -tr.sum(i + sh + sz - 1 - p + 1, i + sh + sz - 1 - p + 1));
					}
					//print(tr);
				}
				sz -= p;

			}
		}
		else {
			int l, r;
			cin >> l >> r;
			if (!rev)
				cout << tr.sum(sh + l, sh + r - 1) << "\n";
			else 
				cout << tr.sum(sh + sz - r, sh + sz - l - 1) << "\n";
		}
	}
}

//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	solve();
	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}