#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e18;
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

struct Line {
    Point v, p;
    Line() {}
    Line(Point v, Point p) {
        this->v = v;
        this->p = p;
    }
    Point point(double t) {
        return v + p * t;
    }
};

//
Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector AngleBisector(Point p, Vector v1, Vector v2){//
    double rad = Angle(v1, v2);
    return Rotate(v1, dcmp(Cross(v1, v2)) * 0.5 * rad);
}

//3
bool LineCoincide(Point p1, Point p2, Point p3) {
    return dcmp(Cross(p2 - p1, p3 - p1)) == 0;
}

//
bool LineParallel(Vector v, Vector w) {
    return Cross(v, w) == 0;
}

//
bool LineVertical(Vector v, Vector w) {
    return Dot(v, w) == 0;
}

//
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

//
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}

//
double DistanceToSegment(Point P, Point A, Point B) {
    if (A == B) return Length(P - A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}

//
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}

//()
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
            c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

//
bool SegmentProperIntersection2(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
            c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return max(a1.x, a2.x) >= min(b1.x, b2.x) &&
    max(b1.x, b2.x) >= min(a1.x, a2.x) &&
    max(a1.y, a2.y) >= min(b1.y, b2.y) &&
    max(b1.y, b2.y) >= min(a1.y, a2.y) &&
    dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}

//, 
bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

//n
double PolygonArea(Point *p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; i++)
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}

//
int isPointInPolygon(Point o, Point *p, int n) {
    int wn = 0;
    for (int i = 0; i < n; i++) {
        if (OnSegment(o, p[i], p[(i + 1) % n])) return -1;
        int k = dcmp(Cross(p[(i + 1) % n] - p[i], o - p[i]));
        int d1 = dcmp(p[i].y - o.y);
        int d2 = dcmp(p[(i + 1) % n].y - o.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;
    return 0;
}

//
int ConvexHull(Point *p, int n, Point *ch) {
    sort(p, p + n);
    int m = 0;
    //<,
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}

const int N = 100005;

int n;
Point p, a[N];

int main() {
    scanf("%d", &n);
    p.read();
    double Max = -INF, Min = INF;
    for (int i = 0; i < n; i++) {
        a[i].read();
        Max = max(Length(a[i] - p), Max);
    }
    for (int i = 1; i <= n; i++) {
        double tmp = DistanceToSegment(p, a[i - 1], a[i % n]);
        Min = min(tmp, Min);
    }
    printf("%.12f\n", (Max * Max - Min * Min) * pi);
    return 0;
}