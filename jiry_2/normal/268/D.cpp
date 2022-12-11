#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int f[1010][32][32][32][2],n,h,mo=1e9+9;
int main(){
    scanf("%d%d",&n,&h); memset(f,0x00,sizeof f);
    f[0][0][0][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int k1=0;k1<=h;k1++)
            for (int k2=k1;k2<=h;k2++)
                for (int k3=k2;k3<=h;k3++){
                    if (k1!=h)
                        f[i][1][min(k2+1,h)][min(k3+1,h)][0]=(f[i][1][min(h,k2+1)][min(h,k3+1)][0]+f[i-1][k1][k2][k3][0])%mo;
                    else f[i][1][min(k2+1,h)][min(k3+1,h)][1]=(f[i][1][min(h,k2+1)][min(h,k3+1)][1]+f[i-1][k1][k2][k3][0])%mo;
                    if (k2!=h)
                        f[i][1][min(k1+1,h)][min(k3+1,h)][0]=(f[i][1][min(k1+1,h)][min(k3+1,h)][0]+f[i-1][k1][k2][k3][0])%mo;
                    else f[i][1][min(k1+1,h)][min(k3+1,h)][1]=(f[i][1][min(k1+1,h)][min(k3+1,h)][1]+f[i-1][k1][k2][k3][0])%mo;
                    if (k3!=h)
                        f[i][1][min(k1+1,h)][min(k2+1,h)][0]=(f[i][1][min(k1+1,h)][min(k2+1,h)][0]+f[i-1][k1][k2][k3][0])%mo;
                    else f[i][1][min(k1+1,h)][min(k2+1,h)][1]=(f[i][1][min(k1+1,h)][min(k2+1,h)][1]+f[i-1][k1][k2][k3][0])%mo;
                    f[i][min(k1+1,h)][min(k2+1,h)][min(k3+1,h)][0]=(f[i][min(k1+1,h)][min(k2+1,h)][min(k3+1,h)][0]+f[i-1][k1][k2][k3][0])%mo;
                    if (k1!=h)
                        f[i][min(k2+1,h)][min(k3+1,h)][h][0]=(f[i][min(k2+1,h)][min(k3+1,h)][h][0]+f[i-1][k1][k2][k3][1])%mo;
                    else f[i][min(k2+1,h)][min(k3+1,h)][h][1]=(f[i][min(k2+1,h)][min(k3+1,h)][h][1]+f[i-1][k1][k2][k3][1])%mo;
                    if (k2!=h)
                        f[i][min(k1+1,h)][min(k3+1,h)][h][0]=(f[i][min(k1+1,h)][min(k3+1,h)][h][0]+f[i-1][k1][k2][k3][1])%mo;
                    else f[i][min(k1+1,h)][min(k3+1,h)][h][1]=(f[i][min(k1+1,h)][min(k3+1,h)][h][1]+f[i-1][k1][k2][k3][1])%mo;
                    if (k3!=h)
                        f[i][min(k1+1,h)][min(k2+1,h)][h][0]=(f[i][min(k1+1,h)][min(k2+1,h)][h][0]+f[i-1][k1][k2][k3][1])%mo;
                    else f[i][min(k1+1,h)][min(k2+1,h)][h][1]=(f[i][min(k1+1,h)][min(k2+1,h)][h][1]+f[i-1][k1][k2][k3][1])%mo;
                    f[i][min(k1+1,h)][min(k2+1,h)][min(k3+1,h)][1]=(f[i][min(k1+1,h)][min(k2+1,h)][min(k3+1,h)][1]+f[i-1][k1][k2][k3][1])%mo;
                }
    int ans=0;
    for (int i=0;i<=h;i++)
        for (int j=i;j<=h;j++)
            for (int k=j;k<=h;k++){
                ans=(ans+f[n][i][j][k][0])%mo;
                if (i!=h||j!=h||k!=h) ans=(ans+f[n][i][j][k][1])%mo;
            }
    cout<<ans<<endl; return 0;
}