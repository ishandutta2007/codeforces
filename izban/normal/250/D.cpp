#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 17;
const int inf = 1000000007;


int n, m, l, r, ansa, ansb;
int a[maxn], b[maxn], c[maxn];
double ans = 1e15;

double sqr(double x) {
	return x * x;
}

double f(int i, int j) {
	double res = 0;
	res += c[i];
	res += sqrt(sqr(l) + sqr(a[j]));
	res += sqrt(sqr(r - l) + sqr(b[i] - a[j]));
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m >> l >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < m; i++)
		cin >> c[i];

	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j < n - 1 && f(i, j + 1) < f(i, j))
			j++;
		if (f(i, j) < ans)
			ansb = i + 1, ansa = j + 1, ans = f(i, j);
	}

	cout << ansa << " " << ansb << endl;

	return 0;
}