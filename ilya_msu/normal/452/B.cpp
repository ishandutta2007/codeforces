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
typedef unsigned long long ull; 

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 2 * 1000 * 1000 * 1000 + 10;
const ll LLINF = (ll)4 * 1000 * 1000 * 1000 * 1000 * 1000 * 10;
const int N = 1000 * 1000 * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 9;


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 0) {
		cout << 0 << " " << 1 << endl;
		cout << 0 << " " << m << endl;
		cout << 0 << " " << 0 << endl;
		cout << 0 << " " << m - 1 << endl;
		return 0;
	}
	if (m == 0) {
		cout << 1 << " " << 0 << endl;
		cout << n << " " << 0 << endl;
		cout << 0 << " " << 0 << endl;
		cout << n - 1 << " " << 0 << endl;
		return 0;
	}
	if (n > m) {
		double d1 = sqrt(n * n + m * m + 0.) + 2 * sqrt(n * n + (m - 1) * (m - 1) + 0.);
		double d2 = sqrt(n * n + m * m + 0.) * 2 + n;
		if (d1 > d2) {
			cout << 0 << " " << 1 << endl;
			cout << n << " " << m << endl;
			cout << 0 << " " << 0 << endl;
			cout << n << " " << m - 1 << endl;
		}
		else {
			cout << 0 << " " << 0 << endl;
			cout << n << " " << m << endl;
			cout << 0 << " " << m << endl;
			cout << n << " " << 0 << endl;
		}
	}
	else {
		double d1 = sqrt(n * n + m * m + 0.) + 2 * sqrt((n - 1) * (n - 1) + m * m + 0.);
		double d2 = sqrt(n * n + m * m + 0.) * 2 + m;
		if (d1 > d2) {
			cout << 1 << " " << 0 << endl;
			cout << n << " " << m << endl;
			cout << 0 << " " << 0 << endl;
			cout << n - 1 << " " << m << endl;
		}
		else {
			cout << 0 << " " << 0 << endl;
			cout << n << " " << m << endl;
			cout << n << " " << 0 << endl;
			cout << 0 << " " << m << endl;
		}
	}

    return 0;
}