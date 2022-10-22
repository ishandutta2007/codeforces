#include <bits/stdc++.h> 
using namespace std ;
int v[2][100009];
int a,b;
 int main(){
ios::sync_with_stdio(0);
int n,c;
cin>>n>>a>>b>>c;

if(n==1){cout<<0;return 0;}

int l=min(a,min(b,c));
if(min(a,b)==l){cout<<(n-1)*l;
return 0;}
cout<<min(a,b)+(n-2)*l;
return 0;}