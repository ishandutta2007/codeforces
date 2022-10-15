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
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;


ll power(ll a, int n) {
	ll res = 1;
	while(n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	return res;
}


ll c(ll n, ll k) {
	ll res = 1;
	for (int i = 0; i < k; ++i)
		res = (res * (n - i)) % mod;
	ll x = 1;
	for (int i = 1; i < k + 1; ++i)
		x = (x * i) % mod;
	return (res * power(x, mod - 2)) % mod;
}

ll count(int n, int k) {
	
	int d = 2;
	vector<int> a;
	while(n > 1) {
		int c = 0;
		while (n % d == 0) {
			n /= d;
			++c;
		}
		if (c)
			a.push_back(c);
		++d;
	}
	ll res = 1;
	for (int i = 0; i < a.size(); ++i) {
		res = (res * c(a[i] + k - 1, a[i])) % mod;

	}
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res = (res + count(i, k)) % mod;
	}
	cout << res << endl;
	

    return 0;
}