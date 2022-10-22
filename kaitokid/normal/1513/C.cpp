#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll fr[11][200009];
ll res[200009];
int main()
{
    ios::sync_with_stdio(0);
    fr[0][0]=fr[1][0]=1;
    res[0]=2;
    for(int i=1;i<=200002;i++)
       {
        fr[1][i]=(fr[0][i-1]+fr[9][i-1])%mod;
           fr[0][i]=fr[9][i-1];
           for(int j=2;j<10;j++)fr[j][i]=fr[j-1][i-1];
        ll u=0;
        for(int j=0;j<10;j++)u=(u+fr[j][i])%mod;
        res[i]=u;
       }

    int t;
    cin>>t;
    while(t--)
    {
   ll n,m,ans=0;
   cin>>n>>m;
   while(n)
   {
       int u=n%10;
       n/=10;
       if(m<10-u){ans=(ans+1)%mod;continue;}
       ans+=res[m-(10-u)];
       ans%=mod;

   }
   cout<<ans<<endl;
    }
    return 0;
}