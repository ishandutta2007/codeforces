#include<bits/stdc++.h>
using namespace std;
int main()
{
int x,y,l,r;
double k;
cin>>l>>r>>x>>y>>k;
for(int i=x;i<=y;i++){
if(k*i>=l&&k*i<=r&&floor(k*i)==k*i){cout<<"YES";return 0;}}
cout<<"NO";
return 0;
}