#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
vector<int>p[100009];
int d[100009];
int lcm(int x,int y)
{
    ll r=x*1LL*y;
    r/=__gcd(x,y);
    return (r%mod);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   for(int i=1;i<=100000;i++)
        for(int j=2*i;j<=100000;j+=i)p[j].push_back(i);
   ll ans=0;
   int n;
   cin>>n;
   for(int i=2;i<n;i++)
   {
       int u=p[i].size()-1;
       for(int j=u;j>=0;j--)
       {

           d[j]=i/p[i][j]-1;
           for(int h=j+1;h<=u;h++)
            if((p[i][h]%p[i][j])==0)d[j]-=d[h];
         ans+=d[j]*1LL*lcm(p[i][j],n-i);
         ans%=mod;
       }
   }
   cout<<ans;
    return 0;
}