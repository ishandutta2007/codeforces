#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int d[405][405];
int dg[405];
int n, m;

double u[405][405];
int ut[405][405];
double sm[405];
int st[405];
int T;

void clr() {
    T++;
}

double &gu(int i, int j) {
    if (ut[i][j] != T) {
        u[i][j] = 0;
        ut[i][j] = T;
    }
    return u[i][j];
}

double &gsm(int i) {
    if (st[i] != T) {
        sm[i] = 0;
        st[i] = T;
    }
    return sm[i];
}

vector<int> l[405];
double pd[405];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) FO(j,0,n) d[i][j] = 1000;
    FO(i,0,n) d[i][i] = 0;
    FO(i,0,m) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        d[a][b] = d[b][a] = 1;
        dg[a]++;
        dg[b]++;
    }
    FO(i,0,n) FO(j,0,n) FO(k,0,n) d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

    //FO(i,0,n) FO(j,0,n) printf("%d%c", d[i][j], " \n"[j+1==n]);

    double bst = 0;
    FO(i,0,n) {
        // first city
        FO(j,0,n) l[j].clear();
        FO(j,0,n) l[d[i][j]].push_back(j);
        double cans = 0;
        //printf("i=%d\n", i);
        FO(li,0,n) if (sz(l[li])) {
            //printf("dst=%d\n", li);
            // what's the first dist query give
            double lb = 1. / sz(l[li]); // just guess
            FO(j,0,n) pd[j] = 0;
            clr();
            for (int j : l[li]) {
                double du = 1. / dg[j] / sz(l[li]);
                FO(k,0,n) if (d[j][k] == 1) {
                    pd[k] += du;
                }
            }
            FO(j,0,n) if (pd[j] > 1e-5) {
                //printf("pd[%d]=%lf\n", j, pd[j]);
                FO(k,0,n) {
                    double ov = gu(k,d[j][k]);
                    if (ov < pd[j]) {
                        double os = gsm(k);
                        os += pd[j]-ov;
                        gsm(k) = os;

                        ov = pd[j];
                        gu(k,d[j][k]) = ov;
                    }
                }
            }
            FO(j,0,n) lb = max(lb, gsm(j));

            //printf("lb = %lf\n", lb);
            //printf("wf = %lf\n", sz(l[li]) / 1. / n);
            cans += lb * sz(l[li]) / 1. / n;
        }
        //printf("cans = %lf\n", cans);

        bst = max(bst, cans);
    }
    printf("%.12lf\n", bst);
}