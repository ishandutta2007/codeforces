#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
using namespace std;
const int N=524300,M=1.5e6+5,mo=1e6;
const ll MO=4179340454199820289;
const db pi=acos(-1);
int n,a[M],Q,P,h[N],ws=6;
int c3[N],s[N],s2[N],g,gg,an;
ll x,ys,b[N],c[N],w[N],nQ;
char ch;
ll mu(ll x,ll y){
	ll z=(db)x*y/MO;z=x*y-z*MO;
	if(z<0)z+=MO;if(z>=MO)z-=MO;return z;
}
ll ksm(ll x,ll y){
	ll t=1;
	for(;y;y>>=1,x=mu(x,x))if(y&1)t=mu(t,x);
	return t;
}
ll add(ll x,ll y){return(x+y)-(x+y>=MO?MO:0);}
void dft(ll *a){
	fo(i,1,Q)if(h[i]>i)swap(a[i],a[h[i]]);ll A;
	for(int i=2,j,m,k,g=1;m=i>>1,i<=Q;i<<=1,g++)for(j=0;j<Q;j+=i)for(k=0;k<m;k++)
		A=mu(w[(P>>g)*k],a[j+m+k]),a[j+m+k]=add(a[j+k],MO-A),a[j+k]=add(a[j+k],A);
}
void idft(ll *a){
	fo(i,1,Q>>1)swap(a[i],a[Q-i]);dft(a);
	fo(i,0,Q)a[i]=mu(a[i],nQ);
}
bool pd(int *b,int k){
	if(k<n)return 0;
	if(k>n)return 1;
	fd(i,0,k)if(b[i]<a[i])return 0;
	else if(b[i]>a[i])return 1;
	return 1;
}
void get(int x){
	for(Q=1;Q<=x;Q<<=1);nQ=ksm(Q,MO-2);
	fo(i,1,Q)h[i]=(i&1)*(Q>>1)+(h[i>>1]>>1);
}
void mult(int *a,int *d,int &le,int le2){
	get(le+le2);
	fo(i,0,le)b[i]=a[i];
	fo(i,le+1,Q)b[i]=0;
	fo(i,0,le2)c[i]=d[i];
	fo(i,le2+1,Q)c[i]=0;
	dft(b);dft(c);
	fo(i,0,Q)b[i]=mu(b[i],c[i]);
	idft(b);
	ys=0;le=le+le2;
	fo(i,0,le)x=b[i]+ys,a[i]=x%mo,ys=x/mo;
	if(ys)a[++le]=ys;
}
void sq(int *a,int &le){
	get(le*2);
	fo(i,0,le)b[i]=a[i];
	fo(i,le+1,Q)b[i]=0;
	dft(b);
	fo(i,0,Q)b[i]=mu(b[i],b[i]);
	idft(b);
	ys=0;le<<=1;
	fo(i,0,le)x=b[i]+ys,a[i]=x%mo,ys=x/mo;
	if(ys)a[++le]=ys;
}
void mult2(int *a,int *b,int &le,int le2,int cl){
	le=le2;x=0;
	fo(i,0,le)ys=b[i],a[i]=(x+ys*cl)%mo,x=(x+ys*cl)/mo;
	if(x)a[++le]=x;
}
int main(){
//	freopen("a.in","r",stdin);
	for(;(ch=getchar())<='9'&&ch>='0';)a[++n]=ch-48;
	if(n==1){
		int an;
		if(a[1]<=5)an=a[1];
		if(a[1]==6)an=5;
		if(a[1]>=7&&a[1]<=9)an=6;
		printf("%d",an);
		return 0; 
	}
	an=(ll)(log(10)/(db)log(3)*(n-1));
	fo(i,1,n>>1)swap(a[i],a[n-i+1]);
	fo(i,1,n/ws){
		a[i-1]=0;
		fd(j,(i-1)*ws+1,i*ws)a[i-1]=a[i-1]*10+a[j];
	}
	if(n%ws>0){
		a[n/ws]=0;fd(j,n/ws*ws+1,n)a[n/ws]=a[n/ws]*10+a[j];
	}
	n=n/ws+(n%ws>0)-1;
	for(P=1;P<=n;P<<=1);
	w[0]=1;w[1]=ksm(3,(MO-1)/P);
	fo(i,2,P)w[i]=mu(w[i-1],w[1]);
	c3[0]=3;s[0]=1;
	for(int y=an;y;y>>=1){
		if(y&1)mult(s,c3,gg,g);
		if(y>1)sq(c3,g);
	}
	for(;mult2(s2,s,g,gg,3),!pd(s2,g);an++,gg=g)fo(i,0,g)s[i]=s2[i];
	an=(an+1)*3;g=gg;
	fo(i,0,g)s2[i]=s[i];ys=0;
	fd(i,0,g)x=ys*mo+s2[i],s2[i]=x/3,ys=x%3;
	if(mult2(s2,s2,gg,gg,4),pd(s2,g))an-=2;
	else if(mult2(s,s,gg,gg,2),pd(s,gg))an--;
	printf("%d",an);
}