#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e18+3;
int n,m;
string s;
set<ll>h5,h7;

ll has5(string s)
{
    ll u=1,an=0;
    for(int i=0;i<s.size();i++)
    {
        an+=((s[i]-'a'+2)*u)%mod;
        an%=mod;
        u=(u*5)%mod;

    }
    return an;
}
ll has7(string s)
{
    ll u=1,an=0;
    for(int i=0;i<s.size();i++)
    {
        an+=((s[i]-'a'+2)*u)%mod;
        an%=mod;
        u=(u*7)%mod;

    }
    return an;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){cin>>s;
        h5.insert(has5(s));
        h7.insert(has7(s));
        //cout<<has5(s)<<" "<<has7(s)<<endl;
        }
for(int i=0;i<m;i++)
{
    cin>>s;
    bool bl=false;
    ll q5=has5(s),q7=has7(s);
    ll u5=1,u7=1;
    for(int j=0;j<s.size();j++)
    {
        ll w5=q5,w7=q7;
        w5-=((s[j]-'a'+2)*u5)%mod;
        w7-=((s[j]-'a'+2)*u7)%mod;
        if(w5<0)w5+=mod;
if(w7<0)w7+=mod;
        for(int z=0;z<3;z++)
        {
            if(s[j]-'a'==z)continue;
            ll uu5=(w5+(((z+2)*u5)%mod))%mod;
            ll uu7=(w7+(((z+2)*u7)%mod))%mod;
            //cout<<uu5<<" "<<uu7<<endl;
            if((h5.find(uu5)!=h5.end())&&(h7.find(uu7)!=h7.end())){bl=true;break;}
        }
        u5*=5;
        u5%=mod;
         u7*=7;
        u7%=mod;
        if(bl)break;
    }
    if(bl)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}