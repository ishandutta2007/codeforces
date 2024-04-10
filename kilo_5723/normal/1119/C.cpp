#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=505;
int a[maxn][maxn],b[maxn][maxn];
int col1[maxn],col2[maxn],row1[maxn],row2[maxn];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) for (j=0;j<m;j++){
        scanf("%d",&a[i][j]);
        col1[i]^=a[i][j];
        row1[j]^=a[i][j];
    }
    for (i=0;i<n;i++) for (j=0;j<m;j++){
        scanf("%d",&b[i][j]);
        col2[i]^=b[i][j];
        row2[j]^=b[i][j];
    }
    for (i=0;i<n;i++) if (col1[i]!=col2[i]){
        puts("No");
        return 0;
    }
    for (i=0;i<m;i++) if (row1[i]!=row2[i]){
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}