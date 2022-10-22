#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
map<ll,ll> a;
ll ans;
set<ll>st;
int main() {
ios::sync_with_stdio(0);
ll n,k;
cin>>n>>k;
ll i=0;
while(n!=0)
{

if(n%2!=0){st.insert(i);a[i]++;ans++;}
i++;
n/=2;


}

if(st.size()>k){cout<<"No";return 0;}
ll u=*(--st.end());
while(k-ans>=a[u])
{

a[u-1]+=a[u]*2;
ans+=a[u];
a[u]=0;
st.erase(u);
st.insert(u-1);
u--;


}
cout<<"Yes\n";
set<ll>::iterator it2=(st.end());
it2--;
for(set<ll>::iterator it=it2;it!=st.begin();it--)
{

for(int i=0;i<a[*it];i++)cout<<(*it)<<" ";



}
ll d=(*st.begin());
for(int i=0;i<a[d]-1;i++)cout<<d<<" ";
if(ans==k){cout<<d;return 0;}
int p=ans;
while(p<k)
{d--;
cout<<d<<" ";
p++;}
cout<<d;
 return 0; }