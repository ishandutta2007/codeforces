#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int n,m;
string s;
pair<string,ll> go(int x)
{
    if(x>m)return {"",1};
    pair<string,ll> u=go(2*x),v=go(2*x+1);
    if(u!=v){
       if(u>v)swap(u,v);
       ll p=(u.second*v.second*2)%mod;
    string g=s[x]+u.first+v.first;
    //cout<<x<<" "<<g<<" "<<p<<endl;
    return {g,p};

    }
    ll p=u.second;
    p=p*(p-1+mod)%mod;
    p+=u.second;
    p%=mod;
    string g=s[x]+u.first+v.first;

    //cout<<x<<" "<<g<<" "<<p<<endl;
    return {g,p};

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    m=s.size();
    s='&'+s;

    ll ans=go(1).second;
    cout<<ans;
    return 0;

}