#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int dp[309];
int mex(vector<int>v)
{
    sort(v.begin(),v.end());
    int m=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==m){m++;continue;}
    }
    return m;
}
int go(int x)
{
    while(x>140)x-=68;
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1]=0;
    dp[1]=0;
   for(int i=2;i<210;i++)
    {
        vector<int>v;
        for(int j=1;j<i;j++)
        {
            v.push_back(dp[j-1]^dp[i-j-1]);
        }
        dp[i]=mex(v);
       // cout<<i<<" "<<dp[i]<<endl;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int d=0;
        for(int i=0;i<n;i++)if(s[i]=='R')d++;
        else d--;
        if(d>0){cout<<"Alice"<<endl;continue;}
        if(d<0){cout<<"Bob"<<endl;continue;}
        int ans=0;
        int l=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1]){l++;continue;}
            ans^=go(l);
            l=1;

        }
        ans^=go(l);
        if(ans==0)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;

    }

    return 0;

}