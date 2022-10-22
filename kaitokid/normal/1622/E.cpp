#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[12];
string qq[12];
int num[2003];
int s[10009],dd[100009];
ll w[12],g[10009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<2000;i++)
        for(int j=0;j<15;j++)if(i&(1<<j))num[i]++;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)a[i]=w[i]=0;
        for(int i=0;i<=m;i++)s[i]=g[i]=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>qq[i];

        for(int j=0;j<m;j++)
        for(int i=n-1;i>=0;i--)
        {
            s[j]*=2;
            if(qq[i][j]=='1'){s[j]++;w[i]++;g[j]++;}

        }

      ll ans=LLONG_MIN,bst=0;
      for(int msk=0;msk<(1<<n);msk++)
      {
          ll res=0;
          for(int i=0;i<n;i++)
          {
              if(msk&(1<<i))res-=a[i];
              else res+=a[i];
          }
          vector<ll>hh;
          for(int i=0;i<m;i++)
          {
                int r=num[(s[i]&msk)];
                int p=g[i]-r;
                hh.push_back(r-p);
          }
         sort(hh.begin(),hh.end());
         for(ll i=0;i<m;i++)
            res+=(i+1)*hh[i];
         if(res>ans){ans=res,bst=msk;}
      }
      vector<pair<int,int> >hh;
          for(int i=0;i<m;i++)
          {
                int r=num[(s[i]&bst)];
                int p=g[i]-r;
                hh.push_back({r-p,i});
          }
         sort(hh.begin(),hh.end());
         for(int i=0;i<m;i++)dd[hh[i].second]=i+1;
         for(int i=0;i<m;i++)cout<<dd[i]<<" ";
         cout<<endl;

    }
    return 0;
}