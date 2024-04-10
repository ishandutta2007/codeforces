#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;

int main() {
ios::sync_with_stdio(0);
int a1,a2,b1,b2,c1,c2;
cin>>a1>>b1>>c1>>a2>>b2>>c2;
if(a1==0&&b1==0&&c1!=0){cout<<0;return 0;}
if(a2==0&&b2==0&&c2!=0){cout<<0;return 0;}
if(a1*b2!=a2*b1){cout<<1;return 0;}
if(a1*c2!=a2*c1||b1*c2!=b2*c1){cout<<0;return 0;}
cout<<-1;
 return 0; }