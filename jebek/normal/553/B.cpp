#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long n,k,dp[100],last=1;

int main()
{
    dp[0]=1,dp[1]=1;
    for(int i=1;i<=50;i++)
        dp[i]=dp[i-1]+dp[i-2];
    cin>>n>>k;
    for(int i=n;i>0;i--)
    {
        if(dp[i-1]<k)
        {
            cout<<n-i+2<<" "<<n-i+1<<" ";
            k-=dp[i-1];
            i--;
        }
        else
            cout<<n-i+1<<" ";
    }
}