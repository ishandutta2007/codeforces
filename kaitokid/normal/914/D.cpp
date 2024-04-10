#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int num[7000000];
int ans=0;
int x;
int wh[500009],a[500009];
void test(int fir,int en,int l,int r,int i)
{
if(ans>1)return;
if(en<l||fir>r)return;
if(num[i]%x==0)return ;
if(fir==en&&(num[i]%x!=0)){ans++;return;}
if(fir>=l&&en<=r&&num[i]%x!=0&&ans==1){ans++;return;}
int mid=(fir+en)/2;
test(fir,mid,l,r,2*i);
test(mid+1,en,l,r,2*i+1);



}

void go(int l,int r,int i)
{
if(l==r){wh[l]=i;num[i]=a[l];return ;}
int mid =(l+r)/2;
go(l,mid,2*i);
go(mid+1,r,2*i+1);
num[i]=__gcd(num[2*i],num[2*i+1]);



}
int main() 
{ 
ios::sync_with_stdio(0);

int n;
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
go(0,n-1,1);
int p,l,r;
int q;
cin>>q;
while(q--)
{

cin>>p>>l>>r;
if(p==1){ans=0;
l--;
r--;
cin>>x;
ans=0;
test(0,n-1,l,r,1);
if(ans<2)cout<<"YES\n";
else cout<<"NO\n";



continue;}
l--;
int u=wh[l];
num[u]=r;
u/=2;
while(u>0)
{
num[u]=__gcd(num[2*u],num[2*u+1]);
u/=2;

}


}
return 0 ;}