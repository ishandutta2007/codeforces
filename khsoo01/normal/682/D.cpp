#include<bits/stdc++.h>
using namespace std;
int n,m,q,dt[1005][1005][11];
char a[1005],b[1005];
bool spt[1005][1005][11];

int maxmat (int X, int Y) {
    int ret = 0;
    for(int k=10;k>=0;k--) {
        if(spt[X][Y][k]) {
            ret += (1<<k);
            X -= (1<<k);
            Y -= (1<<k);
        }
        if(X<0 || Y<0) break;
    }
    return ret;
}

int solve(int X,int Y,int Z) {
    if(X<0 || Y<0) return 0;
    if(!Z) return 0;
    if(dt[X][Y][Z]!=-1) return dt[X][Y][Z];
    int ret = 0, mm = maxmat(X,Y);
    ret = max(mm+solve(X-mm,Y-mm,Z-1),max(solve(X-1,Y,Z),solve(X,Y-1,Z)));
    dt[X][Y][Z] = ret;
    //printf("%d %d %d : %d\n",X,Y,Z,ret);
    return ret;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s",&a,&b);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            spt[i][j][0] = (a[i]==b[j]);
        }
    }
    for(int k=1;k<=10;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!spt[i][j][k-1] || min(i,j)+1<(1<<k)) spt[i][j][k] = false;
                else spt[i][j][k] = spt[i-(1<<(k-1))][j-(1<<(k-1))][k-1];
            }
        }
    }
    memset(dt,-1,sizeof(dt));
    printf("%d",solve(n-1,m-1,q));
}