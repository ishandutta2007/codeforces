#include<bits/stdc++.h>
using namespace std;
int a[101];
int ans;
int main()
{int x;
int n,d;
cin>>n>>d;
for(int i=1;i<=n;i++)
{cin>>x;a[max(d,i)-min(i,d)]+=x;}
for(int i=0;i<=100;i++)
{if(a[i]==2)ans+=2;
if(a[i]==1&&(d-i<=0||d+i>n))ans++;}
ans+=a[0];
cout<<ans;



return 0;
}