#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<int,int>,int> mp;
int dp[600009];
int ch(int x,int y,int i)
{
    int r=__gcd(x,y);
    x/=r;
    y/=r;
    int ans=mp[{x,y}];
    mp[{x,y}]=i;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{int n;
cin>>n;
mp.clear();
int u=0,v=0;
for(int i=1;i<=n;i++)
{
    char c;
    cin>>c;
    if(c=='D')u++;else v++;
    int q=ch(u,v,i);
    dp[i]=dp[q]+1;
    cout<<dp[i]<<" ";
}
cout<<endl;
}
    return 0;
}