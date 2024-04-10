#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, a[105], dt[105][3];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++) {
        for(int j=0;j<3;j++) dt[i][j] = inf;
    }
    dt[0][0] = 0;
    for(int i=1;i<=n;i++) {
        if(a[i]&1) dt[i][1] = min(dt[i-1][0], dt[i-1][2]);
        if(a[i]&2) dt[i][2] = min(dt[i-1][0], dt[i-1][1]);
        dt[i][0] = min(min(dt[i-1][0],dt[i-1][1]),dt[i-1][2])+1;
    }
    printf("%d\n",min(min(dt[n][0],dt[n][1]),dt[n][2]));
}