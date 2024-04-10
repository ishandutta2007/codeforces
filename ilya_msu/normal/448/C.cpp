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

vector<int> a;

int get(int l, int r, int h) {
	int res1 = r - l;
	int m = a[l];
	for (int i = l + 1; i < r; ++i) {
		m = min(m, a[i]);
	}
	int res2 = m - h;
	int add = 0;
	int pr = l;
	while(pr < r) {
		while(pr < r) {
			if (a[pr] > m)
				break;
			++pr;
		}
		int e = pr;
		while(e < r) {
			if (a[e] <= m)
				break;
			++e;
		}
		if (e > pr)
			add += get(pr, e, m);
		pr = e;
	}
	return min(res1, res2 + add);
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << get(0, n, 0) << endl;
	return 0;
}