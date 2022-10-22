#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
pair<ll,ll> f(ll n,ll m){
	if(n==0||m==0)return make_pair(n,m);
	else if(n>=2ll*m)return f(n%(2ll*m),m);
	else if(m>=2ll*n)return f(n,m%(2ll*n));
	else return make_pair(n,m);
}
int main(){
	ll n,m;
	n=read();m=read();
	pair<ll,ll>p=f(n,m);
    printf("%lld %lld\n",p.fi,p.se);
	return 0;
}