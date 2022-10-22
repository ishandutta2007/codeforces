#include <bits/stdc++.h>
using namespace std;
int a[200];
int n;
int ans=10000000;
void d(int q,int b,int i,bool bl,int sum,int v)
{
if(i==q||i==b){d(q,b,i+1,bl,sum,v);return ;}
if(i==n+1){ans=min(ans,sum);return ;}
if(bl)d(q,b,i+1,0,sum+a[i]-v,0);
if(!bl)d(q,b,i+1,1,sum,a[i]);

}
int main()
{

cin>>n;
n*=2;
for(int i=0;i<n;i++)cin>>a[i];
sort (a,a+n);
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
d(i,j,0,0,0,0);

//cout<<ans<<endl;
}
cout<<ans;
return 0;}