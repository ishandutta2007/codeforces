#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long double p[105];
int m[105];
int n;
long double tp[105];
long double np[105];
long double rp[105];
priority_queue<pair<long double, int> > q;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        double tmp; scanf("%lf", &tmp);
        p[i] = tmp / 100.;
    }
    long double res = n;
    FO(i,0,n) m[i] = 1;

    long double P = 1;
    FO(i,0,n) {
        tp[i] = 1 - pow(1-p[i],m[i]);
        np[i] = 1 - pow(1-p[i],m[i]+1);
        rp[i] = np[i] / tp[i];
        P *= tp[i];
        q.emplace(rp[i],i);
    }

    int Z = 0;
    while (1) {
        Z++;
        if (Z % 100 == 0) {
            P = 1;
            FO(i,0,n) P *= tp[i];
            if (P > 1-1e-10) break;
        }

        res += 1-P;

        int b = q.top().second; q.pop();
        P *= rp[b];
        m[b]++;
        tp[b] = np[b];
        np[b] = 1 - pow(1-p[b],m[b]+1);
        rp[b] = np[b] / tp[b];
        q.emplace(rp[b],b);
    }
    double tmp = res;
    printf("%.10lf\n", tmp);
}