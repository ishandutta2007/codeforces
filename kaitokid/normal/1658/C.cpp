#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int p[100009];
int g[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<2000;i++)p[i]=(p[i-1]*i)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int u=0,r=-1;
        for(int i=1;i<=n;i++)
            {cin>>p[i];
            u+=(p[i]==1);
            if(p[i]==1)r=i;
            }
          if(u!=1){cout<<"NO"<<endl;continue;}
          for(int i=r;i>=1;i--)g[r-i+1]=p[i];
          for(int i=n;i>r;i--)g[r+n-i+1]=p[i];
          bool bl=true;
          for(int i=2;i<=n;i++)
          {
              if(g[i]>2+n-i )bl=false;
            if(i<n && g[i]>g[i+1]+1)bl=false;
          }
          if(bl)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;

    }
    return 0;
}