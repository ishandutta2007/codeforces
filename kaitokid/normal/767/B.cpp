#include <bits/stdc++.h>
using namespace std ;
vector <long long > a;
int main(){
ios::sync_with_stdio(0);
long long f,e,t,x,ans,time=1000000000000000000;
int n;
cin>>f>>e>>t>>n;
for(int i=0;i<n;i++)
{cin>>x;
a.push_back(x);}
sort(a.begin(),a.end());
long long l=f-1;
int i=0;
while(l+t<=e)
{
if(i==n){cout<<l+1;return 0;}
if(a[i]>l+1){cout<<l+1;return 0;} 
if(l+3-a[i]<time){ans=a[i]-1;time=l+3-a[i];}
l=max(l+1,a[i])+t-1;

i++;




}
cout<<ans;
return 0;}