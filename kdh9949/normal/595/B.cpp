#include<stdio.h>
#include<algorithm>
using namespace std;

int n,k;
long long a[101010],b[101010];
long long ans=1,mod=1000000007;
long long tenk[11];

int main(){
    scanf("%d%d",&n,&k);
    tenk[0]=1;
    for(int i=1;i<=k;i++)tenk[i]=tenk[i-1]*10;
    for(int i=0;i<n/k;i++){
        scanf("%I64d",a+i);
    }
    for(int i=0;i<n/k;i++){
        scanf("%I64d",b+i);
    }
    for(int i=0;i<n/k;i++){
        long long t=(tenk[k]-1)/a[i];
        if(b[i]){
            t-=(tenk[k-1]*(b[i]+1)-1)/a[i]-(tenk[k-1]*b[i]-1)/a[i];
            ans*=(t+1);
        }
        else{
            t-=(tenk[k-1]-1)/a[i];
            ans*=t;
        }
        ans%=mod;
    }
    printf("%I64d",ans);
}