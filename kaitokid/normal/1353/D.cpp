#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,a[200009];
priority_queue <pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pr;
int main()
{ios::sync_with_stdio(0);
cin>>t;

while(t--)
{
    cin>>n;
pr.push({-n,1});
int v=0;
while(!pr.empty())
{
    v++;
    pair<ll,ll> g=pr.top();
    pr.pop();
    ll l=g.second;
    ll r=-g.first+l-1;
    //cout<<l<<" "<<r<<" "<<v<<endl;
    ll mid=(l+r)/2;
    a[mid]=v;
if(mid>l)pr.push({-mid+l,l});
if(r>mid)pr.push({-r+mid,mid+1});

}
for(int i=1;i<=n;i++)cout<<a[i]<<" ";
cout<<endl;
}
    return 0;
}