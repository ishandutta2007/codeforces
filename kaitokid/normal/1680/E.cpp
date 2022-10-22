#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[2];
int n,dp[2][200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
      cin>>n;
    cin>>s[0]>>s[1];
    int l=-1,r=-1;
    for(int i=0;i<n;i++)
    if(s[0][i]=='*'||s[1][i]=='*'){r=i;if(l==-1)l=i;}
    dp[0][l]=dp[1][l]=0;
    if(s[0][l]=='*')dp[1][l]++;
    if(s[1][l]=='*')dp[0][l]++;
    for(int i=l+1;i<=r;i++)
    {
        dp[0][i]=dp[1][i]=2+min(dp[0][i-1],dp[1][i-1]);
        if(s[0][i]=='.')dp[1][i]=min(dp[1][i],dp[1][i-1]+1);
        if(s[1][i]=='.')dp[0][i]=min(dp[0][i],dp[0][i-1]+1);
    }

    cout<<min(dp[0][r],dp[1][r])<<endl;

    }

    return 0;
}