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

bool f1(ll n, ll k, ll d1, ll d2) {
	ll x = (k - d1 - d2 - d2) / 3;
	if (x < 0)
		return false;
	ll p1 = x + d1 + d2, p2 = x + d2, p3 = x;
	if (p1 + p2 + p3 != k)
		return false;
	ll r = n - k;
	r -= d1 + d1 + d2;
	return ((r >= 0) && (r % 3 == 0));
}

bool f2(ll n, ll k, ll d1, ll d2) {
	ll x = (k - d1 - d2) / 3;
	if (x < 0)
		return false;
	ll p1 = x + d1, p2 = x, p3 = x + d2;
	if (p1 + p2 + p3 != k)
		return false;
	ll r = n - k;
	if (d1 < d2)
		swap(d1, d2);
	r -= d1 + d1 - d2;
	return ((r >= 0) && (r % 3 == 0));
}

bool f3(ll n, ll k, ll d1, ll d2) {
	ll x = (k - d1 - d1 - d2) / 3;
	if (x < 0)
		return false;
	ll p1 = x, p2 = x + d1, p3 = x + d1 + d2;
	if (p1 + p2 + p3 != k)
		return false;
	ll r = n - k;
	r -= d1 + d2 + d2;
	return ((r >= 0) && (r % 3 == 0));
}

bool f4(ll n, ll k, ll d1, ll d2) {
	if (d1 < d2)
		swap(d1, d2);
	ll x = (k - d1 - d1 + d2) / 3;
	if (x < 0)
		return false;
	ll p1 = x, p2 = x + d1, p3 = x + d1 - d2;
	if (p1 + p2 + p3 != k)
		return false;
	ll r = n - k;	
	r -= d1 + d2;
	return ((r >= 0) && (r % 3 == 0));
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		ll n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		if ((f1(n, k, d1, d2)) || (f2(n, k, d1, d2)) || (f3(n, k, d1, d2)) || (f4(n, k, d1, d2)))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}