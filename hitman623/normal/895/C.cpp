#include <bits/stdc++.h>
#define pb push_back
#define vl vector < int >
#define pll pair < int , int >
#define vll vector < pll >
#define x first
#define y second
#define ml map < int , int >
#define mll map < pll , int >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int h=1e9+7;
int po(int a,int b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    int ans=1;
    while(b)
    {
        if(b&1) ans=(1LL*ans*a)%h;
        a=(1LL*a*a)%h;
        b>>=1;
    }
    return ans;
}
int n,x,i,p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67},m=19,d=(1<<m),vv[600006],dp[71][600000],j,pp[71];
int main()
{
    io
    cin>>n;
    vll v;
    for(i=0;i<n;++i)
    {
        cin>>x;
        int dd=0;
        for(j=0;j<m;++j)
        {
            int temp=x,c=0;
            while(temp%p[j]==0) c++,temp/=p[j];
            if(c&1) dd|=(1<<j);
        }
        vv[dd]++;
    }
    for(i=0;i<d;++i)
    if(vv[i] || !i)
    v.pb({i,vv[i]});
    for(i=1;i<v.size();++i)
    pp[i]=po(2,v[i].y-1);
    dp[0][0]=po(2,vv[0]);
    for(i=1;i<v.size();++i)
    for(j=0;j<d;++j)
    dp[i][j]=(dp[i][j]+1LL*(dp[i-1][j]+dp[i-1][j^v[i].x])*pp[i])%h;
    cout<<(dp[i-1][0]-1+h)%h;
    return 0;
}