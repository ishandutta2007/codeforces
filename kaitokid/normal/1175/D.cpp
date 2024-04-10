#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[1000009],ans,k,n;

int main()
{
ios::sync_with_stdio(0);
cin>>n>>k;
for(ll i=0;i<n;i++)cin>>sum[i];
for(ll i=n-1;i>=0;i--){sum[i]+=sum[i+1];}

sort(sum+1,sum+n);
ans=sum[0];
for(int i=n-1;i>n-k;i--){ans+=sum[i];}

cout<<ans;
return 0;
}