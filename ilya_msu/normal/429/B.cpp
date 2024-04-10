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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	vector<vector<int> > d14(n, vector<int>(m, 0));
	vector<vector<int> > d32(n, vector<int>(m, 0));
	vector<vector<int> > d23(n, vector<int>(m, 0));
	vector<vector<int> > d41(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i)
				d14[i][j] = max(d14[i][j], d14[i - 1][j]);
			if (j)
				d14[i][j] = max(d14[i][j], d14[i][j - 1]);
			d14[i][j] += a[i][j];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			if (i + 1 < n)
				d32[i][j] = max(d32[i][j], d32[i + 1][j]);
			if (j)
				d32[i][j] = max(d32[i][j], d32[i][j - 1]);
			d32[i][j] += a[i][j];
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i)
				d23[i][j] = max(d23[i][j], d23[i - 1][j]);
			if (j + 1 < m)
				d23[i][j] = max(d23[i][j], d23[i][j + 1]);
			d23[i][j] += a[i][j];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i + 1 < n)
				d41[i][j] = max(d41[i][j], d41[i + 1][j]);
			if (j + 1 < m)
				d41[i][j] = max(d41[i][j], d41[i][j + 1]);
			d41[i][j] += a[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i + 1 < n; ++i) {
		for (int j = 1; j + 1 < m; ++j) {
			int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
			x1 = d14[i - 1][j];
			x2 = d41[i + 1][j];
			x3 = d32[i][j - 1];
			x4 = d23[i][j + 1];
			res = max(res, x1 + x2 + x3 + x4);
			x1 = x2 = x3 = x4 = 0;
			x1 = d23[i - 1][j];
			x2 = d32[i + 1][j];
			x3 = d14[i][j - 1];
			x4 = d41[i][j + 1];
			res = max(res, x1 + x2 + x3 + x4);
		}
	}
	cout << res << endl;

    return 0;
}