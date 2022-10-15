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
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	if (k > m + n - 2) {
		cout << -1 << endl;
		return 0;
	}
	ll k1 = 0, k2 = k - k1;
	if (k2 > m - 1) {
		k1 += k2 - m + 1;
		k2 = m - 1;
	}
	ll res1 = n / (k1 + 1) * (m / (k2 + 1));
	k2 = 0, k1 = k - k2;
	if (k1 > n - 1) {
		k2 += k1 - n + 1;
		k1 = n - 1;
	}
	ll res2 = n / (k1 + 1) * (m / (k2 + 1));
	cout << max(res1, res2) << endl;	
	return 0;
}