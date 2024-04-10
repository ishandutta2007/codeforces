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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std;  
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<double> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	double res = p[0];
	double p0 = 1, p1 = 0;
	for (int i = 0; i < n; ++i) {
		double pp1 = p[i] * p0 + (1 - p[i]) * p1;
		double pp0 = p0 * (1 - p[i]);
		res = max(res, pp1);
		if (pp1 < pp0) {
			p1 = pp1;
			p0 = pp0;
		}
	}
	cout.precision(18);
	cout << res << endl;
    return 0;
}