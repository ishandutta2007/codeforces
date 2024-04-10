#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int main()
{

ios::sync_with_stdio(0);
 
cin>>n>>a>>b;
int q=0,v=0;
while(true)
{
if((n-(a*q))<0){cout<<-1;return 0;}
int u=n-(a*q);
if(u%b==0){v=u/b;break;}
q++;



}
int m=q*a;
for(int i=0;i<q;i++)
{
for(int j=1;j<=a;j++)
{
int d=j+1;
if(j==a)d=1;
cout<<(i*a)+d<<" ";


}


}
int r=n-m;
for(int i=0;i<v;i++)
{for(int j=1;j<=b;j++)
{
int d=j+1;
if(j==b)d=1;
cout<<(i*b)+d+m<<" ";


}



}
return 0;}