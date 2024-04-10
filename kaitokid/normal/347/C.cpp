#include <bits/stdc++.h>
using namespace std;
int n,x,mx,gd;
int main (){
ios::sync_with_stdio(0);

cin>>n;
for(int i=0;i<n;i++)
{cin>>x;
mx=max(mx,x);
gd=__gcd(gd,x);}


string s []={"Bob","Alice"};
cout<<s[(mx/gd-n)%2];
return 0;}