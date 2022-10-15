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
const int INF = 50000;
const int N = 1000 * 1000 * 1000 + 10;

struct circle {
	double x, y, r;
};

struct point {
	double x, y;
};

bool comp(circle a, circle b) {
	return a.r < b.r;
}

int inter(circle a, circle b, point& p1, point& p2) {
	if (a.r > b.r)
		swap(a, b);
	double x0 = b.x - a.x;
	double y0 = b.y - a.y;
	double aa = 2 * x0;
	double bb = 2 * y0;
	double c = b.r * b.r - a.r * a.r - x0 * x0 - y0 * y0;
	if (abs(bb) < eps) {
		p1.x = p2.x = -c / aa;
		p1.y = sqrt(a.r * a.r - p1.x * p1.x);
		p2.y = -sqrt(a.r * a.r - p1.x * p1.x);
		p1.x += a.x;
		p2.x += a.x;
		p1.y += a.y;
		p2.y += a.y;
		return 1;
	}
	double k = -aa / bb;
	double d = -c / bb;
	double D = k * d * k * d - (k * k + 1) * (d * d - a.r * a.r);
	if (D < 0)
		return -1;
	p1.x = (-k * d + sqrt(D)) / (k * k + 1);
	p2.x = (-k * d - sqrt(D)) / (k * k + 1);
	p1.y = k * p1.x + d;
	p2.y = k * p2.x + d;
	p1.x += a.x;
	p2.x += a.x;
	p1.y += a.y;
	p2.y += a.y;
	return 1;
}

double dist(point p, circle c) {
	return sqrt((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y));
}

double dist(circle p, circle c) {
	return sqrt((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y));
}


circle apol(circle a, circle b) {
	circle res;
	if (a.r < b.r)
		swap(a, b);
	res.x = a.x + a.r * a.r / (a.r * a.r - b.r * b.r) * (b.x - a.x);
	res.y = a.y + a.r * a.r / (a.r * a.r - b.r * b.r) * (b.y - a.y);
	res.r = a.r * b.r * dist(a, b) / (a.r * a.r - b.r * b.r);
	return res;
}


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<circle> a(3);
	for (int i = 0; i < 3; ++i)
		cin >> a[i].x >> a[i].y >> a[i].r;
	sort(a.begin(), a.end(), comp);
	if (a[0].r + 0.5 > a[2].r) {
		double aa = dist(a[0], a[1]);
		double bb = dist(a[2], a[1]);
		double cc = dist(a[0], a[2]);
		double cosa = (cc * cc + bb * bb - aa * aa) / (2.0 * bb * cc);
		double cosb = (cc * cc - bb * bb + aa * aa) / (2.0 * aa * cc);
		double cosc = (-cc * cc + bb * bb + aa * aa) / (2.0 * bb * aa);
		double s = aa * cosa + bb * cosb + cc * cosc;
		printf("%0.10f %0.10f\n", (a[0].x * bb * cosb + a[1].x * cc * cosc + a[2].x * aa * cosa) / s, (a[0].y * bb * cosb + a[1].y * cc * cosc + a[2].y * aa * cosa) / s);
		return 0;
	}
	circle c1 = apol(a[0], a[2]);
	circle c2;
	if (a[1].r > a[0].r + 0.5)
		c2 = apol(a[0], a[1]);
	else
		c2 = apol(a[1], a[2]);
	point p1, p2;
	if (inter(c1, c2, p1, p2) == -1)
		return 0;
	double a11 = asin(a[0].r / dist(p1, a[0]));
	double a12 = asin(a[1].r / dist(p1, a[1]));
	double a13 = asin(a[2].r / dist(p1, a[2]));
	double a1 = -1;
	if ((abs(a11 - a12) < eps) && (abs(a11 - a13) < eps))
		a1 = a11;
	double a21 = asin(a[0].r / dist(p2, a[0]));
	double a22 = asin(a[1].r / dist(p2, a[1]));
	double a23 = asin(a[2].r / dist(p2, a[2]));
	double a2 = -1;
	if ((abs(a21 - a22) < eps) && (abs(a21 - a23) < eps))
		a2 = a21;
	if (a2 > a1)
		printf("%0.10f %0.10f\n", p2.x, p2.y);
	else
		printf("%0.10f %0.10f\n", p1.x, p1.y);
	return 0;
}