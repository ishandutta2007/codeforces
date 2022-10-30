#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    long double a,b,c,d;
    long long H,I,J,K;
    scanf("%lld %lld %lld %lld", &H, &I, &J, &K);
    a = H; b = I; c = J; d = K;
    long double s = 0, e = 1e9;
    FO(Z,0,5000) {
        long double m = (s+e)/2;

        long double l0 = 2e18, r0 = -2e18;
        long double l1 = 2e18, r1 = -2e18;

        FO(i,0,2) FO(j,0,2) {
            long double av = a + (i==0 ? m : -m);
            long double cv = d + (j==0 ? m : -m);
            long double v = av*cv;
            l0 = min(l0,v);
            r0 = max(r0,v);

            av = b + (i==0 ? m : -m);
            cv = c + (j==0 ? m : -m);
            v = av*cv;
            l1 = min(l1,v);
            r1 = max(r1,v);
        }

        if (max(l0,l1) <= min(r0,r1)) {
            e = m;
        } else s = m;
    }
    double ans = s;
    printf("%.15lf\n", ans);
}