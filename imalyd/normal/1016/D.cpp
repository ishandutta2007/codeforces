#include<bits/stdc++.h>
using namespace std;
int n,m,x[105][105],a[105],b[105],ax,bx;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),ax^=a[i];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),bx^=b[i];
    if(ax!=bx){printf("NO");}
    else{
        printf("YES\n");
        for(int i=2;i<=n;i++)x[i][1]=a[i];
        for(int i=2;i<=m;i++)x[1][i]=b[i];
        x[1][1]=ax^b[1]^a[1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%d ",x[i][j]);
            printf("\n");
        }
    }
    return 0;
}