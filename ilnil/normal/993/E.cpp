#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define max(a,b)(C=(b),a>C?a:C)
#define db long double
#define add(x,y)((x+y)-(x+y>=mo?mo:0))
using namespace std;
const int N=2e5+5;
const ll mo=2748779069441;
int n,x,a[N],Q,h[N*4];
ll z,nQ,b[N*4],c[N*4],w[N*4];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
ll mu(ll x,ll y){
	z=x*y-(ll)((db)x*y/mo)*mo;
	if(z<0)z+=mo;if(z>=mo)z-=mo;return z;
}
ll ksm(ll x,ll y){
	ll t=1;for(;y;y>>=1,x=mu(x,x))if(y&1)t=mu(t,x);
	return t;
}
void dft(ll *a){
	fo(i,1,Q)if(h[i]>i)swap(a[i],a[h[i]]);ll C;
	for(int i=2,j,m,k;m=i>>1,i<=Q;i<<=1)for(j=0;j<Q;j+=i)for(k=0;k<m;k++){
		ll &l=a[j+m+k],&r=a[j+k];
		C=mu(w[Q/i*k],l);l=add(r,mo-C);r=add(r,C);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	R(n);R(x);
	fo(i,1,n)R(a[i]),a[i]=(a[i]<x)+a[i-1];
	fo(i,0,n)b[a[i]]+=1,c[n-a[i]]+=1;
	for(Q=1;Q<=n*2;Q<<=1);nQ=ksm(Q,mo-2);
	fo(i,1,Q)h[i]=(i&1)*(Q>>1)|(h[i>>1]>>1);
	w[0]=1;w[1]=ksm(3,(mo-1)/Q);
	fo(i,2,Q)w[i]=mu(w[i-1],w[1]);
	dft(b);dft(c);
	fo(i,0,Q)b[i]=mu(b[i],c[i]);
	fo(i,1,Q>>1)swap(b[i],b[Q-i]);
	dft(b);
	printf("%I64d ",mu(b[n],nQ)-n-1>>1);
	fo(i,n+1,n+n)printf("%I64d ",mu(b[i],nQ));
}