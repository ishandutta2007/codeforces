#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (Vector A, Vector B) {
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}

Vector operator / (Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-8;

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) {return A.x * B.x + A.y * B.y;} //
double Length(Vector A) {return sqrt(Dot(A, A));} //
double Angle(Vector A, Vector B) {return acos(Dot(A, B) / Length(A) / Length(B));} //
double Cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;} //
double Area2(Point A, Point B, Point C) {return Cross(B - A, C - A);} //

Point s, t;
double v, ti;
Vector v1, v2;

bool judge(double x) {
    Point u = s;
    if (dcmp(x - ti) <= 0) {
        u = u + v1 * x;
    } else {
        u = u + v1 * ti + v2 * (x - ti);
    }
    return dcmp(Length(t - u) - v * x) <= 0;
}

int main() {
    s.read(); t.read();
    scanf("%lf%lf", &v, &ti);
    v1.read(); v2.read();
    double l = 0, r = 1e18;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;
        if (judge(mid)) r = mid;
        else l = mid;
    }
    printf("%.18f\n", l);
    return 0;
}