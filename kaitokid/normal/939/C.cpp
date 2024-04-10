#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int n,a[100009],num[100009];
int main() 
{ 
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int s,f;
cin>>s>>f;
for(int i=1;i<=n;i++)
{
int st=s-i+1;
int fi=f-i+1;
if(st<1)st+=n;
if(fi<1)fi+=n;
if(fi<st)num[1]+=a[i];
num[st]+=a[i];
num[fi]-=a[i];


}
int ans,res=0;
for(int i=1;i<=n;i++)

{
num[i]+=num[i-1];

if(res<num[i]){res=num[i];ans=i;}


}
cout<<ans;
return 0 ;}