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
#include<functional>




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
const ll N = 1001;
//const int M = 10000000;

bool isPr(int n) {
	for (int d = 2; d * d <= n; ++d) {
		if (n % d == 0)
			return false;
	}
	return true;
}

ll power(ll a, ll n, ll mod) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	return res;
}

void solve() {
	ll n;
	cin >> n;
	if (n < 4) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << "\n";
		}
		return;
	}
	if (n == 4) {
		cout << "YES\n1\n3\n2\n4\n";
		return;
	}
	if (!isPr(n)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << "1\n";
	for (ll i = 1; i < n - 1; ++i) {
		cout << ((i + 1) * power(i, n - 2, n)) % n << "\n";
		
	}
	cout << n << endl;
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}