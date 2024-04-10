#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans;
ll n,m;
ll x[200009],pp[200009],d[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>x[0];
    for(int i=1;i<m;i++)
    {
        cin>>x[i];
  if(x[i]==x[i-1])continue;
  ll res=abs(x[i]-x[i-1]);
  ans+=res;
  d[max(x[i],x[i-1])]+=min(x[i-1],x[i])-res;
  d[min(x[i-1],x[i])]+=max(x[i],x[i-1])-res-1;
  pp[min(x[i],x[i-1])+1]-=1;
  pp[max(x[i],x[i-1])]+=1;
    }
    for(int i=1;i<=n;i++){pp[i]+=pp[i-1];cout<<ans+d[i]+pp[i]<<" ";}
    return 0;
}