#include <cstdio>
#include <cmath>
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

inline double area(const point &p1, const point &p2, const point &p3)
{
    point p = p1 - p3;
    point q = p2 - p3;
    
    return abs(p.x * q.y - p.y * q.x) / 2;
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
    int n, i, j, k;
    double ans = 0;
    point p[300];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        p[i] = point(x, y);
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double m1 = 0, m2 = 0;
            
            for (k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                
                if (ccw(p[i], p[j], p[k]) == LEFT) {
                    m1 = max(m1, area(p[i], p[j], p[k]));
                } else {
                    m2 = max(m2, area(p[i], p[j], p[k]));
                }
            }
            
            if (m1 == 0 || m2 == 0) continue;
            
            ans = max(ans, m1 + m2);
        }
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}