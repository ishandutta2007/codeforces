#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1001000;
const ll INF=1ll<<62;
int n,m;
ll k;
ll x1,y1,gcd,lcm;
int ato[maxn],tnt;
ll Meet[maxn];
inline ll read(){
	ll res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void exgcd(ll &x,ll &y,int a,int b){
	if(!b){
		gcd=a;x=1;y=0;return;
	}
	exgcd(y,x,b,a%b);
	y=y-x*(a/b);
}
void tryer(int x,int y){
	if((x-y)%gcd!=0)return;
	Meet[++tnt]=((n*x1%lcm*((x-y)/gcd)%lcm+lcm)%lcm+x)%lcm;
}
bool check(ll x){
	ll res=x/lcm*tnt;
	for(int i=1;i<=tnt;++i)
		res+=(x%lcm>=Meet[i]);
	return x+1-res>=k;
}
void process(){
	n=read();m=read();k=read();
	exgcd(x1,y1,n,m);
	lcm=1ll*n/gcd*m;
	x1=(-x1%(m/gcd)+(m/gcd))%(m/gcd);
	for(int i=0;i<n;++i)
		ato[read()]=i+1;
	for(int i=0,x;i<m;++i){
		x=read();
		if(ato[x])
			tryer(ato[x]-1,i);
	}
	ll l=0,r=INF,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l+1);
}
int main(){
	int T=1;
	while(T--)process();
    return 0;
}