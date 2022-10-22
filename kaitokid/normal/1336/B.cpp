#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans;
vector<ll>st1,st2,st3;
void ch(ll x,ll y,ll z)
{
    //cout<<x<<" "<<y<<" "<<z<<endl;
    ll res=(x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
    ans=min(ans,res);
}
int main()
{
ios::sync_with_stdio(0);
ll t,n1,n2,n3;
cin>>t;
while(t--)
{
    st1.clear();
    st2.clear();
    st3.clear();
    ll x;
    cin>>n1>>n2>>n3;
    for(int i=0;i<n1;i++){cin>>x;st1.push_back(x);}
for(int i=0;i<n2;i++){cin>>x;st2.push_back(x);}
for(int i=0;i<n3;i++){cin>>x;st3.push_back(x);}
sort(st1.begin(),st1.end());
sort(st2.begin(),st2.end());
sort(st3.begin(),st3.end());
ans=3e18;
for(int i=0;i<n1;i++)
{
    ll u=st1[i];
vector<ll>::iterator it1=lower_bound(st2.begin(),st2.end(),u),it2=lower_bound(st3.begin(),st3.end(),u);
if(it2!=st3.end()&&it1!=st2.end())ch(u,(*it1),*(it2));
if(it2!=st3.begin()&&it1!=st2.end()){it2--;ch(u,(*it1),*(it2));it2++;}
if(it1!=st2.begin()&&it2!=st3.end()){it1--;ch(u,(*it1),*(it2));it1++;}
if(it1!=st2.begin()&&it2!=st3.begin()){it1--;it2--;ch(u,(*it1),*(it2));}
}
for(int i=0;i<n2;i++)
{
    ll u=st2[i];
vector<ll>::iterator it1=lower_bound(st1.begin(),st1.end(),u),it2=lower_bound(st3.begin(),st3.end(),u);
if(it2!=st3.end()&&it1!=st1.end())ch(u,(*it1),*(it2));
if(it2!=st3.begin()&&it1!=st1.end()){it2--;ch(u,(*it1),*(it2));it2++;}
if(it1!=st1.begin()&&it2!=st3.end()){it1--;ch(u,(*it1),*(it2));it1++;}
if(it1!=st1.begin()&&it2!=st3.begin()){it1--;it2--;ch(u,(*it1),*(it2));}
}
for(int i=0;i<n3;i++)
{
    ll u=st3[i];
vector<ll>::iterator it1=lower_bound(st1.begin(),st1.end(),u),it2=lower_bound(st2.begin(),st2.end(),u);
if(it2!=st2.end()&&it1!=st1.end())ch(u,(*it1),*(it2));
if(it2!=st2.begin()&&it1!=st1.end()){it2--;ch(u,(*it1),*(it2));it2++;}
if(it1!=st1.begin()&&it2!=st2.end()){it1--;ch(u,(*it1),*(it2));it1++;}
if(it1!=st1.begin()&&it2!=st2.begin()){it1--;it2--;ch(u,(*it1),*(it2));}
}
cout<<ans<<endl;
}
    return 0;
}