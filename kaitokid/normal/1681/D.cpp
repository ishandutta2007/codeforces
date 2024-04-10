#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map<ll,int>mp;
bool h[11];
int go(ll x)
{
    if(mp[x]!=0)return mp[x];

    vector<int>dd;
    ll g=x;
    while(g>0)
    {
        dd.push_back(g%10);
        g/=10;
    }
    if(dd.size()==n)return 0;

    int r=200;

    for(int i=0;i<dd.size();i++)
    {
        if(dd[i]==0 ||dd[i]==1)continue;
        r=min(r,1+go(x*dd[i]));

    }
    return mp[x]=r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x;
    cin>>n>>x;

    int ans=go(x);
    if(ans>100)ans=-1;
    cout<<ans;
    return 0;
}