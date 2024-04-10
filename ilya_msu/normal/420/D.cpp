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
#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;

struct Fenvick {
	int n;
	vector<int> a;
	Fenvick(int nn) {
		n = nn;
		a.assign(n, 0);
	}
	void inc(int pos, int d) {
		for (; pos < n; pos = pos | (pos + 1))
			a[pos] += d;
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
};

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n + m, 0);
	for (int i = m; i < m + n; ++i)
		a[i] = i - m + 1;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i)
		scanf("%d %d", &x[i], &y[i]);
	vector<int> p(n, -1);
	Fenvick t(n + m + 5);
	for (int i = m; i < m + n; ++i)
		t.inc(i, 1);
	for (int i = 0; i < m; ++i) {
		int l = -1, r = n + m;
		while(r - l > 1) {
			int mid = (r + l) / 2;
			int s = t.sum(0, mid);
			if (s >= y[i])
				r = mid;
			else
				l = mid;
		}
		int pos = a[r] - 1;
		if (p[pos] == -1)
			p[pos] = x[i];
		else {
			if (p[pos] != x[i]) {
				cout << -1 << endl;
				return 0;
			}
		}
		a[m - i - 1] = a[r];
		a[r] = 0;
		t.inc(r, -1);
		t.inc(m - i - 1, 1);
	}
	vector<int> used(n, 0);
	for (int i = 0; i < n; ++i)
		if (p[i] != -1)
			used[p[i] - 1]++;
	for (int i = 0; i < n; ++i)
		if (used[i] > 1) {
			cout << -1 << endl;
			return 0;
		}
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] != -1)
			continue;
		while(used[j])
			++j;
		p[i] = j + 1;
		used[j] = 1;
	}
    for (int i = 0; i < n; ++i)
		printf("%d ", p[i]);
	cout << endl;
    return 0;
}