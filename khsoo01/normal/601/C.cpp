#include<bits/stdc++.h>
using namespace std;
int n, m, sum, a[105];
double dt[105][100005];

int main()
{
    scanf("%d%d",&n,&m);
    if(m == 1) {puts("1.000000000000"); return 0;}
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for(int i=1;i<sum;i++) {
        dt[1][i] = (a[1] != i && i<=m);
        dt[1][i] += dt[1][i-1];
    }
    for(int j=2;j<=n;j++) {
        for(int i=j;i<sum;i++) {
            dt[j][i] = dt[j-1][i-1]-dt[j-1][max(0,i-m-1)];
            if(i-a[j]>0) dt[j][i] -= dt[j-1][i-a[j]] - dt[j-1][i-a[j]-1];
            dt[j][i] /= m-1;
            dt[j][i] += dt[j][i-1];
        }
    }
    printf("%.12f\n",dt[n][sum-1]+1);
}