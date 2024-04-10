#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;

const r32 eps = 1e-2;
const r32 PI = acos(-1.0);

inline r32 sqr(const r32 &x)
{
	return x * x;
}

r32 gcd(const r32 &a, const r32 &b)
{
	return b < eps ? a : gcd(b, fmod(a, b));
}

int main()
{
	r32 x1, x2, x3;
	r32 y1, y2, y3;
	scanf("%lf%lf", &x1, &y1);
	scanf("%lf%lf", &x2, &y2);
	scanf("%lf%lf", &x3, &y3);

	r32 l1 = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
	r32 l2 = sqrt(sqr(x2 - x3) + sqr(y2 - y3));
	r32 l3 = sqrt(sqr(x3 - x1) + sqr(y3 - y1));
	r32 p = (l1 + l2 + l3) * 0.5;
	r32 w = sqrt(p * (p - l1) * (p - l2) * (p - l3));
	r32 r = l1 * l2 * l3 * 0.25 / w;

	r32 g1 = acos(1.0 - l1 * l1 * 0.5 / r / r);
	r32 g2 = acos(1.0 - l2 * l2 * 0.5 / r / r);
	r32 g3 = 2.0 * PI - g1 - g2;
	r32 g = gcd(g1, gcd(g2, g3));
	printf("%.16f\n", PI * r * r * sin(g) / g);

	return 0;
}