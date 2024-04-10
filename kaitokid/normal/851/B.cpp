#include <bits/stdc++.h>
using namespace std;
int main (){
long long a1,a2,b1,b2,b3,c1,c2;
cin>>a1>>a2>>b1>>b2>>c1>>c2;
double x,y;
/*if(a2-b2==0&&c2-b2==0){cout<<"No";return 0;}
if(a2-b2!=0){ x=(a1-b1+0.0)/(a2-b2-0.0);}else{x=0;}
if(c2!=b2){ y=(c1-b1+0.0)/(c2-b2-0.0);}else{ y=0;}

if(x==y){cout<<"No";return 0;}*/
x=sqrt((a1-b1+0.0)*(a1-b1)+(a2-b2)*(a2-b2-0.0));
y=sqrt((b1-c1+0.0)*(b1-c1)+(b2-c2)*(b2-c2-0.0));
double z=sqrt((a1-c1+0.0)*(a1-c1)+(a2-c2)*(a2-c2-0.0));
if(x==y&&z<2*x){cout<<"Yes";return 0;}
cout<<"No";
return 0;}