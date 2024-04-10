#include <bits/stdc++.h> 
using namespace std ;
 long long ans;
 int main()
{ ios::sync_with_stdio(0); 
long long a,b; cin>>a>>b; 

if(b-a>20){cout<<0;return 0;}
if(a==b){cout<<1;return 0;}


ans=(a+1)%10; 




for(long long i=a+2;i<=b;i++) ans=(ans*i)%10;
 cout<<ans; 
return 0;}