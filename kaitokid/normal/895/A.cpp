#include <bits/stdc++.h>
using namespace std;
int a[10009];
long long x,sum,n,ans=9999999;
int main(){

cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{

sum=0;
for(int j=i;j<n;j++)
{sum+=a[j];
ans=min(ans,abs(360-2*sum));


}}
cout<<ans;
return 0;}