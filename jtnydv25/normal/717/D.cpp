#include <bits/stdc++.h>
using namespace std;
double P[32][130];
void pw(int u) {
    for(int i=0; i<128; i++) P[u+1][i] = 0.;
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            P[u+1][i^j] += P[u][i]*P[u][j];
}
double sol[130];
double temp[130];
void mul(int u) {
    for(int i=0; i<128; i++) temp[i] = sol[i];
    for(int i=0; i<128; i++) sol[i] = 0.;
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            sol[i^j] += temp[i]*P[u][j];
}
void give(int n) {
    for(int i=0; i<128; i++) sol[i] = 0.;
    sol[0] = 1.;
    int i = 0;
    while(i < 32) {
        if((n>>i) & 1) {
            mul(i);
        }
        i++;
    }
}
int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    for(int i=0; i<=w; i++) scanf("%lf", &P[0][i]);
    for(int i=w+1; i<128; i++) P[0][i] = 0.;
    for(int i=0; i<31; i++)
        pw(i);
    give(n);
    double ans = 1. - sol[0];   
    printf("%.6f", ans);
}