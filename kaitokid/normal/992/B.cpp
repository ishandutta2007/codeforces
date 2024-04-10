#include<bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(0);
int l,r,x,y;
cin>>l>>r>>x>>y;
if(x==y)
{
if(x<=r&&x>=l){cout<<1;return 0;}
cout<<0;
return 0;
}
if(y%x!=0){cout<<0;return 0;}
y/=x;
l=ceil((l+0.0)/x);
r=floor((r+0.0)/x);
int ans=0;
for(int i=l;i<min(r+1.0,sqrt(y));i++)
{
if(y%i!=0)continue;
int d=y/i;
if(d>=l&&d<=r&&__gcd(d,i)==1)ans+=2;




}
cout<<ans;
return 0;
}