#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200009],c[200009];
ll ans;
set<int>st;

int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<m;i++)st.insert(i);
int u=n/m;
for(int i=0;i<n;i++)
{
cin>>a[i];
int k=a[i]%m;
if(c[k]<u){c[k]++;if(c[k]==u)st.erase(k);continue;}
set<int>::iterator it=st.lower_bound(k);
if(it==st.end())it=st.begin();
int r=*it;
r-=k;
if(r<0)r+=m;
ans+=r;
a[i]+=r;
k=*it;
c[k]++;if(c[k]==u)st.erase(k);
}
cout<<ans<<endl;
for(int i=0;i<n;i++)cout<<a[i]<<" ";
return 0;
}