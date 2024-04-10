#include<bits/stdc++.h>
using namespace std;
int n,k,a[505];
bool dt[2][505][505];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    dt[1][0][0] = true;
    for(int i=0;i<n;i++) {
        for(int x=k;x>=0;x--) {
            for(int y=k;y>=0;y--) {
                if(x>=a[i]) dt[i&1][x][y] |= dt[1-(i&1)][x-a[i]][y];
                if(y>=a[i]) dt[i&1][x][y] |= dt[1-(i&1)][x][y-a[i]];
                dt[i&1][x][y] |= dt[1-(i&1)][x][y];
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<=k;i++) {
        if(dt[(n-1)%2][i][k-i]) cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<=k;i++) {
        if(dt[(n-1)%2][i][k-i]) printf("%d ",i);
    }
}