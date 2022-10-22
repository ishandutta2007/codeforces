#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
ll n,l,r,k;
cin>>n>>l>>r>>k;
ll x;
vector<ll>v;
for(int i=0;i<n;i++)
{
    cin>>x;
    if(x>=l && x<=r)v.push_back(x);
}
sort(v.begin(),v.end());
int ans=0;
for(int i=0;i<v.size();i++)
{
    k-=v[i];
    if(k<0)break;
    ans++;
}
cout<<ans<<endl;
}
	return 0;
}