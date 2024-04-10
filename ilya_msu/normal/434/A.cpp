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

ll solve(int n, int m, const vector<ll>& a) {
	ll res = 0;
	for (int i = 1; i < m; ++i)
		res += abs(a[i] - a[i - 1]);
	vector<vector<ll> > page(n + 1);
	for (int i = 0; i < m; ++i) {
		if (i) 
			if (a[i] != a[i - 1])
				page[a[i]].push_back(a[i - 1]);
		if (i + 1 < m)
			if (a[i] != a[i + 1])
				page[a[i]].push_back(a[i + 1]);
	}
	ll ans = res;
	for (int i = 0; i < page.size(); ++i) {
		if (page[i].empty())
			continue;
		sort(page[i].begin(), page[i].end());
		ll cur = 0;
		ll sum = 0;
		ll mid = page[i][page[i].size() / 2];
		for (int j = 0; j < page[i].size(); ++j) {
			cur += abs(i - page[i][j]);
			sum += abs(mid - page[i][j]);
		}
		ans = min(ans, res - cur + sum);
	}
	return ans;
}

ll brute(int n, int m, const vector<ll>& a) {
	vector<ll> b(m);
	ll res = 0;
	for (int i = 1; i < m; ++i)
		res += abs(a[i] - a[i - 1]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < m; ++k) {
				b[k] = a[k];
				if (b[k] == i)
					b[k] = j;
			}
			ll cur = 0;
			for (int k = 1; k < m; ++k)
				cur += abs(b[k] - b[k - 1]);
			res = min(res, cur);
		}
	}
	return res;
}

void read(int& n, int& m, vector<ll>& a) {
	cin >> n >> m;
	a.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
}

void gen(int& n, int& m, vector<ll>& a) {
	n = rand() % 100 + 10;
	m = rand() % 10 + 1;
	a.resize(m);
	for (int i = 0; i < m; ++i)
		a[i] = rand() % n + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	vector<ll> a;
	read(n, m, a);
	cout << solve(n, m, a) << endl;
	
	
	
	return 0;
}