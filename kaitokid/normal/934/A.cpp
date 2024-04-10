#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[55],b[55],r[55];
int main()
{
ios::sync_with_stdio(0);
for(int i=0;i<55;i++)r[i]=-1900000000000000000;
cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)r[i]=max(r[i],a[i]*b[j]);
sort(r,r+n);
cout<<r[n-2];
return 0;}