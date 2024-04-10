#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TVec {
	double x, y, z;
	static TVec MakeVec(double x, double y, double z) {
		TVec res;
		res.x = x;
		res.y = y;
		res.z = z;
		return res;
	}
	double norm() const {
		return x*x + y*y + z*z;
	}
	TVec operator-(const TVec& p) const {
		return MakeVec(x - p.x, y - p.y, z - p.z);
	}
	TVec operator+(const TVec& p) const {
		return MakeVec(x + p.x, y + p.y, z + p.z);
	}
	double operator*(const TVec& p) const {
		return x*p.x + y*p.y + z*p.z;
	}
	TVec operator%(const TVec& p) const {
		return MakeVec(y * p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	double abs() const {
		return sqrt(norm());
	}
	TVec operator*(double p) const {
		return MakeVec(x*p, y*p, z*p);
	}
};

TVec operator*(double p1, const TVec& p2) {
	return p2*p1;
}

TVec readVec() {
	TVec res;
	scanf("%lf%lf%lf", &res.x, &res.y, &res.z);
	return res;
}

TVec A, v;
double R;

double getTime(const TVec& O, double r) {
	double Y = ((O - A) % v).abs() / v.abs();
	if (Y < r + R + 1e-9) {
		double X = ((O - A) * v) / v.abs();
		if (X > 0) {
			return (X - sqrt((r+R)*(r+R) - Y*Y)) / v.abs();
		}
	}
	return 1e+30;
}

int main(void) {
	A = readVec();
	v = readVec();
	scanf("%lf", &R);
	double res = 1e+30;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TVec O = readVec();
		double r;
		scanf("%lf", &r);
		res = min(res, getTime(O, r));
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			TVec p = readVec();
			res = min(res, getTime(p + O, 0.0));
		}
	}
	if (res > 1e+28) {
		cout << -1 << endl;
	} else {
		printf("%.8lf\n", res);
	}
	return 0;
}