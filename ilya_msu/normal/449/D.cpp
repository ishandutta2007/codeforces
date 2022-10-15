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
		n /= 2;
	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector<int> f(1 << 20, 0);
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		++f[x];
	}
	for (int k = 0; k < 20; ++k) {
		//cerr << k << endl;
		for (int i = 0; i < f.size(); ++i) {
			if ((i >> k) & 1)
				f[i] = f[i];
			else
				f[i] = f[i] + f[i + (1 << k)];
		}
	}
	ll res = 0;
	for (int i = 0; i < (1 << 20); ++i) {
		int mask = i;
		int sign = 1;
		while(mask) {
			if (mask & 1)
				sign *= -1;
			mask /= 2;
		}
		res = (res + mod + power(2, f[i]) * sign) % mod;
	}
	cout << res << endl;
	return 0;
}