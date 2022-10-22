#include <bits/stdc++.h>
using namespace  std;
int a[1006][1006];
int n,k,d;
bool bl=false;
void p(int st,int en,int i,int bus)
{if (bl)return ;

for(int j=st;j<=en;j++)a[i-1][j]=bus;
if(st==en)return ;
if(i>d){bl=true;return ;}
int l=st,r=(en-st+1.0)/min(k,en-st+1);
for(int j=1;j<=min(k,en-st+1)-1;j++)
{
p(l,l+r-1,i+1,j);
l+=r;


}


p(l,en,i+1,min(k,en-st+1));


}
int main()
{ios::sync_with_stdio(0);
cin>>n>>k>>d;
if(k==1&&n>1){cout<<-1;return 0;}

p(1,n,1,0);
if(bl){cout<<-1;return 0;}
for(int i=1;i<=d;i++)
{for(int j=1;j<=n;j++)
{cout<<max(a[i][j],1)<<" ";}
cout<<endl;}
return 0;}