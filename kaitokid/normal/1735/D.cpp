#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[30];
ll cal(vector<int>v)
{
    ll res=0;
    for(int i=0;i<v.size();i++)
        res+=v[i]*p[i];
    return res;
}
vector<int>mrg(vector<int>a,vector<int>b)
{
    vector<int>res;
    for(int i=0;i<a.size();i++)
    {if(a[i]==b[i]){res.push_back(a[i]);continue;}
    for(int j=0;j<3;j++)if((j!=a[i])&&(j!=b[i])){res.push_back(j);break;}
    }
    return res;
}
vector<int>a[1009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<22;i++)
        p[i]=3*p[i-1];
   int n,k;
   cin>>n>>k;
   for(int i=0;i<n;i++)
    for(int j=0;j<k;j++)
   {
       int x;
       cin>>x;
       a[i].push_back(x);
   }
   map<ll,ll>mp;
   for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++)
      mp[cal(mrg(a[i],a[j]))]++;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll u=mp[cal(a[i])];
        ans+=u*(u-1)/2;

    }
    cout<<ans;
    return 0;
}