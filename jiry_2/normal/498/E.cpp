#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int x[130][130];
}A,B;
int mo=1e9+7,n,w[10],dp[130],f[130],m;
atom operator * (atom k1,atom k2){
    memset(B.x,0x00,sizeof B.x);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                B.x[i][j]=(B.x[i][j]+1ll*k1.x[i][k]*k2.x[k][j])%mo;
    return B;
}
int check(int k1,int k2,int k3){
    int a[10],b[10],c[10];
    memset(a,0x00,sizeof a);
    memset(b,0x00,sizeof b);
    memset(c,0x00,sizeof c);
    for (int i=0;i<m;i++) a[i]=((k1>>i)&1);
    for (int i=0;i<m-1;i++) b[i+1]=((k2>>i)&1);
    for (int i=0;i<m;i++) c[i]=((k3>>i)&1);
    b[0]=1; b[m]=1;
    for (int i=0;i<m;i++) if (a[i]&&b[i]&&b[i+1]&&c[i]) return 0;
    return 1;
}
void quick(int k){
    if (k==0){
        memset(A.x,0x00,sizeof A.x);
        for (int i=0;i<n;i++) A.x[i][i]=1; return;
    }
    atom C=A; k--;
    while (k){
        if (k&1) A=A*C; C=C*C; k>>=1;
    }
    return;
}
int main(){
    for (int i=1;i<=7;i++) scanf("%d",&w[i]); int r;
    for (int i=7;i;i--) if (w[i]){w[i]--; r=i; break;} dp[0]=1;
    for (int now=1;now<=r;now++){
        memset(f,0x00,sizeof f);
        for (int i=0;i<(1<<now-1);i++) f[i+(1<<now-1)]=dp[i];
        n=1<<now; m=now;
        memset(A.x,0x00,sizeof A.x); 
        for (int i=0;i<n;i++)
            for (int j=0;j<(n>>1);j++)
                for (int k=0;k<n;k++)
                    if (check(i,j,k)) A.x[i][k]=(A.x[i][k]+1)%mo;
        quick(w[now]);
        memset(dp,0x00,sizeof dp);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dp[j]=(dp[j]+1ll*f[i]*A.x[i][j])%mo;
    }
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<(n>>1);j++)
            if (check(i,j,n-1)) ans=(ans+dp[i])%mo;
    cout<<ans<<endl; return 0;
}