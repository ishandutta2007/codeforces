#include <bits/stdc++.h>
using namespace std;
typedef long double coord;
typedef long long ll;

template<class T>
struct pt {
    T x, y;
    pt() {}
    pt(T x, T y): x(x), y(y) {}
    pt<T> operator+(pt<T> p) {
        return pt<T>(x + p.x, y + p.y);
    }
    pt<T> operator-(pt<T> p) {
        return pt<T>(x - p.x, y - p.y);
    }
    pt<T> scale(T s) {
        return pt<T>(x * s, y * s);
    }
    T dot(pt<T> p) {
        return x * p.x + y * p.y;
    }
    T cross(pt<T> p) {
        return x * p.y - y * p.x;
    }
    coord dist(pt<T> p) {
        return (*this - p).mag();
    }
    coord mag() {
        return hypot(coord(x), coord(y));
    }
};

pt<coord> get(pt<coord> oa, pt<coord> pa, pt<coord> ob, pt<coord> pb, pt<coord> oc) {
    pt<coord> oab = ob - oa;
    pt<coord> pab = pb - pa;

    coord c = oab.dot(pab);
    coord s = oab.cross(pab);
    coord cs = hypot(c, s);
    c /= cs;
    s /= cs;

    pt<coord> oac = oc - oa;
    pt<coord> roac = {
        c * oac.x - s * oac.y,
        s * oac.x + c * oac.y
    };
    return roac + pa;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<pt<coord>> orig(n);
    for (int i = 0; i < n; i++) {
        scanf("%Lf%Lf", &orig[i].x, &orig[i].y);
    }

    pt<coord> centr = {0, 0};
    for (int i = 0; i < n; i++) centr = centr + orig[i];
    centr = centr.scale(coord(1)/n);
    pt<coord> origm = {0, 0};
    coord areat = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        coord ar = abs((orig[i] - centr).cross((orig[j] - centr)));
        pt<coord> ctrd = (centr + orig[i] + orig[j]).scale(coord(1)/3);
        origm = origm + ctrd.scale(ar);
        areat += ar;
    }
    origm = origm.scale(1/areat);


    int ia = 0, ib = 1;
    pt<coord> pa = orig[ia], pb = orig[ib], currm = origm;
    while (q--) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            int f, t;
            scanf("%d%d", &f, &t);
            f--, t--;
            if (ia != f) {
                swap(ia, ib);
                swap(pa, pb);
            }
            assert(ia == f);

            currm = {pb.x, pb.y - pb.dist(currm)};

            ia = t;
            pa = get(orig[ib], pb, origm, currm, orig[ia]);
        } else {
            int i;
            scanf("%d", &i);
            i--;
            pt<coord> bago = get(orig[ia], pa, origm, currm, orig[i]);
            printf("%.11Lf %.11Lf\n", bago.x, bago.y);
        }
    }
}