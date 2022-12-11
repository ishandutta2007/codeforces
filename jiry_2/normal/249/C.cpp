#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long double f[101000][110],I[601000],A[110];
int num[101000],n,m,r[101000];
long double C(int k1,int k2){
    if (k2>k1) return 0;
    return I[k1]/I[k2]/I[k1-k2];
}
int main(){
    I[0]=1;
    for (int i=1;i<=600000;i++) I[i]=I[i-1]*i;
    scanf("%d",&n);
    long double ans=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&num[i]); f[i][num[i]]=1; r[i]=num[i]; if (num[i]==0) ans++;
    }
    scanf("%d",&m);
    for (;m;m--){
        memset(A,0x00,sizeof A);
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
        long double tot=C(num[k1],k3);
        for (int i=0;i<=r[k1];i++)
            for (int j=0;j<=k3;j++){
                long double k4=f[k1][i]*C(i,j)*C(num[k1]-i,k3-j)/tot;
                if (j<=i) A[i-j]+=k4;
            }
        ans+=A[0]-f[k1][0];
        memcpy(f[k1],A,sizeof A);
        num[k2]+=k3; num[k1]-=k3;
        printf("%.11lf\n",(double)ans);
    }
    return 0;
}