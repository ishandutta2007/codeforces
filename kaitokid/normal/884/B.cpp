#include <bits/stdc++.h>
using namespace std ; 

int main() 
{

int n,x,sum=0,y;
cin>>n>>x;
for(int i=0;i<n;i++)
{cin>>y;
sum+=y;}
if(x-sum==n-1){cout<<"YES";return 0;}
cout<<"NO";
return 0;
}