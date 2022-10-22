#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100001];
int main(){
    dp[0]=1;
    int t,k,i;
    scanf("%d%d",&t,&k);
    for(i=1;i<=100000;i++){
        dp[i]=dp[i-1];
        if(i>=k)dp[i]+=dp[i-k];
        dp[i]%=1000000007LL;
    }
    for(i=1;i<=100000;i++)dp[i]+=dp[i-1],dp[i]%=1000000007LL;
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",(dp[b]-dp[a-1]+1000000007LL)%1000000007LL);
    }
}