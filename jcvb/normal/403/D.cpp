#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define mo 1000000007;
int c[2005][2005]={0};
int fac[2005];
int f[2005][2005]={0};
void inic(){
    c[0][0]=1;
    for (int i=1;i<=1002;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
    }
}

int A(int a,int b){
    if(a>b)return 0;
    return c[b-1][a-1];
}
int B(int a,int b){
    return 1ll*f[b][a]*fac[a]%mo;
}
void inif(){
    f[0][0]=1;
    for (int i=1;i<=1100;i++)
        for (int k=1;k<=i;k++){
            f[i][k]=(f[i-k][k-1]+f[i-k][k])%mo;
        }
}

int main()
{
    int tes;
    inic();
    inif();
    fac[0]=1;
    for (int i=1;i<=1002;i++)fac[i]=1ll*fac[i-1]*i%mo;
    scanf("%d",&tes);
    while(tes--){
        int k,n;
        scanf("%d%d",&n,&k);
        if(k>50)printf("0\n");
        else{
            int ans=0;
            for (int i=0;i<=n+1;i++){
                ans=(ans+1ll*A(k+1,i)*B(k,n+1-i+k))%mo;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}