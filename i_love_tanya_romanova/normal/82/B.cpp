#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long n,i,j,szz,sz[100000],nm[300][300],ara[10000],was[10000],par[10000];
int main(){   
    vector <long > ans[1000];
cin>>n;
for (int i=1;i<=n*(n-1)/2;i++)
{scanf("%d",&sz[i]);
 for (int j=1;j<=sz[i];j++){scanf("%d",&ara[j]);
 was[ara[j]]=1;}
 for (int j=1;j<=sz[i];j++)
  for (int q=j+1;q<=sz[i];q++)
  { nm[ara[j]][ara[q]]++;
   nm[ara[q]][ara[j]]++;
   
}}

for (int i=1;i<=200;i++)
par[i]=i;

for (int i=1;i<=200;i++)
{for (int j=i+1;j<=200;j++)
 {
     if (nm[i][j]==n-1&&par[j]==j)par[j]=i;
     }}

for (int i=1;i<=200;i++)
 if (par[i]==i&&was[i]==1)
 {szz++;
  ans[szz].push_back(i);
  for (int j=i+1;j<=200;j++)
  if (par[j]==i)ans[szz].push_back(j);
}
if (n==2)
{cout<<1<<" "<<ans[1][0]<<endl;
 cout<<ans[1].size()-1;
 for (int j=1;j<ans[1].size();j++)
 cout<<" "<<ans[1][j];
 cout<<endl;}
 else {
for (int i=1;i<=szz;i++)
{cout<<ans[i].size();
for (int j=0;j<ans[i].size();++j)
cout<<" "<<ans[i][j];
cout<<endl;}
}
cin.get();cin.get();
return 0;}