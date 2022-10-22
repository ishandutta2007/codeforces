#include <bits/stdc++.h>
#define double long double
#define ll long long
using namespace std;
const int maxk=3e4+5,mod=1e9+7;
const double pai=acos(-1.0);
ll n;
int k;
int G[maxk];
int F[maxk];
struct C{
	double a,b;
	C conj(){return (C){a,-b};}
	C operator +(C i){return (C){a+i.a,b+i.b};}
	C operator -(C i){return (C){a-i.a,b-i.b};}
	C operator *(C i){return (C){a*i.a-b*i.b,a*i.b+b*i.a};}
};
int rev[4*maxk];
C A0[4*maxk],A1[4*maxk],B0[4*maxk],B1[4*maxk];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
inline int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
C pw[2][8*maxk];
void pre(int lim){
	for(int i=1;i<lim;i<<=1){
		pw[0][i]=pw[1][i]=(C){1,0};
		pw[0][i+1]=(C){cos(pai/i),sin(pai/i)};
		pw[1][i+1]=(C){cos(pai/i),-sin(pai/i)};
		for(int j=2;j<i;j++){
			pw[0][i+j]=(C){cos(j*pai/i),sin(j*pai/i)};
			pw[1][i+j]=(C){cos(j*pai/i),-sin(j*pai/i)};
		}
	}
	return ;
}
void FFT(C *f,int lim,int opt){
	for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
	int op=(opt==-1);
	for(int mid=1;mid<lim;mid<<=1){
		for(int j=0;j<lim;j+=(mid<<1)){
			for(int k=0;k<mid;k++){
				C u=f[j+k],v=f[j+k+mid]*pw[op][mid+k];
				f[j+k]=u+v;
				f[j+k+mid]=u-v;
			}
		}
	}
	if(opt==1)return ;
	for(int i=0;i<lim;i++)f[i].a/=lim,f[i].b/=lim;
	return ;
}
int b=32768;
int lim;
void mul(int *f,int *g,int p,int q){
	for(int i=0;i<=k;i++){
		int x=1ll*f[i]*power(2,1ll*q*i%(mod-1))%mod;
		A0[i]=(C){x>>15,x&32767};
	}
	for(int i=0;i<=k;i++)B0[i]=(C){g[i]>>15,g[i]&32767};
	FFT(A0,lim,1);FFT(B0,lim,1);
	for(int i=1;i<lim;i++)A1[i]=A0[lim-i].conj(),B1[i]=B0[lim-i].conj();
	A1[0]=A0[0].conj();B1[0]=B0[0].conj();
	for(int i=0;i<lim;i++){
		C u,v,x,y,z,w;
		u=A0[i]+A1[i],v=A0[i]-A1[i];
		x=u*(C){0.5,0};
		y=v*(C){0,-0.5};
		u=B0[i]+B1[i],v=B0[i]-B1[i];
		z=u*(C){0.5,0};
		w=v*(C){0,-0.5};
		A0[i]=x*z+(C){0,1}*((x*w)+(y*z));
		B0[i]=y*w;
	}
	FFT(A0,lim,-1);FFT(B0,lim,-1);
	for(int i=0;i<=k;i++){
		f[i]=add((ll)(A0[i].a+0.5)%mod*b%mod*b%mod+(ll)(A0[i].b+0.5)%mod*b%mod);
		f[i]=add(f[i]+1ll*(ll)(B0[i].a+0.5)%mod);
	}
	for(int i=0;i<lim;i++)A0[i]=A1[i]=B0[i]=B1[i]=(C){0,0};
	return ;
}
int fc[maxk],iv[maxk];
int C(int n,int m){
	return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;
}
int main(){
	n=read();k=read();
	if(n>k){puts("0");return 0;}
	lim=1;int c=0;
	while(lim<=2*k)lim<<=1,c++;
	pre(lim);
	for(int i=0;i<lim;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(c-1));
	fc[0]=1;
	for(int i=1;i<=k;i++)fc[i]=1ll*fc[i-1]*i%mod;
	iv[k]=power(fc[k],mod-2);
	for(int i=k-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
	int numg=0,numf=1;
	G[0]=1;
	F[0]=0;
	for(int i=1;i<=k;i++)F[i]=iv[i];
	while(n){
		if(n&1)mul(G,F,numg,numf),numg+=numf;
		mul(F,F,numf,numf),numf<<=1;
		n>>=1;
	}
//	for(int i=0;i<=k;i++)cout<<G[i]<<" ";cout<<endl;
	int res=0;
	for(int i=0;i<=k;i++)res=add(res+1ll*G[i]*C(k,i)%mod*fc[i]%mod);
    printf("%d\n",res);
	return 0;
}