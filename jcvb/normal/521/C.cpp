#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
#define mo 1000000007
#include<set>
#include<vector>
#include<map>
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}
int n,k;
char str[100005];
int a[100005];
int p10[100005];
int fact[100005];
int c(int a,int b){
    if(b>a || b<0)return 0;
    return 1ll*fact[a]*qp(fact[b],mo-2)%mo*qp(fact[a-b],mo-2)%mo;
}
int main()
{
    p10[0]=1;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)p10[i]=1ll*p10[i-1]*10%mo;
    fact[0]=1;
    for (int i=1;i<=n+2;i++)fact[i]=1ll*fact[i-1]*i%mo;
    scanf("%s",str+1);
    for (int i=1;i<=n;i++)a[i]=str[i]-'0';
    a[0]=0;
    if(k==0){
        int res=0;
        for (int i=1;i<=n;i++)res=(1ll*res*10+a[i])%mo;
        printf("%d\n",res);
        return 0;
    }
    for (int i=1;i<=n;i++)a[i]=a[i]+a[i-1];
    int su=0;
    for (int i=1;i<=n;i++)
        su=(su+1ll*(a[i]-a[i-1])*c(i-1,k)%mo*p10[n-i])%mo;
    for (int j=0;j<=n-2;j++)
        su=(su+1ll*c(n-2-j,k-1)*p10[j]%mo*a[n-1-j])%mo;
    printf("%d\n",su);
    return 0;
}