#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct point {
    double x;
    double y;
    
    point(const double &x1 = 0, const double &y1 = 0) {
        x = x1;
        y = y1;
    }
} point;

typedef struct line {
    point p1;
    point p2;
    
    line(const point &s = point(), const point &t = point()) {
        p1 = s;
        p2 = t;
    }
} line;

double eps = 1e-8;

bool operator<(const point &a, const point &b)
{
    if (abs(a.x - b.x) > eps) return a.x < b.x;
    
    return a.y < b.y;
}

bool operator==(const point &a, const point &b)
{
    return abs(a.x - b.x) < eps && abs(a.y - b.y) < eps;
}

point operator+(const point &a, const point &b)
{
    return point(a.x + b.x, a.y + b.y);
}

point operator-(const point &a, const point &b)
{
    return point(a.x - b.x, a.y - b.y);
}

point operator*(const point &a, const double &r)
{
    return point(a.x * r, a.y * r);
}

point operator/(const point &a, const double &r)
{
    return point(a.x / r, a.y / r);
}

inline double dist(const point &p1, const point &p2)
{
    point p = p1 - p2;
    
    return sqrt(p.x * p.x + p.y * p.y);
}

inline double dist_line(const line &l, const point &p)
{
    point d = l.p2 - l.p1;
    point q = p - l.p1;
    double t = (d.x * q.x + d.y * q.y) / (d.x * d.x + d.y * d.y);
    
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    
    return dist(l.p1 + d * t, p);
}

int main()
{
    int n, x, y, i;
    double m1 = 1e18, m2 = 0, pi = acos(-1);
    point p;
    vector <point> v;
    
    scanf("%d %d %d", &n, &x, &y);
    
    p = point(x, y);
    
    for (i = 0; i < n; i++) {
        double d;
        point q;
        
        scanf("%d %d", &x, &y);
        
        q = point(x, y);
        
        v.push_back(q);
        
        d = dist(p, q);
        
        m1 = min(m1, d);
        m2 = max(m2, d);
    }
    
    for (i = 0; i < n; i++) {
        line l = line(v[i], v[(i + 1) % n]);
        
        m1 = min(m1, dist_line(l, p));
    }
    
    printf("%.12lf\n", m2 * m2 * pi - m1 * m1 * pi);
    
    return 0;
}