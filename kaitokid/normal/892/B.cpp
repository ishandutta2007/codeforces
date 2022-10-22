#include <bits/stdc++.h>
using namespace std;
int a[1000009];
 int main()
{
ios::sync_with_stdio(0);
int n,x;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
a[i]++;
a[max(i-x,0)]--;}
for(int i=1;i<=n;i++)
a[i]+=a[i-1];
int ans=0;
for(int i=0;i<n;i++)
if(a[i]==0)ans++;
cout<<ans;
return 0;
}