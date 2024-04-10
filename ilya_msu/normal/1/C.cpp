#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const double eps = 1e-12;
struct point {
	double x, y;
	point(double a, double b) :x(a), y(b) {}
	point() {}
};

struct line {
	double a, b, c;
};

line midPer(point a, point b) {
	line res;
	res.a = a.x - b.x;
	res.b = -b.y + a.y;
	res.c = -(res.a * (a.x + b.x) / 2 + res.b * (a.y + b.y) / 2);
	return res;
}

point intersection(line l1, line l2) {
	double det = l1.a * l2.b - l1.b * l2.a;
	double det1 = -l1.c * l2.b + l1.b * l2.c;
	double det2 = -l1.a * l2.c + l1.c * l2.a;
	point res(det1 / det, det2 / det);
	return res;
}

double getDist(point x, point y) {
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

bool isInt(double x) {
	int a = x;
	return ((x - a < 0.0001) || (x - a > 1 - 0.0001));	
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	point p1, p2, p3;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	point center = intersection(midPer(p1, p2), midPer(p1, p3));
	double R = getDist(center, p1);
	double d1 = getDist(p1, p2);
	double a1 = acos(1.0 + eps - d1 * d1 / 2 / R / R);
	double d2 = getDist(p1, p3);
	double a2 = acos(1.0 + eps - d2 * d2 / 2 / R / R);
	double d3 = getDist(p3, p2);
	double a3 = acos(1.0 + eps - d3 * d3 / 2 / R / R);
	int n = 3;
	while (true) {
		if ((isInt(a1 / 2 / PI * n)) && (isInt(a2 / 2 / PI * n)) && (isInt(a3 / 2 / PI * n)))
			break;
		++n;
	}
	double s = sin(2 * PI / n) * R * R * n / 2;
	printf("%0.10f\n", s);
	return 0;
}