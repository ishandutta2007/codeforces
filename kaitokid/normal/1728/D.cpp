#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int dp[2009][2009],n;
int go(int l,int r)
{
    if(dp[l][r]!=-1)return dp[l][r];
    if(r==(l+1)){if(s[l]==s[r])return dp[l][r]=0; return dp[l][r]=1;}
    int u1=go(l+1,r-1);
    if(u1==0)
    {
        if(s[l]!=s[r])u1=1;
    }
    int u2=go(l+2,r);
    if(u2==0)
    {
        if(s[l]<s[l+1])u2=1;
        if(s[l]>s[l+1])u2=2;
    }
    int u3=go(l,r-2);
    if(u3==0)
    {
        if(s[r]<s[r-1])u3=1;
        if(s[r]>s[r-1])u3=2;
    }
    if((u1==1)&&(u2==1))return dp[l][r]=1;
    if((u1==1)&&(u3==1))return dp[l][r]=1;
    if((u1!=2)&&(u2!=2))return dp[l][r]=0;
    if((u1!=2)&&(u3!=2))return dp[l][r]=0;
    return dp[l][r]=2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)dp[i][j]=-1;
        int u=go(0,n-1);
        if(u==0){cout<<"Draw"<<endl;continue;}
        if(u==1){cout<<"Alice"<<endl;continue;}
        cout<<"Bob"<<endl;

    }
    return 0;
}