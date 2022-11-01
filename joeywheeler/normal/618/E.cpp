#include <bits/stdc++.h>
#include <complex>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef complex<double> p;

struct f {
    p fp;
    p fo;
};

f mrge(f a, f b) {
    f res;
    b.fp *= a.fo;
    b.fo *= a.fo;
    res.fp = a.fp + b.fp;
    res.fo = b.fo;
    return res;
}

f rt[600006];
int n;

f apply(f a, int op, int s) {
    if (op == 1) {
        // inc len
        a.fp += (1.*s) * a.fo;
    } else {
        // add s to angle
        double ang = -(s * 2 * acos(-1.)) / 360.;
        p rot = polar(1.,ang);
        a.fp *= rot;
        a.fo *= rot;
    }
    return a;
}

void u(int i, int op, int s) {
    i += n;
    rt[i] = apply(rt[i], op, s);
    for (i /= 2; i; i /= 2) rt[i] = mrge(rt[2*i], rt[2*i+1]);
}

f q(int l, int r) {
    f resl, resr;
    resl.fp = polar(0.0); resl.fo = polar(1.0);
    resr.fp = polar(0.0); resr.fo = polar(1.0);
    for (l += n, r += n; l < r; l/=2, r/=2) {
        if (l&1) resl = mrge(resl, rt[l++]);
        if (r&1) resr = mrge(rt[--r], resr);
    }
    return mrge(resl, resr);
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    FO(i,0,600006) {
        rt[i].fp = polar(0.0);
        rt[i].fo = polar(1.0);
    }
    FO(i,0,n) u(i, 1, 1);
    //f res = q(0,n);
    //cout << res.fp << " " << res.fo << "\n";
    //return 0;

    FO(i,0,m) {
        int t, j, s; scanf("%d%d%d", &t, &j, &s);
        u(j-1, t, s);
        f res = q(0,n);
        double x = res.fp.real();
        double y = res.fp.imag();
        printf("%.10lf %.10lf\n", x, y);
    }
}