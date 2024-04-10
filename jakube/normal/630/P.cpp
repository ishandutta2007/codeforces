#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

struct Line
{
    static constexpr double EPS = 1e-9;
    double a, b, c;

    // ax + by + c = 0
    Line(double a, double b, double c) 
        : a(a), b(b), c(c) {}
    // y = kx + d
    Line(double k, double d) 
        : a(k), b(-1), c(d) {}
    // p - q
    Line(Point p, Point q) {
        double x_diff = q.x - p.x;
        if (std::abs(x_diff) < EPS) {
            a = 1;
            b = 0;
            c = -q.x;
        } else {
            a = q.y - p.y;
            b = p.x - q.x;
            c = p.y*q.x - p.x*q.y;
        }
    }

    static double det(double a11, double a12, double a21, double a22) {
        return a11*a22 - a12*a21;
    }

    static bool parallel(Line l1, Line l2) {
        return std::abs(det(l1.a, l1.b, l2.a, l2.b)) < EPS;
    }

    static Point intersect(Line l1, Line l2) {
        double d = det(l1.a, l1.b, l2.a, l2.b);
        Point p;
        p.x = -det(l1.c, l1.b, l2.c, l2.b) / d;
        p.y = -det(l1.a, l1.c, l2.a, l2.c) / d;
        return p;
    }
};

double area_parallelogram(Point p1, Point p2, Point p3) {
    return std::abs(Line::det(p2.x - p1.x, p3.x - p2.x, p2.y - p1.y, p3.y - p2.y));
}

double area_triangle(Point p1, Point p2, Point p3) {
    return area_parallelogram(p1, p2, p3) / 2;
}

int main() {
    int n;
    double r;
    cin >> n >> r;
    double pi = acos(-1);
    double angle = 2*pi/n;
    Point p1{r, 0};
    Point p2{r * cos(angle), r * sin(angle)};
    Point p1op{r * cos(angle * (n / 2)), r * sin(angle * (n / 2))};
    Point p2op{r * cos(angle * (n / 2 + 2)), r * sin(angle * (n / 2 + 2))};
    Line l1(p1, p1op);
    Line l2(p2, p2op);
    Point inter = Line::intersect(l1, l2);
    double area_small = area_triangle(p1, p2, inter);
    double area_big = area_triangle(p1, p2, {0, 0});
    std::cout << std::fixed << std::setprecision(9);
    cout << (area_big - area_small) * n << '\n';
}