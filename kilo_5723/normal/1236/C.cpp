#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=305;
int a[maxn][maxn];
int main(){
    int i,j,n,t;
    scanf("%d",&n);
    t=0;
    for (j=0;j<n;j++){
        if (j&1) for (i=0;i<n;i++) a[i][j]=++t;
        else for (i=n-1;i>=0;i--) a[i][j]=++t;
    }
    for (i=0;i<n;i++) for (j=0;j<n;j++)
        printf("%d%c",a[i][j],j<n-1?' ':'\n');
    return 0;
}