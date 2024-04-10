#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int num[20000000];
map<int,int> mp;
int x;
ll ans;
int d1[1000009],d2[1000009],a[1000009];
void go (int fir,int en,int x,int i)
{
ans+=num[i];
if(fir==en)return;
int mid=(fir+en)/2;
if(x<=mid)go(fir,mid,x,2*i);
else go(mid+1,en,x,2*i+1);



}
void sum (int fir,int en,int l,int r,int i)
{
if(fir>r||en<l)return;
if(fir>=l&&en<=r){num[i]++;return;}
int mid=(fir+en)/2;
sum(fir,mid,l,r,2*i);
sum(mid+1,en,l,r,2*i+1);


}
int main()
{

ios::sync_with_stdio(0);
cin>>n;
int m=n;
for( int i=0;i<n;i++)
{
cin>>a[i];
mp[a[i]]++;
d1[i]=mp[a[i]];

}
mp.clear();
for( int i=n-1;i>=0;i--)
{

mp[a[i]]++;
d2[i]=mp[a[i]];

}
for(int i=0;i<n;i++)
{




go(1,n,d2[i],1);

if(d1[i]>1)sum(1,n,1,d1[i]-1,1);



}
cout<<ans;
return 0;}