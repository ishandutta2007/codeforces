#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n,m;
ll k;
int a[maxn],b[maxn];
int pos[2*maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll p,q;
ll exgcd(ll a,ll b){
	if(b==0){p=1;q=0;return a;}
	ll g=exgcd(b,a%b);
	ll tmp=p;
	p=q;
	q=tmp-a/b*q;
	return g;
}
ll c[maxn],d[maxn];
void excrt(int u,int v){
	ll x=u,M=n;
	ll g=exgcd(M,m),mod;
	mod=M/g*m;
	if((v-x)%g)return ;
	p=p*((v-x+m)%m/g)%m;
	x=(x+p*M%mod+mod)%mod;M=mod;
	x=(x+M)%M;
	c[v]=x;d[v]=M;
	return ;
}
ll check(ll t){
	ll res=t;
	for(int i=1;i<=m;i++)if(pos[b[i]]&&d[i])res-=(t/d[i]+(c[i]?t%d[i]>=c[i]:0));
	return res;
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=m;i++)if(pos[b[i]])excrt(pos[b[i]],i);
	ll lt=k-1,rt=1e18,mid;
	while(lt+1<rt){
		mid=lt+((rt-lt)>>1);
		if(check(mid)<k)lt=mid;
		else rt=mid;
	}
	printf("%lld\n",rt);
    return 0;
}