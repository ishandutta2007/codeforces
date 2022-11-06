#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll a[N],b[N],c[N],n,T;
ll l0,r0,l1,r1,l2,r2,l3,r3;
void cmin(ll &a,ll b){a=a<b?a:b;}
void cmax(ll &a,ll b){a=a>-b?a:-b;}
void getlim(ll lim){
	l0=l1=l2=l3=-5e18;
	r0=r1=r2=r3=5e18;
	for (ll i=1;i<=n;i++){
		cmin(r0,lim+a[i]+b[i]+c[i]);
		cmin(r1,lim-a[i]+b[i]+c[i]);
		cmin(r2,lim+a[i]-b[i]+c[i]);
		cmin(r3,lim+a[i]+b[i]-c[i]);
		cmax(l0,lim-a[i]-b[i]-c[i]);
		cmax(l1,lim+a[i]-b[i]-c[i]);
		cmax(l2,lim-a[i]+b[i]-c[i]);
		cmax(l3,lim-a[i]-b[i]+c[i]);
	}
}
ll cross(ll l1,ll r1,ll l2,ll r2){
	return (l2<=l1&&l1<=r2||l2<=r1&&r1<=r2||l1<=l2&&r2<=r1);
}
ll check(ll &a,ll &b,ll &c){
	for (ll r=0;r<=1;r++){
		ll p0=l0-3*r,p1=l1-r,p2=l2-r,p3=l3-r,q0=r0-3*r,q1=r1-r,q2=r2-r,q3=r3-r;
		p0=p0+1>>1,
		p1=p1+1>>1,
		p2=p2+1>>1,
		p3=p3+1>>1,
		q0=q0>>1,
		q1=q1>>1,
		q2=q2>>1,
		q3=q3>>1;
		if (p0<=q0&&p1<=q1&&p2<=q2&&p3<=q3&&cross(p0,q0,p1+p2+p3,q1+q2+q3)){
			a=p1,b=p2,c=p3;
			a+=min(q1-p1,max(p0-a-b-c,0LL));
			b+=min(q2-p2,max(p0-a-b-c,0LL));
			c+=min(q3-p3,max(p0-a-b-c,0LL));
			a=2*a+r;b=2*b+r;c=2*c+r;
			return 1;
		}
	}
	return 0;
}
int main(){
	for (cin>>T;T--;){
		cin>>n;
		for (ll i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		ll ans=-1,a0,b0,c0;
		for (ll u=1LL<<61;u;u>>=1){
			getlim(ans+u);
			if (!check(a0,b0,c0))ans+=u;
		}
		getlim(ans+1);
		check(a0,b0,c0);
		printf("%lld %lld %lld\n",b0+c0>>1,a0+c0>>1,a0+b0>>1);
	}
}