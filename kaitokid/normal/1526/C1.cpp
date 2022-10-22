#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],n;
bool bl[200009];
bool ch()
{
    ll s=0;
    for(int i=0;i<n;i++)
    {
        if(bl[i])s+=a[i];
        if(s<0)return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    cin>>n;
    vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++){cin>>a[i];
    if(a[i]>=0){bl[i]=true;ans++;}
    else v.push_back({-1*a[i],i});
    }
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
   {
       int u=v[i].second;
       bl[u]=true;
       if(ch())ans++;
       else bl[u]=false;
   }
  cout<<ans;
}