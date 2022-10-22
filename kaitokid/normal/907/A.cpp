#include <bits/stdc++.h>
using namespace std;
int main()
{
ios::sync_with_stdio(0);
int a,b,c,d;
cin>>a>>b>>c>>d;
int r1=max(c,d);
if(r1>min(2*c,2*d)){cout<<-1;return 0;}
int r2=max(b,2*d+1);
if(r2<=r1)r2++;
if(r2>b*2){cout<<-1;return 0;}
int r3=max(a,2*d+1);
if(r3<=r2)r3++;
if(r3>a*2){cout<<-1;return 0;}
cout<<r3<<endl<<r2<<endl<<r1;
return 0;}