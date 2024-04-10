#include<bits/stdc++.h>
using namespace std;
long long dp[5005][2];
long long dp2[5005][2];
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    dp[0][0]=1;
    while(a--)
    {
        char c;
        cin>>c;
        if(c=='s')
        {
            long long suma=0;
            for(int x=5001;x>=0;x--)
            {
                suma+=dp[x][0];
                dp2[x][0]=(suma+dp[x][1])%mod;
            }
        }
        else
        {
            long long suma=0;
            for(int x=5002;x>=1;x--)
            {
                suma+=dp[x-1][0];
                dp2[x][1]=(suma+dp[x-1][1])%mod;
            }
        }
        for(int x=0;x<=5002;x++)
        {
            dp[x][0]=dp2[x][0];
            dp[x][1]=dp2[x][1];
            dp2[x][0]=0;
            dp2[x][1]=0;
        }
    }
    long long suma=0;
    for(int x=0;x<=5002;x++)
        suma+=dp[x][0];
        cout<<suma%mod;
    return 0;
}