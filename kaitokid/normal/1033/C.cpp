#include<bits/stdc++.h>	
using namespace std;
typedef long long ll;
int n;
int a[100009];
int bl[100009];
int r[100009];
int main() 
{ ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
r[a[i]]=i;

}
bl[r[n]]=2;
for(int i=n-1;i>=1;i--)
{
int j=r[i]+i;
while(j<=n)
{
if(bl[j]==2){bl[r[i]]=1;break;}

j+=i;
}
if(bl[r[i]]==1)continue;
 j=r[i]-i;
while(j>0)
{
if(bl[j]==2){bl[r[i]]=1;break;}

j-=i;
}
if(bl[r[i]]==1)continue;

bl[r[i]]=2;
}

for(int i=1;i<=n;i++)if(bl[i]==1)cout<<"A";
else cout<<"B";

}