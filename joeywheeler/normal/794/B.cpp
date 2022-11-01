#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
double h;

int main() {
    scanf("%d %lf", &n, &h);
    double a = 0.5 * h;
    FO(i,0,n-1) {
        double r = (a / n) * (i+1);
        double t = sqrt(r * 2 * h);
        printf("%.8lf%c", t, " \n"[i+1==n-1]);
    }
}