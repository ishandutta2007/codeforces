#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p1,p2,k;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	for (cin>>n;n--;){
		scanf("%lld%lld%lld",&p1,&p2,&k);
		if (p1>p2)swap(p1,p2);
		ll l=gcd(p1,p2),r=l+(k-1)*p1;
		printf(r<p2?"REBEL\n":"OBEY\n");
	}
}