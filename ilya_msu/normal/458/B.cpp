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



void solve() {
	int m, n;
	cin >> m >> n;
	vector<ll> a(m);
	vector<ll> b(n);
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll sa = 0, sb = 0;
	for (int i = 0; i < a.size(); ++i)
		sa += a[i];
	for (int i = 0; i < b.size(); ++i)
		sb += b[i];
	ll res1 = sb;
	for (int i = 0; i + 1 < a.size(); ++i)
		res1 += min(a[i], sb);
	ll res2 = sa;
	for (int i = 0; i + 1 < b.size(); ++i)
		res2 += min(b[i], sa);
	cout << min(res1, res2) << endl;
}


//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	solve();
	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}