#include <bits/stdc++.h>

using namespace std;
long br[100005];
long long dp[100005];
int main()
{
    long long x,n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        br[x]++;
    }
    dp[0]=0;
    dp[1]=br[1];
    for(i=2;i<=100000;i++){
        dp[i]=max(dp[i-1],dp[i-2]+i*br[i]);
    }
    cout<<dp[100000];
    return 0;
}