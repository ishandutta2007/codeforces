#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;
int n,m;
long arr[505][505];
int isprime[100105];
long prime[100105];
int tot=0;
int linear_prime(int n){
     for (int i=2;i<=n;i++)isprime[i]=1;
     for (int i=2;i<=n;i++){
         if(isprime[i])prime[tot++]=i;
         for (int j=0;j<tot && prime[j]*i<=n;j++){
             isprime[prime[j]*i]=0;
             if(!(i%prime[j]))break;
         }
     }
     return tot;
}
int main()
{
    scanf("%d%d",&n,&m);
    linear_prime(100102);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            long t;
            scanf("%ld",&t);
            for (int k=0;;k++)
                if(isprime[t+k]){
                                 arr[i][j]=k;
                                 break;
                }
        }
    long ans=2000000000;
    for (int i=1;i<=n;i++){
        long tmp=0;
        for (int j=1;j<=m;j++)tmp+=arr[i][j];
        if(tmp<ans)ans=tmp;
    }
    for (int j=1;j<=m;j++){
        long tmp=0;
        for (int i=1;i<=n;i++)tmp+=arr[i][j];
        if(tmp<ans)ans=tmp;
    }
    printf("%ld\n",ans);
    return 0;
}