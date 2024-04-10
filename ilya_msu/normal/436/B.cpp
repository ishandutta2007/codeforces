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
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> res(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'U') {
				if ((i & 1) == 0)
					++res[j];
			}
			if (a[i][j] == 'L') {
				if (j - i >= 0)
					++res[j - i];
			}
			if (a[i][j] == 'R') {
				if (i + j < m)
					++res[j + i];
			}
		}
	}
	for (int i = 0; i < m; ++i)
		cout << res[i] << " ";
	cout << endl;

    return 0;
}