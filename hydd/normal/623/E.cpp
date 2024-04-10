#include<bits/stdc++.h>
//#define int long long
typedef long long ll;
typedef long double ldb;
using namespace std;

const ldb pi=acos(-1);
const int Mod=1e9+7;
ll n,fac[1100000],inv[1100000]; int k,bit,len,rev[1100000];
struct cp{
	ldb x,y;
	cp():x(0),y(0){}
	cp(ldb _x,ldb _y):x(_x),y(_y){}
};
cp operator+(const cp &a,const cp &b){ return cp(a.x+b.x,a.y+b.y);}
cp operator-(const cp &a,const cp &b){ return cp(a.x-b.x,a.y-b.y);}
cp operator*(const cp &a,const cp &b){ return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
typedef std::vector<ll> poly;
typedef std::vector<cp> polyc;
poly res,x,y;
polyc p1,p2,q1,q2;

void FFT(polyc &a,int inv){
	for (int i=0;i<len;i++)
		if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int mid=1;mid<len;mid<<=1){
		cp tmp(cos(pi/mid),inv*sin(pi/mid));
		for (int i=0;i<len;i+=(mid<<1)){
			cp omega(1,0);
			for (int j=0;j<mid;j++,omega=omega*tmp){
				cp x=a[i+j],y=omega*a[i+j+mid];
				a[i+j]=x+y; a[i+j+mid]=x-y;
			}
		}
	}
}
void polymul(poly &a,poly b,int v){
	ll mul=1;
	for (int i=0;i<=k;i++){ a[i]=a[i]*mul%Mod; mul=mul*v%Mod;}
	a.resize(len); b.resize(len);
	for (int i=0;i<len;i++){ p1[i].x=a[i]>>15; p1[i].y=0; p2[i].x=a[i]&32767; p2[i].y=0;}
	for (int i=0;i<len;i++){ q1[i].x=b[i]>>15; q1[i].y=0; q2[i].x=b[i]&32767; q2[i].y=0;}
	
	FFT(p1,1); FFT(p2,1);
	FFT(q1,1); FFT(q2,1);
	for (int i=0;i<len;i++){
		cp x1=p1[i],x2=p2[i],y1=q1[i],y2=q2[i];
		p1[i]=x1*y1; p2[i]=x1*y2;
		q1[i]=x2*y1; q2[i]=x2*y2;
	}
	FFT(p1,-1); FFT(p2,-1); FFT(q1,-1); FFT(q2,-1);
	
	a.resize(k+1);
	for (int i=0;i<=k;i++){
		ll x1=(ll)(p1[i].x/len+0.5)%Mod+Mod,
		   x2=(ll)(p2[i].x/len+0.5)%Mod+Mod,
		   y1=(ll)(q1[i].x/len+0.5)%Mod+Mod,
		   y2=(ll)(q2[i].x/len+0.5)%Mod+Mod;
		a[i]=((x1<<30)+(x2<<15)+(y1<<15)+y2)%Mod;
	}
}
signed main(){
	scanf("%lld%d",&n,&k);
	if (n>k){ puts("0"); return 0;}
	bit=0; len=1;
	while (len<=k+k+2) len<<=1,bit++;
	p1.resize(len); q1.resize(len);
	p2.resize(len); q2.resize(len);
	
	for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	
	//k![x^k]e^x(e^x-1)(e^{2x}-1)(e^{4x}-1)...(e^{2^n x}-1)
	fac[0]=1; for (int i=1;i<=1000000;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=1000000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=1000000;i++) inv[i]=inv[i]*inv[i-1]%Mod;
	
	res.resize(k+1); x.resize(k+1); y.resize(k+1);
	for (int i=1;i<=k;i++) y[i]=inv[i],x[i]=inv[i];
	x[0]=0; y[0]=1; res[0]=1;
//	polymul(x,x,1);
	ll t=2;
	while (n){
		if (n&1) polymul(res,x,t);
		polymul(x,x,t);
		t=t*t%Mod; n>>=1;
	}
	polymul(res,y,1);
	printf("%lld\n",res[k]*fac[k]%Mod);
	return 0;
}