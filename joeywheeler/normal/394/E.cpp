#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
ll py[100005], px[100005];

ll AX, BX, CX;
ll AY, BY, CY;

double score(double y, double x) {
    return AY*y*y + BY*y + CY +
        AX*x*x + BX*x + CX;
}

double cross(double y0, double x0, double y1, double x1) {
    return y0*x1-x0*y1;
}

int main() {
    int _; scanf("%d", &_);
    double ty = 0, tx = 0;
    FO(__,0,_) {
        ll y,x; scanf("%lld %lld", &y, &x);
        AX++; AY++;
        BX -= 2*x; BY -= 2*y;
        CX += x*x; CY += y*y;
        ty += y; tx += x;
    }
    ty /= _; tx /= _;
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld %lld", &py[i], &px[i]);
    bool fail = false;
    FO(i,0,n) {
        int p = i==0?n-1:i-1;
        double pty = ty-py[p];
        double ptx = tx-px[p];
        double piy = py[i]-py[p];
        double pix = px[i]-px[p];
        double c = cross(pty, ptx, piy, pix);
        if (c < -1e-5) {
            fail = true;
            break;
        }
    }
    if (!fail) {
        printf("%.8lf\n", score(ty,tx));
    } else {
        double res = 1e100;
        FO(i,0,n) {
            int p = i==0?n-1:i-1;
            double y0 = py[p], x0 = px[p], y1 = py[i], x1 = px[i];
            // ternary search on interval (y0,x0) - (y1,x1)
            while (fabs(y1-y0)+fabs(x1-x0) > 1e-5) {
                double ay = y0+(y1-y0)/3., ax = x0+(x1-x0)/3.;
                double by = y0+(y1-y0)*2./3., bx = x0+(x1-x0)*2./3.;
                double sa = score(ay, ax);
                double sb = score(by, bx);
                if (sa > sb) {
                    y0 = ay; x0 = ax;
                } else {
                    y1 = by; x1 = bx;
                }
            }
            res = min(res, score(y0,x0));
        }
        printf("%.8lf\n", res);
    }
}