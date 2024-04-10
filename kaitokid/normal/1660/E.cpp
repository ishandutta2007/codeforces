#include <bits/stdc++.h>
using namespace std;
string s[4009];
int n;
int dp[4009][4009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int c=0;
        for(int i=0;i<n;i++){cin>>s[i];
        for(int j=0;j<n;j++)if(s[i][j]=='1')c++;
        s[i]+=s[i];}
        for(int i=n;i<2*n;i++)s[i]=s[i-n];
        int m=n;
        n*=2;
        int mx=0;
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=0;
                if((i+1<n) && (j+1<n))dp[i][j]=dp[i+1][j+1];
                if((i+m<n) && (j+m < n) && (s[i+m][j+m]=='1'))dp[i][j]--;
                if(s[i][j]=='1')dp[i][j]++;
                mx=max(mx,dp[i][j]);

            }
      int ans=c+m-2*mx;
      cout<<ans<<endl;

    }
    return 0;
}