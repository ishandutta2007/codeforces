#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a,b,G[1002][1002],i,j,fl;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    if (a!=1 && b!=1 || ((n==2 || n==3) && a==1 && b==1)){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    memset(G,-1,sizeof(G));
    if (a==1 && b==1){
        fl=1;
        for (i=1;i<n;i++) G[i][i+1]=1;
    }
    else{
        if (a>b) swap(a,b),fl=1;
        for (i=2;i<=n+1-b;i++) G[1][i]=fl;
    }
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++)
            if (i==j) putchar(48);
            else if (G[i][j]!=-1 || G[j][i]!=-1) putchar(fl+48);
            else putchar((fl^1)+48);
        putchar('\n');
    }
}