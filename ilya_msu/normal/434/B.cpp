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

int solve(const vector<int>& a, int ind) {
	int n = a.size();
	vector<pii> r, l;
	r.push_back(pii(a[ind], ind));
	l.push_back(pii(a[ind], ind));
	for (int i = ind + 1; i < n; ++i) {
		if (a[i] < r.back().first)
			r.push_back(pii(a[i], i));
		else {
			r.back().second = i;
		}
	}
	for (int i = ind - 1; i >= 0; --i) {
		if (a[i] < l.back().first)
			l.push_back(pii(a[i], i));
		else {
			l.back().second = i;
		}
	}
	int j = 0;
	int res = 0;
	for (int i = 0; i < l.size(); ++i) {
		while ((j + 1 < r.size()) && (r[j + 1].first >= l[i].first))
			++j;
		res = max(res, l[i].first * (r[j].second - l[i].second + 1));
	}
	j = 0;
	for (int i = 0; i < r.size(); ++i) {
		while ((j + 1 < l.size()) && (l[j + 1].first >= r[i].first))
			++j;
		res = max(res, r[i].first * (r[i].second - l[j].second + 1));
	}
	return res;
}

int brute(const vector<int>& a, int ind) {
	int res = 0;
	for (int i = 0; i <= ind; ++i) {
		for (int j = ind; j < a.size(); ++j) {
			int h = a[ind];
			for (int k = i; k <= j; ++k)
				h = min(h, a[k]);
			res = max(res, h * (j - i + 1));
		}
	}
	return res;
}

void testSolve() {
	while(true) {
	int n = 10;
	int ind = rand() % 5;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 10;
	if (brute(a, ind) != solve(a, ind)) {
		cerr << "!!!!\n";
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << ind << endl;
		cout << brute(a, ind) << endl;
		cout << solve(a, ind) << endl;
		return;
	}
	else
		cerr << "OK\n";
	}

}


int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//testSolve();
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	vector<vector<int> > a(n, vector<int> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	vector<vector<int> > right(n, vector<int> (m, 0));
	vector<vector<int> > left(n, vector<int> (m, 0));
	vector<vector<int> > up(n, vector<int> (m, 0));
	vector<vector<int> > down(n, vector<int> (m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0)
				continue;
			left[i][j] = 1;
			if (j > 0)
				left[i][j] += left[i][j - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (a[i][j] == 0)
				continue;
			right[i][j] = 1;
			if (j + 1 < m)
				right[i][j] += right[i][j + 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0)
				continue;
			up[i][j] = 1;
			if (i > 0)
				up[i][j] += up[i - 1][j];
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (a[i][j] == 0)
				continue;
			down[i][j] = 1;
			if (i + 1 < n)
				down[i][j] += down[i + 1][j];
		}
	}
	for (int qq = 0; qq < q; ++qq) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		--x, --y;
		if (op == 1) {
			a[x][y] = 1 - a[x][y];
			for (int j = 0; j < m; ++j) {
				if (a[x][j] == 0) {
					left[x][j] = 0;
					continue;
				}
				left[x][j] = 1;
				if (j > 0)
					left[x][j] += left[x][j - 1];
			}
			for (int j = m - 1; j >= 0; --j) {
				if (a[x][j] == 0) {
					right[x][j] = 0;
					continue;
				}
				right[x][j] = 1;
				if (j + 1 < m)
					right[x][j] += right[x][j + 1];
			}
			for (int i = 0; i < n; ++i) {
				if (a[i][y] == 0) {
					up[i][y] = 0;
					continue;
				}
				up[i][y] = 1;
				if (i > 0)
					up[i][y] += up[i - 1][y];
			}
			for (int i = n - 1; i >= 0; --i) {
				if (a[i][y] == 0) {
					down[i][y] = 0;
					continue;
				}
				down[i][y] = 1;
				if (i + 1 < n)
					down[i][y] += down[i + 1][y];
			}
		}
		else {
			int res = 0;
			vector<int> r(n);
			for (int i = 0; i < n; ++i)
				r[i] = right[i][y];
			res = max(res, solve(r, x));
			for (int i = 0; i < n; ++i)
				r[i] = left[i][y];
			res = max(res, solve(r, x));
			vector<int> u(m);
			for (int i = 0; i < m; ++i)
				u[i] = up[x][i];
			res = max(res, solve(u, y));
			for (int i = 0; i < m; ++i)
				u[i] = down[x][i];
			res = max(res, solve(u, y));
			printf("%d\n", res);
		}
	}


    return 0;
}