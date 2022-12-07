#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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

const double eps = 1e-12;
const double PI = acos(-1.0);

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
double angle(Vector v) {return atan2(v.y, v.x);}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}

Vector AngleBisector(Point p, Vector v1, Vector v2){//
    double rad = Angle(v1, v2);
    return Rotate(v1, dcmp(Cross(v1, v2)) * 0.5 * rad);
}

//x(0<=X<180)
double RealAngleWithX(Vector a){
    Vector b(1, 0);
    if (dcmp(Cross(a, b)) == 0) return 0.0;
    else if (dcmp(Dot(a, b) == 0)) return 90.0;
    double rad = Angle(a, b);
    rad = (rad / PI) * 180.0;
    if (dcmp(a.y) < 0) rad = 180.0 - rad;
    return rad;
}

struct Circle {
    Point c;
    double r;
    void read() {
        c.read();
        scanf("%lf", &r);
    }
    Circle() {}
    Circle(Point c, double r) {
        this->c = c;
        this->r = r;
    }
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }

    void put() {
        printf("%f %f %f\n", c.x, c.y, r);
    }
} sb;

//
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point> &sol) {
   // C1.put(); C2.put();
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0) {
        if (dcmp(C1.r - C2.r) == 0) return -1; // 
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
    sol.push_back(p1);
    if(p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

const int N = 100005;
int n;
Circle c[N];
Point o;
double v, t, r;

struct ST {
    double v;
    int f;
    ST() {}
    ST(double v, int f) : v(v), f(f) {}
    bool operator < (const ST& c)const {
        if (dcmp(v - c.v) == 0) return f > c.f;
        return v < c.v;
    }
} st[N * 4];

int tot;

bool f1() {
    for (int i= 0; i < n; i++) {
        if (dcmp(Length(c[i].c - sb.c) - c[i].r) <= 0) return true;
    }
    return false;
}

int main() {
    o.read(); scanf("%lf%lf", &v, &t);
    r = v * t;
    sb = Circle(o, r);
    scanf("%d", &n);
    vector<Point> tmp;
    for (int i = 0; i < n; i++) c[i].read();
    if (f1()) {
        printf("%.12f\n", 1.0);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        tmp.clear();
        double aa = Length(c[i].c - sb.c);
        double bb = sqrt(aa * aa - c[i].r * c[i].r);
        double r1, r2;
        if (dcmp(r - bb) >= 0) {
            r1 = r2 = atan2((c[i].c - sb.c).y, (c[i].c - sb.c).x);
            double du = asin(c[i].r / aa);
            r1 -= du; r2 += du;
        } else {
            getCircleCircleIntersection(sb, c[i], tmp);
            if (tmp.size() != 2) continue;
            Point a = tmp[0];
            Point b = tmp[1];
            r1 = atan2((a - o).y, (a - o).x);
            r2 = atan2((b - o).y, (b - o).x);
        }
        if (dcmp(r1 - (-PI)) <= 0) r1 += 2 * PI;
        if (dcmp(r2 - (PI)) > 0) r2 -= 2 * PI;
        if (dcmp(r1 - r2) > 0) swap(r1, r2);
        if (dcmp(r2 - r1 - PI) >= 0) {
            st[tot++] = ST(-PI, 1);
            st[tot++] = ST(r1, -1);
            st[tot++] = ST(r2, 1);
            st[tot++] = ST(PI, -1);
        } else {
            st[tot++] = ST(r1, 1);
            st[tot++] = ST(r2, -1);
        }
    }
    sort(st, st + tot);
    int cc = 0;
    double pre;
    double sum = 0;
    for (int i = 0; i < tot; i++) {
        if (cc == 0 && st[i].f == 1) pre = st[i].v;
        if (cc == 1 && st[i].f == -1) sum += st[i].v - pre;
        cc += st[i].f;
    }
    printf("%.12f\n", sum / 2 / PI);
    return 0;
}