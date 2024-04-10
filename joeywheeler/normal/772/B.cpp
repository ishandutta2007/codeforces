#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

double x[1005], y[1005];
int n;

double f(int i, int j, int k) {
    double y0 = y[j]-y[i];
    double x0 = x[j]-x[i];

    double y1 = y[k]-y[i];
    double x1 = x[k]-x[i];

    double t = (y0*x1 - x0*y1) / sqrt(x1*x1 + y1*y1);

    return t/2;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lf %lf", x+i, y+i);
    }
    x[n] = x[0], y[n] = y[0];
    x[n+1] = x[1], y[n+1] = y[1];
    double res = 1e16;
    FO(i,0,n) {
        res = min(res, f(i,i+1,i+2));
    }
    printf("%.10lf\n", res);
}