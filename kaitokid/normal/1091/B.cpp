#include <bits/stdc++.h>
 using namespace std; 
typedef long long ll;
 ll n,a,b,x,y;
int main()
 { ios::sync_with_stdio(0); 
cin>>n;
for(ll i=0;i<2*n;i++)
{cin>>x>>y;a+=x;b+=y;}
cout<<a/n<<" "<<b/n;

 return 0; }