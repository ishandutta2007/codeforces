#include <stdio.h>
#include <math.h>

double eps = 1e-8;

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point p1;
    point p2;
} line;

point make_point(double x, double y)
{
    point p;
    
    p.x = x;
    p.y = y;
    
    return p;
}

line make_line(point p1, point p2)
{
    line l;
    
    l.p1 = p1;
    l.p2 = p2;
    
    return l;
}

double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double dist_line(line l, point p)
{
    double dx = l.p2.x - l.p1.x;
    double dy = l.p2.y - l.p1.y;
    double t = (dx * (p.x - l.p1.x) + dy * (p.y - l.p1.y)) / (dx * dx + dy * dy);
    
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    
    return dist(make_point(l.p1.x + dx * t, l.p1.y + dy * t), p);
}

double area(point p1, point p2, point p3)
{
    p1.x -= p3.x;
    p1.y -= p3.y;
    p2.x -= p3.x;
    p2.y -= p3.y;
    
    return fabs(p1.x * p2.y - p2.x * p1.y) / 2;
}

point cross_point(line l1, line l2)
{
    double a = area(l1.p1, l2.p1, l2.p2);
    double b = area(l1.p2, l2.p1, l2.p2);
    
    if (a < eps && b < eps) return l1.p1;
    
    return make_point(l1.p1.x + (l1.p2.x - l1.p1.x) * a / (a + b), l1.p1.y + (l1.p2.y - l1.p1.y) * a / (a + b));
}

int main()
{
    int y1, y2, yw, xb, yb, r;
    point p1, p2, p3;
    
    scanf("%d %d %d %d %d %d", &y1, &y2, &yw, &xb, &yb, &r);
    
    p1 = make_point(xb, yb);
    p2 = make_point(0, (yw - r) * 2 - y1 - r);
    p3 = make_point(0, (yw - r) * 2 - y2);
    
    if (dist_line(make_line(p1, p2), p3) + eps < r) {
        puts("-1");
    } else {
        point p = cross_point(make_line(p1, p2), make_line(make_point(0, yw - r), make_point(xb, yw - r)));
        
        printf("%.12lf\n", p.x);
    }
    
    return 0;
}