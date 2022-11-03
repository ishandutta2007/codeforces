#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
long long n,k;
cin>>n>>k;
vector<ll> v;
for(ll i=1;i*i<=n;++i){
if(n%i==0) v.push_back(i);
}
for(int i=(int)v.size()-1;i>=0;--i){
v.push_back(n/v[i]);
}
if(k>1000000000 || n<k*(k+1)/2) {
cout<<"-1"<<endl;
return 0;
}
auto x =upper_bound(v.begin(),v.end(),n/(k*(k+1)/2))-1;
ll d = *x;
ll s=n/d;
for(int i=1;i<k;++i){
 s-=i;
 cout<<i*d<<" ";
}
cout <<s*d<<endl;
}