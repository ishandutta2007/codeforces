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
const int mod = 1051131;
const ll N = 300100;


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

vector<int> count(vector<int>& a, int sz, ll p, ll q, ll t) {
	if (sz == 0) {
		return vector<int> (1, (power(p + q, t) * a[0]) % mod);
	}
	int n = (1 << sz);
	//vector<int> aa(1 << (sz - 1));
	for (int i = 0; i < n / 2; ++i) {
		a[i] = (a[i] + a[i + n / 2]) % mod;
		a[i + n / 2] = (a[i] - 2 * a[i + n / 2] + mod) % mod;
		/*if (a[i] >= mod)
			a[i] -= mod;
		if (a[i + n / 2] < 0)
			a[i + n / 2] += mod;*/
	}
	//cerr << sz << endl;
	vector<int> tmp = count(a, sz - 1, (2 * p) % mod, ((1 << (sz - 1)) * p - p + q + mod) % mod, t);
	vector<int> res(1 << sz, 0);
	int mult = power((p + q + (mod - ((1 << (sz - 1)) % mod)) * p) % mod, t);
	//cerr << sz << endl;
	for (int i = 0; i < res.size() / 2; ++i) {
		res[i] = (((tmp[i] + ((a[i + n / 2] + mod) * 1ll * mult)) % mod) * 1ll * ((mod + 1) / 2)) % mod;
		res[i + res.size() / 2] = (((tmp[i] + ((mod - a[i + n / 2]) * 1ll * mult)) % mod) * 1ll * ((mod + 1) / 2)) % mod;
	}
	//cerr << sz << endl;
	return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int a1, a2, a3, b1, b2, b3;
	cin >> a1 >> a2 >> a3;
	int a = a1 + a2 + a3;
	cin >> b1 >> b2 >> b3;
	int b = b1 + b2 + b3;
	int m = (a + 4) / 5 + (b + 9) / 10;
	int n;
	cin >> n;
	if (m <= n)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}