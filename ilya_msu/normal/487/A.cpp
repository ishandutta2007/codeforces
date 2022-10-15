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


bool win(int h1, int a1, int d1, int h2, int a2, int d2) {
	int dd1 = max(a1 - d2, 0);
	int dd2 = max(a2 - d1, 0);
	if (dd1 == 0)
		return false;
	if (dd2 == 0)
		return true;
	int n1 = (h2 + dd1 - 1) / dd1;
	int n2 = (h1 + dd2 - 1) / dd2;
	return (n1 < n2);

}

void solve() {
	int h1, a1, d1, h2, a2, d2;
	cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2;
	int h, a, d;
	cin >> h >> a >> d;
	int res = h * h2 + a * (a2 + d2) + d * d2;
	for (int i1 = 0; i1 * h <= res; ++i1) {
		for (int i2 = 0; i2 * a + i1 * h <= res; ++i2) {
			for (int i3 = 0; i3 * d + i2 * a + i1 * h <= res; ++i3) {
				if (win(h1 + i1, a1 + i2, d1 + i3, h2, a2, d2)) {
					res = i3 * d + i2 * a + i1 * h;
				}				
			}
		}
	}
	cout << res << endl;
	
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