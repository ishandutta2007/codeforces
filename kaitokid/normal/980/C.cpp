#include<bits/stdc++.h>
using namespace std;
int n,k;
int c[258];
int x;
int main()
{
ios::sync_with_stdio(0);
memset(c,-1,sizeof c);
cin>>n>>k;
for(int i=0;i<n;i++)
{
cin>>x;
if(c[x]!=-1){cout<<c[x]<<" ";continue;}
int d=x;
for(int j=x;j>max(x-k,-1);j--)
{if(c[j]==-1)d=j;
else if(x-c[j]+1<=k){d=c[j];break;}
else break;}

for(int j=d;j<=x;j++)
{

c[j]=d;

}

cout<<c[x]<<" ";
}

}