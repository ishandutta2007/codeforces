#include <cstdio>
#include <cmath>

using namespace std;

typedef struct point {
    double x;
    double y;
    
    point(const double &x1 = 0, const double &y1 = 0) {
        x = x1;
        y = y1;
    }
} point;

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

enum {
    LEFT = 1,
    RIGHT = -1,
    FRONT = 2,
    BACK = -2,
    ON = 0
};

inline int ccw(const point &p1, const point &p2, const point &p3)
{
    point p = p2 - p1;
    point q = p3 - p1;
    double r = p.x * q.y - p.y * q.x;
    
    if (r > eps) {
        return LEFT;
    } else if (r < -eps) {
        return RIGHT;
    } else {
        double t = (p.x * q.x + p.y * q.y) / (p.x * p.x + p.y * p.y);
        
        if (t > 1) {
            return FRONT;
        } else if (t < 0) {
            return BACK;
        } else {
            return ON;
        }
    }
}

int main()
{
    int n, x1, y1, x2, y2, ans = 0, i;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int a, b, c;
        
        scanf("%d %d %d", &a, &b, &c);
        
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        
        if (b == 0) {
            if (((long long)a * x1 < -c && (long long)a * x2 > -c) || ((long long)a * x1 > -c && (long long)a * x2 < -c)) ans++;
        } else {
            point p1(0, -(double)c / b);
            point p2(1, -(double)(a + c) / b);
            
            if (ccw(p1, p2, point(x1, y1)) != ccw(p1, p2, point(x2, y2))) ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}