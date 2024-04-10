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

ll get(ll k, ll m, ll n) {
	ll res = 0;
	for (ll i1 = 1; i1 <= m; ++i1) {
		res += min(n, k / i1);
	}
	return res;
}


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	ll down = 0, up = m * n;
	while(up - down > 1) {
		ll mid = (up + down) / 2;
		ll r = get(mid, m, n);
		if (r >= k)
			up = mid;
		else
			down = mid;
	}
	cout << up << endl;
	return 0;
}