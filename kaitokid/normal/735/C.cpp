#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;


ll a[200];
int main() 
{ 
ios::sync_with_stdio(0);
ll n;
cin>>n;
n--;
a[1]=1;
a[2]=2;
if(n==1){cout<<1;return 0;}
ll d=1;

for(int i=3;i<100;i++)
{
a[i]=a[i-1]+a[i-2]+1;

if(a[i]>n){cout<<i-1;return 0;}

}

return 0 ;}