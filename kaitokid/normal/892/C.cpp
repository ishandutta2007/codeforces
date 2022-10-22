#include <bits/stdc++.h>
using namespace std;
int a[2009];
int bl;
int n;
int f;
int main(){
ios::sync_with_stdio;
cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];f=__gcd(f,a[i]);if(a[i]==1)bl++;}
if(bl)
{
cout<<n-bl;
return 0;
}
if(f!=1){cout<<-1;return 0;}
int ans=10000;
for(int i=0;i<=n;i++)
{int d=a[i];
for(int j=i+1;j<n;j++)
{d=__gcd(d,a[j]);

if(d==1){ans=min(ans,j-i);}


}}
cout<<n+ans-1;
return 0;}