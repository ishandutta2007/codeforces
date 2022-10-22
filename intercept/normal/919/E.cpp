#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b,p;
ll x,ans;
int kpow(int s,int t,int rex=1){
	for(;t;t>>=1,s=1ll*s*s%p)if(t&1)rex=1ll*rex*s%p;
	return rex;
}
int main(){
	cin>>a>>b>>p>>x;
	for(int i=1;i<=min(1ll*p-1,x);++i){
		int s=kpow(a,i);
		int t=(1ll*b*kpow(s,p-2)%p+p-i)%p;
		s=kpow(p-1,p-2);
		t=1ll*t*s%p;
		ll k=(x-i)/(p-1);
		ans+=(k-t)/p+(k>=t);
	}
	cout<<ans<<endl;
	return 0;
}