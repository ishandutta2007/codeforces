#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct ls {
    int xs, xe, ys, ye;
    int i;

    bool operator<(const ls &o) const {
        return i < o.i;
    }
    bool operator==(const ls &o) const {
        return vector<int>({xs,xe,ys,ye}) == vector<int>({o.xs,o.xe,o.ys,o.ye});
    }
};

bool bad;

/*
void hadj(ls &a, ls &b) {
    if (a.ys == a.ye) {
        if (b.ys > a.ys || b.ye < a.ys) bad = true;
        b.ys = b.ye = a.ys;
    }
    swap(a,b);
    if (a.ys == a.ye) {
        if (b.ys > a.ys || b.ye < a.ys) bad = true;
        b.ys = b.ye = a.ys;
    }
    swap(a,b);
}

void vadj(ls &a, ls &b) {
    if (a.xs == a.xe) {
        if (b.xs > a.xs || b.xe < a.xs) bad = true;
        b.xs = b.xe = a.xs;
    }
    swap(a,b);
    if (a.xs == a.xe) {
        if (b.xs > a.xs || b.xe < a.xs) bad = true;
        b.xs = b.xe = a.xs;
    }
    swap(a,b);
}
*/

ls l[4];

void solve() {
    /*FO(z,0,10) {
        FO(i,0,4) {
            if (i % 2 == 0) {
                hadj(l[i], l[(i+1)%4]);
            } else {
                vadj(l[i], l[(i+1)%4]);
            }
        }
    }
    if (bad) return;*/
    //FO(i,0,4) printf("x:[%d,%d] y:[%d,%d]\n", l[i].xs, l[i].xe, l[i].ys, l[i].ye);
    //printf("--\n");
    FO(z,0,20) {
        FO(i,0,4) {
            ls &a = l[i], &b = l[(i+1)%4];
            if (i % 2 == 0) {
                int ly = max(a.ys,b.ys);
                int ry = min(a.ye,b.ye);
                if (ly > ry) bad = true;
                a.ys = b.ys = ly;
                a.ye = b.ye = ry;
            } else {
                int lx = max(a.xs,b.xs);
                int rx = min(a.xe,b.xe);
                if (lx > rx) bad = true;
                a.xs = b.xs = lx;
                a.xe = b.xe = rx;
            }
        }
        if (bad) return;
        if (z >= 10) {
            // all are same orientation
            FO(i,0,2) {
                ls &a = l[i], &b = l[(i+2)%4];
                if (i == 0) {
                    int lxpy = max(a.xs+a.ys, b.xs+b.ys);
                    int rxpy = min(a.xe+a.ye, b.xe+b.ye);
                    if (lxpy > rxpy) bad = true;

                    a.xs = min(a.xe, lxpy-a.ys);
                    a.ys = min(a.ye, lxpy-a.xs);
                    b.xs = min(b.xe, lxpy-b.ys);
                    b.ys = min(b.ye, lxpy-b.xs);

                    a.xe = max(a.xs, rxpy-a.ye);
                    a.ye = max(a.ys, rxpy-a.xe);
                    b.xe = max(b.xs, rxpy-b.ye);
                    b.ye = max(b.ys, rxpy-b.xe);
                } else {
                    int lxmy = max(a.xs-a.ye, b.xs-b.ye);
                    int rxmy = min(a.xe-a.ys, b.xe-b.ys);
                    if (lxmy > rxmy) bad = true;

                    a.xs = min(a.xe, lxmy+a.ye);
                    a.ye = max(a.ys, a.xs-lxmy);
                    b.xs = min(b.xe, lxmy+b.ye);
                    b.ye = max(b.ys, b.xs-lxmy);

                    a.xe = max(a.xs, rxmy+a.ys);
                    a.ys = min(a.ye, a.xe-rxmy);
                    b.xe = max(b.xs, rxmy+b.ys);
                    b.ys = min(b.ye, b.xe-rxmy);
                }
            }
        }
    }
    if (l[0] == l[1]) bad = true;
    if (bad) return;
}

ls op[4];
ls cl[4];

int main() {
    int t; scanf("%d", &t);
    FO(z,0,t) {
        FO(i,0,4) scanf("%d %d", &op[i].xs, &op[i].ys);
        int s = 0, e = 1e9, bst = -1;
        while (s <= e) {
            int md = (s+e)/2;
            bad = true;
            FO(b,0,1<<4) {
                FO(i,0,4) {
                    cl[i].i = i;
                    if (b&(1<<i)) {
                        cl[i].xs = op[i].xs-md;
                        cl[i].xe = op[i].xs+md;
                        cl[i].ys = op[i].ys;
                        cl[i].ye = op[i].ys;
                    } else {
                        cl[i].xs = op[i].xs;
                        cl[i].xe = op[i].xs;
                        cl[i].ys = op[i].ys-md;
                        cl[i].ye = op[i].ys+md;
                    }
                }
                do {
                    FO(i,0,4) l[i] = cl[i];
                    bad = false;
                    solve();
                    if (!bad) {
                        break;
                    }
                } while (next_permutation(cl,cl+4));
                if (!bad) break;
            }
            if (!bad) {
                bst = md;
                e = md-1;
            } else {
                s = md+1;
            }
        }
        printf("%d\n", bst);
        if (bst != -1) {
            int md = bst;
            FO(b,0,1<<4) {
                FO(i,0,4) {
                    cl[i].i = i;
                    if (b&(1<<i)) {
                        cl[i].xs = op[i].xs-md;
                        cl[i].xe = op[i].xs+md;
                        cl[i].ys = op[i].ys;
                        cl[i].ye = op[i].ys;
                    } else {
                        cl[i].xs = op[i].xs;
                        cl[i].xe = op[i].xs;
                        cl[i].ys = op[i].ys-md;
                        cl[i].ye = op[i].ys+md;
                    }
                }
                do {
                    FO(i,0,4) l[i] = cl[i];
                    bad = false;
                    solve();
                    if (!bad) {
                        break;
                    }
                } while (next_permutation(cl,cl+4));
                if (!bad) break;
            }
            assert(!bad);
            l[0].xs = l[0].xe;
            l[0].ys = l[0].ye;
            solve();
            assert(!bad);
            sort(l,l+4);
            FO(i,0,4) printf("%d %d\n", l[i].xs, l[i].ys);
        }
    }
}