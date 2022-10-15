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
const int N = 1000000;

void solve() {
	int m, k;
	cin >> m >> k;
	vector<int> a(k);
	for (int i = 0; i < k; ++i)
		cin >> a[i];
	int f = m;
	vector<int> b(k, 0);
	int x1 = 0, x2 = 0;
	for (int i = 0; i < m - 1; ++i) {
		int t, r;
		cin >> t >> r;
		if (r)
			f = min(f, i);
		if (t == 0)
			if (f == m)
				++x1;
			else
				++x2;
		else
			if (f == m)
				--a[t - 1];
			else
				++b[t - 1];
	}
	int mi = m;
	if (f < m) {
		for (int i = 0; i < k; ++i) {
			if (b[i])
				continue;
			mi = min(mi, a[i]);
		}
		
	}
	string res = "";
	for (int i = 0; i < k; ++i) {
		int x = a[i] - b[i];
		if (f == m) {
			if (x <= x1 + x2)
				res += "Y";
			else
				res += "N";
			continue;
		}
		if (((b[i] == 0) && (a[i] <= x1)) || ((mi <= x1) && (mi + x <= x1 + x2)))
			res += "Y";
		else
			res += "N";
	}
	cout << res << "\n";

}

//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}