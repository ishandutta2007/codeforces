#include<bits/stdc++.h>
using namespace std;
int a[101];
int ans;
int d;
int i;
int main()
{
for(int j=0;j<5;j++)
{cin>>i;
ans+=i;

if(a[i]/i<3)a[i]+=i;
if(a[i]/i>1)d=max(d,a[i]);
}



ans-=d;
cout<<ans;



return 0;
}