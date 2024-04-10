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

 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 9;
const long double eps = 1e-10;


struct op {
	int t, l, r, m;
};

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> up(n, INF);
	vector<ll> add(n, 0);
	vector<op> oper(m);
	for (int i = 0; i < m; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		--l, --r;
		oper[i].t = t, oper[i].l = l, oper[i].r = r;
		if (t == 1) {
			int d;
			cin >> d;
			oper[i].m = d;
			for (int j = l; j <= r; ++j) {
				add[j] += d;
			}
		}
		else {
			int mm;
			cin >> mm;
			oper[i].m = mm;
			for (int j = l; j <= r; ++j) {
				up[j] = min(up[j], mm - add[j]);
			}
		}
	}
	bool ok = true;
	vector<ll> a = up;
	for (int i = 0; i < n; ++i)
		ok = ok && (abs(up[i]) <= INF);

	for (int i = 0; i < m; ++i) {
		if (oper[i].t == 1) {
			for (int j = oper[i].l; j <= oper[i].r; ++j) {
				a[j] += oper[i].m;
			}
		}
		else {
			ll res = -INF - 100;
			for (int j = oper[i].l; j <= oper[i].r; ++j) {
				res = max(res, a[j]);
			}
			ok = ok && (res == oper[i].m);
		}
	}
	if (!ok)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << up[i] << " ";
		}
		cout << "\n";
	}    
    return 0;
}