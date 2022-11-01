#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int d[3][3];

int main() {
    scanf("%d %d %d", &d[0][1], &d[0][2], &d[1][2]);
    d[1][0] = d[0][1];
    d[2][0] = d[0][2];
    d[2][1] = d[1][2];
    FO(i,0,3) FO(j,0,3) FO(k,0,3) d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    printf("%d\n", d[0][1] + d[1][2] + d[2][0]);
}