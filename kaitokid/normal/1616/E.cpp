#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[200009],n;
string s,t;
vector<ll>v[30];
void add(int x)
{
    while(x<=n)
    {
        bit[x]--;
        x+=(x&(-x));
    }
}
ll cal(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
    cin>>n>>s>>t;
    s='#'+s;
    t='#'+t;
    for(int i=0;i<=n+10;i++)bit[i]=0;
    for(int i=0;i<28;i++)v[i].clear();
    for(int i=n;i>0;i--)v[s[i]-'a'].push_back(i);
    ll ans=LLONG_MAX,res=0;
    for(int i=1;i<=n;i++)
    {
    for(int j=0;j<int(t[i]-'a');j++)
    {
        if(v[j].empty())continue;
        ans=min(ans,res+v[j].back()+cal(v[j].back())-1);
    }
    if(v[t[i]-'a'].empty())break;
    res+=v[t[i]-'a'].back()+cal(v[t[i]-'a'].back())-1;
    add(v[t[i]-'a'].back());
    v[t[i]-'a'].pop_back();
    }
    if(ans==LLONG_MAX)ans=-1;
    cout<<ans<<endl;

    }

    return 0;
}