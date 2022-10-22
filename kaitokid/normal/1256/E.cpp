#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,ans[200009],le[200009],res[200009];
pair<ll,ll> a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
ans[i+1]=-1;
    }
    sort(a,a+n);

for(int i=0;i<n;i++)
{
    if(ans[i]==-1)continue;
    if(ans[i+3]==-1||ans[i+3]>ans[i]+a[i+2].first-a[i].first){ans[i+3]=ans[i]+a[i+2].first-a[i].first;le[i+2]=3;}
      if(ans[i+4]==-1||ans[i+4]>ans[i]+a[i+3].first-a[i].first){ans[i+4]=ans[i]+a[i+3].first-a[i].first;le[i+3]=4;}
if(ans[i+5]==-1||ans[i+5]>ans[i]+a[i+4].first-a[i].first){ans[i+5]=ans[i]+a[i+4].first-a[i].first;le[i+4]=5;}
}
ll k=0,f=0;
for(int i=n-1;i>=0;i--)
{
    if(f==0){k++;f=le[i];}
    res[a[i].second]=k;
    f--;
}
cout<<ans[n]<<" "<<k<<endl;
for(int i=0;i<n;i++)cout<<res[i]<<" ";
    return 0;
}