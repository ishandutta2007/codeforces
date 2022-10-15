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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 100 * 1000 + 1;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int w, h, alpha;
	cin >> w >> h >> alpha;
	if (alpha > 90)
		alpha = 180 - alpha;
	double alpha0 = min(2 * atan((double)(h) / w), 2 * atan((double)(w) / h));
	double a = PI * alpha / 180;
	double res = 0.0;
	if (a < alpha0) {
		double a1 = 1.0 + 1.0 / cos(a), b1 = sin(a);
		double a2 = tan(a), b2 = 1.0 + cos(a);
		double c1 = w, c2 = h;
		double det = a1 * b2 - a2 * b1;
		double det1 = c1 * b2 - c2 * b1;
		double det2 = a1 * c2 - a2 * c1;
		double x = det1 / det;
		double y = det2 / det;
		res = (double)w * h - x * x * tan(a) - y * y * sin(a) * cos(a);
	}
	else {
		double x = min(h, w);
		res = x * x / sin(a);
	}
	printf("%0.10f\n", res);
	return 0;
}