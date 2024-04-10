#include <bits/stdc++.h>
using namespace std;
int a[17];
int n,l,r,x;
int ans;
void h(int mn,int number,int sum,int i)
{

if(i==n)return ;
if(number!=0&&a[i]-mn>=x&&sum+a[i]>=l&&sum+a[i]<=r)ans++;

h(mn,number,sum,i+1);
if(number==0)mn=a[i];
h(mn,number+1,sum+a[i],i+1);





}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>l>>r>>x;
for(int i=0;i<n;i++)
{

cin>>a[i];



}

sort(a,a+n);
h(0,0,0,0);
cout<<ans;

return 0;}