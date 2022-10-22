#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
pair<pair<double,pair<double,double> >,ll>a[500009];
ll n;
bool vis[500009];
bool bl(pair<pair<double,pair<double,double> >,ll> x,pair<pair<double,pair<double,double> >,ll> y)
{
    if(x.first.first<y.first.first)return true;
      if(x.first.first>y.first.first)return false;
        if(x.first.second.first<y.first.second.first)return true;
         if(x.first.second.first>y.first.second.first)return false;
          if(x.first.second.second<y.first.second.second)return true;
return false;
}
int main()
{
   ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i].first.first>>a[i].first.second.first>>a[i].first.second.second;
    a[i].second=i+1;
}
sort(a,a+n,bl);
ll i=0;
while(i<n-1)
{
if((a[i].first.first==a[i+1].first.first)&&(a[i].first.second.first==a[i+1].first.second.first))
    {cout<<a[i].second<<" "<<a[i+1].second<<endl;vis[i]=true;vis[i+1]=true;i+=2;continue;}
i++;
}
i=0;
while(i<n-1)
{
    if(vis[i]){i++;continue;}
    int j=i+1;
    while(j<n){if(!vis[j])break; j++;}
    if(j==n)break;
    if(a[i].first.first==a[j].first.first)
{cout<<a[i].second<<" "<<a[j].second<<endl;vis[i]=true;vis[j]=true;i=j+1;continue;}
i=j;
}
ll u=0;
i=0;
while(i<n)
{
    if(vis[i]){i++;continue;}
    if(u%2==0)cout<<a[i].second<<" ";
    else cout<<a[i].second<<endl;
    u++;
    i++;
}
    return 0;
}