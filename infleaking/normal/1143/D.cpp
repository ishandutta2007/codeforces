#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,k,a,b,mx,mn;
ll gcd(ll a,ll b){
	if (b==0)return a;
	return gcd(b,a%b);
}
ll Abs(ll x){return x<0?-x:x;}
void calc(ll a,ll b){
	for (;b<n*k;b+=k){
		ll dis=Abs(a-b);
		if (dis==0)continue;
		ll st=n*k/gcd(n*k,dis);
		mx=max(mx,st);
		mn=min(mn,st);
	}	
}
int main(){
	cin>>n>>k>>a>>b;
	mx=1,mn=n*k;
	if (a==b)mn=1;
	calc(a,b);
	calc(k-a,b);
	calc(a,k-b);
	calc(k-a,k-b);
	cout<<mn<<' '<<mx<<endl;
}