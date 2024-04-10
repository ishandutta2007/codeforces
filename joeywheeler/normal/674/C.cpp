#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

long double mt[2][200005];
int n, k;
int t[200005];
ll ts[200005];
long double *cur, *prv;

long double u1[200005], u2[200005];

long double cst(int i, int j) {
    return u1[j+1]-u1[i] - ts[i] * (u2[j+1]-u2[i]);
}

void go(int rs, int re, int qs, int qe) {
    if (rs > re) return;
    int i = (rs+re)/2;
    int bst = qe; long double bv = 1e30;
    FO(j,max(qs,i),qe+1) {
        long double cv = prv[j+1] + cst(i,j);
        if (cv < bv) {
            bv = cv;
            bst = j;
        }
    }
    /*FO(j,i,n) {
        long double cv = prv[j+1] + cst(i,j);
        if (cv < bv-1e-5) {
            printf("FUCK %Lf, %Lf\n", cv, bv);
        }
    }*/
    cur[i] = bv;

    go(rs, i-1, qs, bst);
    go(i+1, re, bst, qe);
}

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) scanf("%d", t+i);
    FO(i,0,n) ts[i+1] = ts[i]+t[i];
    FO(i,0,n) u1[i+1] = u1[i] + ts[i+1] / 1.L / t[i];
    FO(i,0,n) u2[i+1] = u2[i] + 1.L / t[i];

    cur = mt[0], prv = mt[1];
    FO(i,1,n) {
        cur[i] = 1e30;
    }
    cur[n] = 0;
    FO(g,1,k+1) {
        swap(cur,prv);
        go(0,n,0,n-1);
    }
    printf("%.10lf\n", (double)cur[0]);
}