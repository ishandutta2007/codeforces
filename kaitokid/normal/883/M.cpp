#include <bits/stdc++.h> 
using namespace std ;
 int main(){
int x1,x2,y1,y2;
cin>>x1>>y1>>x2>>y2;
if(y1==y2)y1++;
if(x1==x2)x1++;
int ans=abs(x1-x2)+abs(y1-y2)+2;
cout<<ans*2;
return 0;}