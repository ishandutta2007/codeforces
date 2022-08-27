#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m;
int k;
ll a[10005],b[10005],r[10005];
ll mul(ll a,ll b,ll p){
	return ((a*b-ll((long double)a/p*b)*p)%p+p)%p;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll exgcd(ll a,ll b,ll &lx,ll &ly){
	ll q,r,t,x=0,y=1;	lx=1,ly=0;
	while(b){
		ll q=a/b,r=a-q*b;
		t=lx-q*x,lx=x,x=t;
		t=ly-q*y,ly=y,y=t;
		a=b,b=r;
	}
	return a;
}
int crt(){
	for (int i=1;i<k;i++){
		ll p,q;
		ll d=exgcd(a[i],a[i+1],p,q);
		if(r[i]%d!=r[i+1]%d)return 0;
		ll mo=a[i]/d*a[i+1];
		r[i+1]=(mul(mul(q,a[i+1]/d,mo),r[i],mo)+mul(mul(p,a[i]/d,mo),r[i+1],mo))%mo;
		a[i+1]=mo;
	}
	return 1;
}
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++)cin>>a[i],r[i]=k-i,b[i]=a[i];
	ll l=1;
	for (int i=1;i<=k;i++){
		ll d=gcd(l,a[i]);
		if(1.0*l/d*a[i]>n+0.001){
			printf("NO\n");
			return 0;
		}
		l=l/d*a[i];
	}
	int t=crt();
	if(!t){
		printf("NO\n");
		return 0;
	}
	ll st=r[k]-k+1;
	st=((st-1)%l+l)%l+1;
	if(st+k-1>m){
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=k;i++)if(gcd(st+i-1,l)!=b[i]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}