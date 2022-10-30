#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int p[1005][1005];
double e[1005];
double a[1005], b[1005], pfail[1005];
bool proc[1005];
int n;
double ca;

double ge(int i) {
    if (pfail[i] > 1-1e-9) return 1e9;
    //printf("pfail[%d]=%lf\n", i, pfail[i]);
    //printf("a[%d]=%lf\n", i, a[i]);
    return (a[i] + pfail[i]) / (1-pfail[i]);
}

void fix(int i) {
    //printf("e[%d]=%lf\n", i, e[i]);
    proc[i] = true;
    FO(j,0,n) if (!proc[j]) {
        if (p[j][i] > 0) {
            a[j] += b[j] * p[j][i] / 100. * (1+e[i]);
            pfail[j] -= b[j] * p[j][i] / 100.;
            b[j] *= 1 - (p[j][i] / 100.);
        }
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) FO(j,0,n) {
        scanf("%d", &p[i][j]);
    }
    FO(i,0,n) a[i] = 0, b[i] = 1, pfail[i] = 1;
    proc[n-1] = true;
    fix(n-1);
    while (1) {
        double mn = 1e9; int mi = -1;
        FO(i,0,n) {
            double tmp = ge(i);
            if (!proc[i] && (mi == -1 || tmp < mn)) {
                mn = tmp;
                mi = i;
            }
        }
        if (mi == -1) break;
        e[mi] = mn;
        fix(mi);
        if (mi == 0) break;
    }
    printf("%.20lf\n", e[0]);
}