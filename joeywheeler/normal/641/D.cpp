#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
double mn[100005];
double mx[100005];

double a[100005], b[100005];
double r1[100005], r2[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf(" %lf", mx+i);
    FO(i,0,n) scanf(" %lf", mn+i);
    FO(i,0,n) {
        r1[i] = mx[i];
        if (i) r1[i] += r1[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        r2[i] = mn[i];
        r2[i] += r2[i+1];
    }
    FO(i,0,n) {
        double p = r1[i];
        double s = 1-(r2[i+1]-r1[i]);
        double A = -1, B = s, C = -p;
        a[i] = (-B + sqrt(max(B*B-4*A*C,0.))) / (2*A);
        b[i] = s-a[i];
        if (a[i] > b[i]) swap(a[i],b[i]);
    }
    for (int i = n-1; i > 0; i--) a[i] -= a[i-1], b[i] -= b[i-1];
    FO(i,0,n) printf("%.11lf ", a[i]);
    printf("\n");
    FO(i,0,n) printf("%.11lf ", b[i]);
    printf("\n");
}