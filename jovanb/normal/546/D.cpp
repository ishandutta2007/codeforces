#include <bits/stdc++.h>

using namespace std;
long long dp[5000005];
bool prime[5000005];
long long dv[5000005];
int main()
{
    long long j,i,a,b;
    dv[1]=1;
    for(i=2;i<=2300;i++){
        if(prime[i]==false){
            for(j=i;j<=5000000;j+=i){
                if(dv[j]==0)dv[j]=i;
                prime[j]=true;
            }
        }
        dp[i]=(dp[i/dv[i]]+1-dp[i/dv[i]-1])+dp[i-1];
    }

    for(i=2301;i<=5000000;i++){
        if(prime[i]==false)dv[i]=i;
        dp[i]=(dp[i/dv[i]]+1-dp[i/dv[i]-1])+dp[i-1];
    }
    long t;
    scanf("%ld",&t);
    for(i=0;i<t;i++){
        scanf("%lld",&a);
        scanf("%lld",&b);
        printf("%lld \n",dp[a]-dp[b]);
    }
    return 0;
}