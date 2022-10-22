#include <bits/stdc++.h>

using namespace std;
long long dp[100005];
int main()
{
    long long t,k,a,b,i;
    cin>>t>>k;
    dp[0]=1;
    for(i=1;i<k;i++)dp[i]=1;
    for(i=k;i<=100000;i++){dp[i]=dp[i-1]+dp[i-k];dp[i]%=1000000007;}
    for(i=1;i<=100000;i++){dp[i]+=dp[i-1];dp[i]%=1000000007;}
    for(i=0;i<t;i++){
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+1000000007)%1000000007<<endl;
    }
    return 0;
}