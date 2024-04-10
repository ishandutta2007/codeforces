#include <bits/stdc++.h> 
using namespace std ;
 int n;
bool prime (int x)
{
for(int i=2;i<=sqrt(x);i++)
{if(x%i==0)return 0;}
return 1;
}

 int main(){
ios::sync_with_stdio(0);
cin>>n;
if(prime(n)){cout<<1;return 0;}
if(n%2==0||prime(n-2)){cout<<2;return 0;}
cout<<3;
return 0;}