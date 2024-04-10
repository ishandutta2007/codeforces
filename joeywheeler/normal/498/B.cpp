#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, T;

double v[5005];
double nv[5005];

void go(double p, int t) {
    double tt = 1;
    double curprob = 0;

    FO(i,0,T+1) nv[i] = 0;
    if (p < 1e-4) {
        FO(i,t,T+1) nv[i] = v[i-t];
        goto done;
    }

    FO(i,0,t-1) tt *= 1-p;

    FO(i,1,T+1) {
        curprob *= 1-p;
        curprob += v[i-1];
        if (i >= t) curprob -= tt*v[i-t];
        nv[i] = curprob * p;
        if (i >= t) nv[i] += tt*v[i-t];
    }

done:
    FO(i,0,T+1) v[i] = nv[i];
}

int main() {
    scanf("%d %d", &n, &T);
    v[0] = 1;
    double res = 0;
    FO(i,0,n) {
        int p, t; scanf("%d %d", &p, &t);
        go(p/100., t);
        FO(i,0,T+1) {
            //printf("%lf ", v[i]);
            res += v[i];
        }
        //printf("\n");
    }
    printf("%.10lf\n", res);
}