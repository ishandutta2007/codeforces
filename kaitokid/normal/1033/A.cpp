#include<bits/stdc++.h>	
using namespace std;
typedef long long ll;
int n,x1,x2,y2,x3,y3;
int y;
int main() 
{ 
cin>>n>>x1>>y>>x2>>y2>>x3>>y3;
if(x2>x1 && x3<x1){cout<<"NO";return 0;}
if(x2<x1 && x3>x1){cout<<"NO";return 0;}
if(y2>y && y3<y){cout<<"NO";return 0;}
if((y2<y)&& (y3>y)){cout<<"NO";return 0;}
cout<<"YES";
}