#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,r,a,m,h[100009];
map<ll,ll>mp,co;
set<ll>st;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>a>>r>>m;
    m=min(m,a+r);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
        mp[h[i]]+=h[i];
        co[h[i]]++;
    st.insert(h[i]);
    }

    sort(h,h+n);
    ll d=0,u=0;
    for(int i=n-1;i>=0;i--)
    {
        d+=h[i];
        u++;
        st.insert(d/u);
        st.insert((d+u-1)/u);
    }
    st.insert(0);
    set<ll>::iterator it=st.begin(),it2;
    it2=it;
    it2++;
    ll ans=1e18;
    while(it2!=st.end())
    {
        ll x=(*it2),y=(*it);
        mp[x]+=mp[y];
        co[x]+=co[y];
    ll s1=co[x];
    ll s2=n-co[x];
    ll f1=mp[x];
    ll f2=d-mp[x];
s1=s1*x-f1;
s2=f2-s2*x;
ll res;
if(s1<s2)res=s1*m+(s2-s1)*r;
else res =s2*m+(s1-s2)*a;
   ans=min(ans,res);
    it++;
    it2++;
    }
    cout<<ans;
    return 0;
}