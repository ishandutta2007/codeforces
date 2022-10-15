#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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



 
using namespace std; 
 
typedef long long ll; 
typedef long double ld;
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll a, ll n) {
	ll res = 1;
	while(n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

ll c(ll n, ll k) {
	if ((k < 0) || (k > n))
		return 0;
	ll res = 1;
	ll zn = 1;
	for (int i = 1; i <= k; ++i) {
		res *= (n - i + 1) % mod;
		res %= mod;
		zn = (zn * i) % mod;
	}
	return (res * power(zn, mod - 2)) % mod;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	ll res = 0;
	int n;
	ll s;
	cin >> n >> s;
	vector<ll> f(n);
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
	}
	for (int m = 0; m < (1 << n); ++m) {
		int mask = m;
		ll x = s;
		int ind = 0;
		int num = n;
		while(mask) {
			if (mask & 1) {
				x -= f[ind] + 1;
				--num;
			}
			++ind;
			mask /= 2;
		}
		if (x < 0)
			continue;
		if ((num + n) & 1)
			res = (res + mod - c(x + n - 1, n - 1)) % mod;
		else
			res = (res + c(x + n - 1, n - 1)) % mod;
	}
	cout << res << endl;
	return 0;
}