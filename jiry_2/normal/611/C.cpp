#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[600][600],B[600][600],pd[600][600],n,m;
char ch[600];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        for (int j=1;j<=m;j++) if (ch[j]=='.') pd[i][j]=1;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if (pd[i][j]&&pd[i][j-1]) A[i][j]=1;
            A[i][j]=A[i][j]+A[i-1][j]+A[i][j-1]-A[i-1][j-1];
            if (pd[i][j]&&pd[i-1][j]) B[i][j]=1;
            B[i][j]=B[i][j]+B[i-1][j]+B[i][j-1]-B[i-1][j-1];
        }
    int q; scanf("%d",&q);
    for (;q;q--){
        int k1,k2,k3,k4; scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
        k1++; int ans=0;
        if (k1<=k3) ans+=B[k3][k4]-B[k3][k2-1]-B[k1-1][k4]+B[k1-1][k2-1];
        k1--; k2++;
        if (k2<=k4) ans+=A[k3][k4]-A[k3][k2-1]-A[k1-1][k4]+A[k1-1][k2-1];
        printf("%d\n",ans);
    }
    return 0;
}