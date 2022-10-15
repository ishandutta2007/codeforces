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

vector<vector<int> > tr(vector<vector<int> >& a) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<int> > res(m, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			res[j][i] = a[i][j];
	return res;
}

int get2(const vector<vector<int> >& a, int r, int c) {
	int n = a.size(), m = a[0].size();
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			res += (a[i][j] + a[r][c] + a[i][c] + a[r][j]) & 1;
		}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	if (n > m) {
		swap(m, n);
		a = tr(a);
	}
	int res = k + 1;
	
	
	if (m > k) {
		for (int j = 0; j < m; ++j) {
			int cur = 0;
			for (int jj = 0; jj < m; ++jj) {
				int count = 0;
				for (int i = 0; i < n; ++i)
					if (a[i][j] != a[i][jj])
						++count;
				cur += min(count, n - count);
			}
			res = min(res, cur);
		}
		if (res > k) 
			cout << -1 << endl;
		else
			cout << res << endl;
		return 0;
	}
	int up = 1 << n;
	vector<int> c(n);
	for (int x = 0; x < up; ++x) {
		for (int i = 0; i < n; ++i)
			c[i] = (x >> i) & 1;
		int cur = 0;
		for (int j = 0; j < m; ++j) {
			int count = 0;
			for (int i = 0; i < n; ++i)
				if (c[i] != a[i][j])
					++count;
			cur += min(count, n - count);
		}
		res = min(res, cur);
	}
	if (res > k)
		cout << -1 << endl;
	else
		cout << res << endl;

    return 0;
}