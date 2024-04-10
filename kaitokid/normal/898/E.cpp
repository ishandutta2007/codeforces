#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int a[2];
ll x;
vector<ll> v;
int zero;
int main()
{ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
ll g=sqrt(x);
if(x==0)zero++;
if(g*g==x){a[0]++;continue;}
a[1]++;
v.push_back(min((g+1)*(g+1)-x,x-g*g));
}
if(a[0]==a[1]){cout<<0;return 0;}
if(a[0]>a[1]){
int l=(a[0]-a[1])/2;
int v=a[0]-zero;
cout<<l+max(0,l-v);

return 0;}

sort(v.begin(),v.end());
ll ans=0;
for(int i=0;i<(a[1]-a[0])/2;i++)ans+=v[i];
cout<<ans;
return 0;}