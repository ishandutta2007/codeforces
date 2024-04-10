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

ll mod = 1000000007;
ll power(ll n, int p) {
	ll res = 1;
	while (p) {
		if (p & 1)
			res = (res * n) % mod;
		n = (n * n) % mod;
		p /= 2;
	}
	return res;
}
ll c[10][10];
void init() {
	c[0][0] = 1;
	for (int i = 1; i < 10; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}
map<pii, ll> ma;

ll get(int m, int n) {
	if (m == 0)
		return 1;
	if (m == 1)
		return n;
	if (ma.find(make_pair(m, n)) != ma.end())
		return ma[make_pair(m, n)];
	ll res = 0;
	for (int i = 1; i <= m; ++i) {
		res += power(n, i) * get(m - i, i) * c[m][i];
	}
	ma[make_pair(m, n)] = res;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, k;
	cin >> n >> k;
	ll res1 = 0;
	for (int i = 1; i < k; ++i) {
		res1 += get(k - i - 1, i) * c[k - 1][i];
	}
	if (k == 1)
		res1 = 1;
	res1 = (res1 * k) % mod;
	res1 = (res1 * power(n - k, n - k)) % mod;
	cout << res1 << endl;

	return 0;
}