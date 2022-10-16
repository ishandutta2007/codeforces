#include<bits/stdc++.h>
#define MAX   3030
typedef long long ll;
const int mod=(int)1e9+7;
int m,n;
char a[MAX][MAX];
ll f[3][MAX][MAX];
void init(void) {
    scanf("%d",&m);
    scanf("%d",&n);
    int i;
    for (i=1;i<=m;i=i+1) scanf("%s",&a[i][1]);
    for (i=0;i<=m+1;i=i+1) {
        a[i][0]='#';
        a[i][n+1]='#';  
    }
    for (i=0;i<=n+1;i=i+1) {
        a[0][i]='#';
        a[m+1][i]='#';
    }
}
void optimize(void) {
    f[0][1][2]=1LL*(a[1][2]!='#');
    f[1][2][1]=1LL*(a[2][1]!='#');
    int i,j,k;
    for (k=0;k<2;k=k+1)
        for (i=1;i<=m;i=i+1)
            for (j=1;j<=n;j=j+1)
                if (f[k][i][j]>0) {
                    if (a[i][j+1]!='#') f[k][i][j+1]=(f[k][i][j+1]+f[k][i][j])%mod;
                    if (a[i+1][j]!='#') f[k][i+1][j]=(f[k][i+1][j]+f[k][i][j])%mod;
                }
    ll res=0LL;
    res+=(f[0][m-1][n]*f[1][m][n-1])%mod;
    res-=(f[0][m][n-1]*f[1][m-1][n])%mod;
    res=(res%mod+mod)%mod;
    printf("%I64d",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}