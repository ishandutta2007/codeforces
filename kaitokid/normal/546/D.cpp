#include <bits/stdc++.h>
using namespace std;
int a[5000008],b[5000008],c[5000008];
int main()
{
//ios::sync_with_stdio(0);

for(int i=2;i<=sqrt(5000000);i++)
{
if(a[i]!=0)continue;

int j=i;
while(i*j<=5000000)
{a[i*j]=i;j++;}



}
for(int i=2;i<=5000000;i++)
{
if(a[i]==0){b[i]=1;}else{
b[i]=b[a[i]]+b[i/a[i]];}
c[i]=c[i-1]+b[i];


}
int n,x,y;

scanf("%d",&n);
for(int i=0;i<n;i++)
{scanf("%d%d",&x ,&y);
printf("%d\n",c[x]-c[y]);
}
return 0;}