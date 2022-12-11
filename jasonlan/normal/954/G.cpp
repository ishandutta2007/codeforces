#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=501000;
ll n,r,k;
ll a[maxn],s[maxn],t[maxn];
inline ll read(){
    ll res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
bool check(ll x){
	for(register int i=1;i<=n+1;++i)t[i]=0;
	ll gad,pt=0,psk=k;
	for(register int i=1;i<=n;++i){
		pt-=t[i];
		gad=pt+s[min(n,i+r)]-s[max(0ll,i-r-1)];
		if(gad<x){
			if(psk<x-gad)return false;
			psk-=x-gad;
			t[min(n+1,i+(r<<1)+1)]=x-gad;
			pt+=x-gad;
		}
	}
	return true;
}
int main()
{
	n=read();r=read();k=read();
	ll lr=0,rr=k,mid;
	for(register int i=1;i<=n;++i){
		a[i]=read();s[i]=a[i]+s[i-1];
	}
	rr+=s[n];
	while(lr<rr){
		mid=(lr+rr+1)>>1;
		if(check(mid))
			lr=mid;
		else rr=mid-1;
	}
	printf("%lld\n",lr);
	return 0;
}