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


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i][0] == 'R')
			a[i][0] = '1';
		if (a[i][0] == 'G')
			a[i][0] = '2';
		if (a[i][0] == 'B')
			a[i][0] = '3';
		if (a[i][0] == 'Y')
			a[i][0] = '4';
		if (a[i][0] == 'W')
			a[i][0] = '5';
	}
	int up = 1 << 10;
	int res = 10;
	for (int i = 0; i < up; ++i) {
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (a[j] == a[k])
					continue;
				if (a[j][0] == a[k][0]) {
					int c1 = a[j][1] - '1';
					int c2 = a[k][1] - '1';
					if ((((i >> c1) & 1) == 0) && (((i >> c2) & 1) == 0))
						ok = false;
					continue;
				}
				if (a[j][1] == a[k][1]) {
					int c1 = a[j][0] - '1' + 5;
					int c2 = a[k][0] - '1' + 5;
					if ((((i >> c1) & 1) == 0) && (((i >> c2) & 1) == 0))
						ok = false;
					continue;
				}
				int c1 = a[j][0] - '1' + 5;
				int c2 = a[k][0] - '1' + 5;
				int c3 = a[j][1] - '1';
				int c4 = a[k][1] - '1';
				if ((((i >> c1) & 1) == 0) && (((i >> c2) & 1) == 0) && (((i >> c3) & 1) == 0) && (((i >> c4) & 1) == 0))
					ok = false;
			}
		}
		if (ok) {
			int cur = 0;
			int x = i;
			while(x) {
				cur += x & 1;
				x /= 2;
			}
			res = min(res, cur);
		}
	}
	cout << res << endl;
	return 0;
}