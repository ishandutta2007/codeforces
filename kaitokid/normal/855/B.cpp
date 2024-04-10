#include <bits/stdc++.h>
using namespace std;
long long mn=10000000009,mx=-10000000009;
long long num[100009],ms[100009],mo[100009],ms2[100009],mo2[100009];
int main()
{
long long n,a,b,c,x;
cin>>n>>a>>b>>c;
for(int i=0;i<n;i++)
{cin>>num[i];}
for(int i=0;i<n;i++)
{
mn=min(num[i],mn);
mx=max(num[i],mx);
ms[i]=mx;
mo[i]=mn;



}
mn=10000000009,mx=-10000000009;
for(int i=n-1;i>=0;i--)
{
mn=min(num[i],mn);
mx=max(num[i],mx);
ms2[i]=mx;
mo2[i]=mn;



}
long long ans=-4000000000000000000;
for(int i=0;i<n;i++)
{long long  res =b*num[i];
res += max(a*ms[i],a*mo[i]);
res+=max(c*ms2[i],c*mo2[i]);
ans=max(ans,res);}
cout<<ans;
return 0;}