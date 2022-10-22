#include <bits/stdc++.h>
using namespace std;
int x=1;
int main(){
ios::sync_with_stdio(0);
int n,k;
cin>>n>>k;
if(k<n/2||(n==1&&k!=0)){cout<<-1;return 0;}
if(n==1){cout<<1;return 0;}
int l=k-n/2+1;
cout<<l<<" "<<2*l;
for(int i=2;i<n;i++)
{if(i!=l&&i!=2*l&&__gcd(x,i)==1){cout<<" "<<i;x=i;}else{n++;}}
return 0;}