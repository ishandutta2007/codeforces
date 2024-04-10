#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
pair<int,int>cal(pair<int,int>x,pair<int,int>y)
{
    if(x.first<y.first)return x;
    if(y.first<x.first)return y;
    x.second=(x.second+y.second)%mod;
    return x;
}
pair<int,int>dp[509];
bool bl[509];
int n,m;
pair<int,int>go(int x)
{
    if(x<m-1)return{0,1};
    if(dp[x].first!=-1)return dp[x];
    if(!bl[x])return go(x-1);
    dp[x]={100000000,0};
    for(int i=x;i>x-m;i--)
    {
        if(!bl[i])continue;
      //  cout<<333<<" "<<x<<" "<<i<<endl;
        pair<int,int>h=go(i-m);
        h.first++;
        dp[x]=cal(dp[x],h);
    }
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int qq;
    cin>>qq;
    while(qq--)
    {
        string s,t;
        cin>>s>>t;
        n=s.size(),m=t.size();
        vector<int>g;
        for(int i=0;i<n;i++)bl[i]=false;
        for(int i=0;i+m<=n;i++)
        {
             bl[i+m-1]=true;
            for(int j=0;j<m;j++)if(s[i+j]!=t[j]){bl[i+m-1]=false;break;}

        }
        for(int i=0;i<=n;i++)dp[i]={-1,-1};
        pair<int,int>f=go(n-1);
        cout<<f.first<<" "<<f.second<<endl;

    }


    return 0;
}