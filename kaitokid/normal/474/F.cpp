#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int n;
map<int,vector<int> >mp;
int num[2000009],a[100009];
int ans=0;
void see(int fir,int en,int l,int r,int i)
{
if(r<fir||l>en)return;
if(fir>=l&&en<=r){ans=__gcd(ans,num[i]);return;}
int mid=(fir+en)/2;
see(fir,mid,l,r,2*i);
see(mid+1,en,l,r,2*i+1);




}

void go(int l,int r,int i)
{
if(l==r){num[i]=a[l];return;}
int mid=(l+r)/2;
go(l,mid,2*i);
go(mid+1,r,2*i+1);
num[i]=__gcd(num[2*i],num[2*i+1]);

}
int main() 
{ 
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++){cin>>a[i];mp[a[i]].push_back(i);}
go(0,n-1,1);
int t;
cin>>t;
int l,r ;
while(t--)
{
cin>>l>>r;
l--;
r--;
ans=0;
see(0,n-1,l,r,1);
int res= (upper_bound(mp[ans].begin(),mp[ans].end(),r)-lower_bound(mp[ans].begin(),mp[ans].end(),l));
cout<<r-l+1-res<<endl;

}

return 0 ;}