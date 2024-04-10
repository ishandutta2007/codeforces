#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,r[100009],l[100009],ans;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
ans=n;
for(int i=0;i<n;i++)cin>>r[i]>>l[i];
sort(r,r+n);
sort(l,l+n);
for(int i=0;i<n;i++)ans+=max(l[i],r[i]);
cout<<ans;
   return 0;
}