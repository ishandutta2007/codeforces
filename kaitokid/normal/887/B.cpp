#include <bits/stdc++.h>
using namespace std;
int a[4][10];
bool can [1000];
int main()
{ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{for(int j=0;j<6;j++)cin>>a[i][j];}
for(int i=0;i<6;i++)
{can[a[0][i]]=true;
int x=a[0][i];
if(n==1)continue;
for(int j=0;j<6;j++)
{can[a[1][j]]=true;
int y=a[1][j];
can[x*10+y]=true;
can[y*10+x]=true;
if(n==2)continue;
for(int g=0;g<6;g++){
int z=a[2][g];
can[z]=true;
can[x*10+z]=true;
can[z*10+x]=true;
can[y*10+z]=true;
can[z*10+y]=true;
can[z*100+y*10+x]=true;
can[z*100+x*10+y]=true;
can[x*100+y*10+z]=true;
can[x*100+z*10+y]=true;
can[y*100+z*10+x]=true;
can[y*100+x*10+z]=true;

}}}
for(int i=1;i<1000;i++)
if(!can[i]){cout<<i-1;return 0;}
return 0;}