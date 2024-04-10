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

bool pluss(int a, int b) {
	int l = 2 * b + a;
	int r = a;
	if ((l >= 0) && (r >= 0))
		return true;
	if ((l >= 0) && (r < 0))
		return l * l > 5 * r * r;
	if ((l < 0) && (r < 0))
		return false;
	return l * l < 5 * r * r;
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int n = max(s1.size(), s2.size());
	while(s1.size() < n)
		s1 += '0';
	while(s2.size() < n)
		s2 += '0';
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int a, b;
	a = b = 0;
	for (int i = 0; i < n; ++i) {
		a = a + b;
		b = a - b;
		
		if (s1[i] > s2[i]) {
			b += 1;
		}
		if (s1[i] < s2[i]) {
			b -= 1;
		}
		if (pluss(a - 1, b)) {
			cout << ">\n";
			return;
		}
		if (pluss(-a - 1, -b)) {
			cout << "<\n";
			return;
		}
		
	}
	if ((a == 0) && (b == 0)) {
		cout << "=\n";
		return;
	}
	if (pluss(a, b)) {
		cout << ">\n";
		return;
	}
	cout << "<\n";
	return;
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