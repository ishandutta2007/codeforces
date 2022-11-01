#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, a, b;
double p[2005], u[2005];
double f[2005][2005]; int c[2005][2005];

int main() {
    scanf("%d %d %d", &n, &a, &b);
    FO(i,0,n) scanf("%lf", p+i);
    FO(i,0,n) scanf("%lf", u+i);
    double s = 0, e = 1e15, ans;
    FO(Z,0,120) {
        double m = (s+e)/2;
        f[0][0] = 0; c[0][0] = 0;
        FO(i,1,n+1) FO(j,0,min(i,a)+1) {
            if (j <= i-1) {
                f[i][j] = f[i-1][j], c[i][j] = c[i-1][j];
                if (f[i][j] < f[i-1][j] + u[i-1]-m) f[i][j] = f[i-1][j] + u[i-1]-m, c[i][j] = c[i-1][j]+1;
            } else f[i][j] = -1e80;
            if (j) {
                if (f[i][j] < f[i-1][j-1] + p[i-1]) f[i][j] = f[i-1][j-1] + p[i-1], c[i][j] = c[i-1][j-1];
                if (f[i][j] < f[i-1][j-1] + p[i-1]+u[i-1]-p[i-1]*u[i-1]-m) f[i][j] = f[i-1][j-1] + p[i-1]+u[i-1]-p[i-1]*u[i-1]-m, c[i][j] = c[i-1][j-1]+1;
            }
        }
        if (c[n][a] > b) s = m;
        else {
            e = m;
            ans = f[n][a] + b * m;
        }
    }
    printf("%.9lf\n", ans);
}