#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,C[1001][1001],n,k,f[1001][1001][4],ans[1001],I[1001];
int main(){
    scanf("%d%d",&n,&k); I[0]=1;
    for (int i=1;i<=n;i++) I[i]=1ll*I[i-1]*i%mo;
    for (int i=0;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
    }
    memset(f,0x00,sizeof f); f[0][0][2]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++){
            for (int k=0;k<4;k++) f[i][j][(k>>1)+2]=(f[i][j][(k>>1)+2]+f[i-1][j][k])%mo;
            if (j==0) continue;
            for (int k=0;k<4;k++){
                f[i][j][(k>>1)]=(f[i][j][(k>>1)]+f[i-1][j-1][k])%mo;
                if (k&1) f[i][j][(k>>1)+2]=(f[i][j][(k>>1)+2]+f[i-1][j-1][k])%mo;
            }
        }
    for (int i=0;i<=n;i++) ans[i]=1ll*(f[n][i][2]+f[n][i][3])%mo*I[n-i]%mo;
    for (int i=n;i>=0;i--)
        for (int j=i+1;j<=n;j++) ans[i]=(ans[i]-1ll*C[j][i]*ans[j]%mo)%mo;
    cout<<(1ll*ans[k]+mo)%mo<<endl; return 0;
}