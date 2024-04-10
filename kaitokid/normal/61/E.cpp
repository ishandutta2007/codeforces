#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int num[40000000];
ll ans,res;
pair<int,int>a[1000009];
void see(int fir,int en,int x,int i)
{
if(x<fir||x>en)return ;
ans+=num[i];
if(fir==en)return;
int mid=(fir+en)/2;
see(fir,mid,x,2*i);
see(mid+1,en,x,2*i+1);




}
void go(int fir,int en,int l,int r,int i)
{

if(fir>r||en<l)return;
if(fir>=l&&en<=r){num[i]++;return ;}
int mid=(fir+en)/2;
go(fir,mid,l,r,2*i);
go(mid+1,en,l,r,2*i+1);




}
int main() 
{ 
ios::sync_with_stdio(0);

int n;
cin>>n;
int x;
for(int i=0;i<n;i++){cin>>x;a[i]=make_pair(x,i);}
sort(a,a+n);
for(int i=0;i<n;i++)
{
go(0,n-1,0,a[i].second-1,1);
ans=0;
see(0,n-1,a[i].second,1);

ll q=n-i-1-(n-a[i].second-1-ans);
res+=ans*q;
//cout<<ans<<" "<<q<<endl;
}
cout<<res;

return 0 ;}