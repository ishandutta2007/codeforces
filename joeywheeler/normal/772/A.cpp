#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
double p, a[100005], b[100005];
double o[100005];

int main() {
    scanf("%d %lf", &n, &p);
    FO(i,0,n) {
        scanf("%lf %lf", a+i, b+i);
    }
    double s = 0, e = 1e16;
    FO(z,0,100) {
        double m = (s+e)/2;
        double so = 0;
        FO(i,0,n) {
            o[i] = max(m*a[i]-b[i],0.0) / p;
            so += o[i];
        }
        if (so <= m) {
            s = m;
        } else {
            e = m;
        }
    }
    if (s > .9e16) printf("-1\n");
    else printf("%.10lf\n", s);
}