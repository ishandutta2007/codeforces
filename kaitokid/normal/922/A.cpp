#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main() {
ios::sync_with_stdio(0);
ll x,y;
cin>>y>>x;
if(x==0||(x<2&&y>0)){cout<<"No";return 0;}
y-=x-1;
if(y<0||y%2!=0){cout<<"No";return 0;}
cout<<"Yes";
 return 0 ;}