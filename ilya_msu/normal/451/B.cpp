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


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = n, r = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (a[i] > a[i + 1]) {
			l = min(l, i);
			r = max(r, i + 1);
		}
	}
	if (l > r)
		l = r = 0;
	reverse(a.begin() + l, a.begin() + r + 1);
	bool ok = true;
	for (int i = 0; i + 1 < a.size(); ++i)
		if (a[i] > a[i + 1])
			ok = false;
	if (ok) {
		cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
	}
	else
		cout << "no\n";
	return 0;
}