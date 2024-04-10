#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[7009],b[7009];
vector<ll> s;
map <ll,int> vis;
int n;
ll ans;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    if(vis[a[i]]==1)s.push_back(a[i]);
    vis[a[i]]++;
}
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++)
  for(int j=0;j<s.size();j++)
  if((a[i]&s[j])==a[i]){ans+=b[i];break;}
    cout<<ans;
    return 0;
}