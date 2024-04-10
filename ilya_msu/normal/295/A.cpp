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
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 300;

struct oper {
	ll l, r, d;
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n), dif(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dif[0] = a[0];
	for (int i = 1; i < n; ++i)
		dif[i] = a[i] - a[i - 1];
	vector<oper> op(m);
	for (int i = 0; i < m; ++i) {
		cin >> op[i].l >> op[i].r >> op[i].d;
		--op[i].l;
		--op[i].r;
	}
	vector<ll> opcount(m, 0);
	int x, y;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		--x;
		--y;
		++opcount[x];
		if (y + 1 < m)
			--opcount[y + 1];
	}
	for (int i = 1; i < m; ++i)
		opcount[i] = opcount[i] + opcount[i - 1];
	for (int i = 0; i < m; ++i) {
		dif[op[i].l] += op[i].d * opcount[i];
		if (op[i].r + 1 < n)
			dif[op[i].r + 1] -= op[i].d * opcount[i];
	}
	a[0] = dif[0];
	for (int i = 1; i < n; ++i) {
		a[i] = a[i - 1] + dif[i];
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}