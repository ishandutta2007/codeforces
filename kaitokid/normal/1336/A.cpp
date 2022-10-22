#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,deep[200009];
vector<ll>v[200009];
ll go(int x,int p,int d)
{
    deep[x]=d;
    ll res=1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=p)res+=go(v[x][i],x,d+1);
    deep[x]=deep[x]-res+1;
    return res;
}
int main()
{
ios::sync_with_stdio(0);
int x,y;
cin>>n>>k;
for(int i=1;i<n;i++)
{
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
go(1,0,0);
ll ans=0;
sort(deep+1,deep+n+1);
   for(int i=n;i>n-k;i--)ans+=deep[i];
   cout<<ans;
    return 0;
}