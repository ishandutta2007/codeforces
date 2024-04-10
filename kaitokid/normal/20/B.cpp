#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a,b,c,d,x1,x2;
int main()
{
ios::sync_with_stdio(0);
cin>>a>>b>>c;
if(a==0&&b==0&&c==0){cout<<-1;return 0;}
if(a==0&&b==0){cout<<0;return 0;}
if(a==0){x1=(-1*c)/b;

cout<<1<<endl<<fixed<<setprecision(10)<<x1;return 0;}
d=b*b-4*a*c;
if(d<0){cout<<0;return 0;}
if(d==0)
{x1=-b/(2*a);cout<<1<<endl<<fixed<<setprecision(10)<<x1;return 0;}
d=sqrt(d);
x1=(-b+d)/(2*a);
x2=(-b-d)/(2*a);
cout<<2<<endl<<fixed<<setprecision(10)<<min(x2,x1)<<endl<<max(x2,x1);
return 0;}