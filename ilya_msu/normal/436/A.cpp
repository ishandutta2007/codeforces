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
const int N = 20 * 1000 + 10;
const ll MOD = 1000 * 1000 * 1000 + 7;




int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	vector<int> t(n), h(n), m(n);
	for (int i = 0; i < n; ++i)
		cin >> t[i] >> h[i] >> m[i];
	vector<int> used(n, 0);
	int res1 = 0, res2 = 0;
	int x1 = x;
	int tt = 1;
	while(true) {
		int ind = -1;
		int a = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			if (t[i] != tt)
				continue;
			if (h[i] > x1)
				continue;
			if (m[i] > a) {
				a = m[i];
				ind = i;
			}
		}
		if (ind == -1)
			break;
		used[ind] = 1;
		x1 += a;
		tt = 1 - tt;
		++res1;
	}
	tt = 0;
	int x2 = x;
	used.assign(n, 0);
	while(true) {
		int ind = -1;
		int a = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			if (t[i] != tt)
				continue;
			if (h[i] > x2)
				continue;
			if (m[i] > a) {
				a = m[i];
				ind = i;
			}
		}
		if (ind == -1)
			break;
		used[ind] = 1;
		x2 += a;
		tt = 1 - tt;
		++res2;
	}
	cout << max(res1, res2) << endl;
	
	return 0;
}