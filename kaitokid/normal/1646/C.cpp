#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v;
int go(ll x)
{
    int r=0;
    while(x>0)
    {
        r++;
        x-=(x&(-x));
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll g=6,h=4;
    while(g<=1000000000000)
    {
        v.push_back(g);
        g*=h;
        h++;
    }
    int u=v.size();
    vector<pair<ll,int> >s;
    for(int msk=0;msk<(1<<u);msk++)
    {
        ll sum=0,p=0;
        for(int i=0;i<u;i++)
        if(msk&(1<<i)){sum+=v[i];p++;}
        s.push_back({sum,p});
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int ans=90;
        for(int i=0;i<s.size();i++)
        {
            if(n<s[i].first)continue;
            ans=min(ans,go(n-s[i].first)+s[i].second);
        }
        cout<<ans<<endl;

    }
    return 0;
}