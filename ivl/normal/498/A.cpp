#include <cstdio>

using namespace std;

#define double long double

const double ep = 1e-12;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3){
       return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
}

int sign(double x){
    if (x < 0) return -1;
    return 1;
}

int x1, y1;
int x2, y2;
int n;
int a[305], b[305], c[305];

int main(){
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d", &n);
    int r = 0;
    for (int i = 0; i < n; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0){
           double y = (double)(-c) / (double)b;
           if (y1 >= y && y2 <= y || y2 >= y && y1 <= y) ++r;
           continue;
        }
        if (b == 0){
           double x = (double)(-c) / (double)a;
           if (x1 >= x && x2 <= x || x2 >= x && x1 <= x) ++r;
           continue;
        }
        
        double xx1, xx2, yy1, yy2;
        xx1 = 0;
        yy1 = (double)(-c) / (double)b;
        if (c != 0){xx2 = (double)(-c) / (double)a; yy2 = 0;}
        else {yy2 = 1; xx2 = (double)(-c-a) / (double)b;}
        if (sign(ccw(xx1, yy1, xx2, yy2, x1, y1)) != sign(ccw(xx1, yy1, xx2, yy2, x2, y2))) ++r;
    }
    printf("%d\n", r);
    return 0;
}