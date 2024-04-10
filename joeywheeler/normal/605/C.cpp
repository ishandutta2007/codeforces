#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct p {
    ll x, y;

    bool operator<(const p &o) const {
        return y*o.x < x*o.y;
    }
};

bool cw(p a, p b, p c) {
    ll x1 = b.x-a.x, x2 = c.x-a.x;
    ll y1 = b.y-a.y, y2 = c.y-a.y;
    return x1*y2 <= x2*y1;
}

p a[100005];
int n;
ll X, Y;
p stk[100005]; int ss;

int main() {
    scanf("%d", &n);
    scanf("%lld%lld", &X, &Y);
    FO(i,0,n) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    sort(a,a+n);
    stk[ss++] = a[0];
    FO(i,1,n) {
        if (!(stk[ss-1] < a[i])) {
            if (a[i].x > stk[ss-1].x) {
                stk[ss-1] = a[i];
            }
        } else {
            while (ss >= 2 && cw(stk[ss-2],stk[ss-1],a[i])) ss--;
            stk[ss++] = a[i];
        }
    }
    double res = 1e6;
    p t; t.x = X; t.y = Y;
    FO(i,0,ss) {
        //printf("%lld, %lld\n", stk[i].x, stk[i].y);
        res = min(res, max(X / 1. / stk[i].x, Y / 1. / stk[i].y));
        if (i+1 < ss && stk[i] < t && t < stk[i+1]) {
            double a = stk[i].x, b = stk[i+1].x, c = stk[i].y, d = stk[i+1].y;
            double t = (c*X - a*Y) / 1. / (b*Y - d*X);
            double nx = a + t*b;
            res = min(res, (1+t) * (X / 1. / nx));
        }
    }
    printf("%.9lf\n", res);
}