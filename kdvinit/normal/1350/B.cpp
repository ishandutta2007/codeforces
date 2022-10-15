/*

Test Case -
1
7
1 4 2 3 6 4 9

Mistake - 
1. 2Loosing Confidence early;
2. Not thinking of dp;
3. Using 2 condition with && in for loop;
4. not thinking of iterating by multiples;


*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int s[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        int dp[n+1]={0},mx=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i]+1;
            mx=max(mx,dp[i]);
            for(int j=i*2;j<=n;j+=i)
            {
                if(s[i]<s[j]) dp[j]=max(dp[j],dp[i]);
            }
            //cout<<"dp["<<i<<"] - "<<dp[i]<<endl;
        }
        cout<<mx<<endl;
    }
    return 0;
}