#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
const int N=3000000,p=998244353,I=86583718,II=911660635;
int r[N],ig[N],yg[N],invf[N],sqrtf[N],sqrtg[N],cdqf[N],cdqg[N],lnf[N],expf[N];
int ksmf[N],inv[N],f[N],g[N],sinf[1],sing[1],cosf[1],cosg[1],tanf[1],tang[1],cotf[1];
int cotg[N],y[N];
int n,m,mm,i,j,l,limit,biglimit,c,w;
pa ys,yys;
bool sp;
inline int sj()
{
	return rand()<<15|rand();
}
pa operator *(pa x,pa y)
{
	ys.first=((ll)x.first*y.first+(ll)x.second*y.second%p*w)%p;
	ys.second=((ll)x.first*y.second+(ll)x.second*y.first)%p;
	return ys;
}
inline void dbug(int *a,int n)
{
	for (int i=0;i<n;i++) printf("%d ",a[i]);puts("");
}
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
inline void readm()
{
	ll a=0,b=0;
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	a=b=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		a=a*10+(c^48);
		b=(b*10+(c^48))%(p-1);
		if (a>=p) {sp=1;a%=p;}
		c=getchar();
	}
	m=a;mm=b;
}
inline int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
inline pa ksm(pa x,int y)
{
	yys.first=1;yys.second=0;
	while (y)
	{
		if (y&1) yys=yys*x;
		x=x*x;
		y>>=1;
	}
	return yys;
}
inline int mosqrt(int x)
{
	pa a;
	int y=rand()%p;
	while (ksm(w=((ll)y*y%p-x+p)%p,p-1>>1)<=1) y=rand()%p;
	if (w<0) w+=p;
	a.first=y;a.second=1;
	a=ksm(a,p+1>>1);
	return min(a.first,p-a.first);
}
inline void ycl(int l,int limit)
{
	for (int i=1;i<limit;i++) r[i]=r[i>>1]>>1|(i&1)<<l;
}
inline void gg(int limit)
{
	int i;
	ig[limit]=ksm(yg[limit]=ksm(3,(p-1)/limit),p-2);
	for (i=limit>>1;i;i>>=1)
	{
		yg[i]=(ll)yg[i<<1]*yg[i<<1]%p;
		ig[i]=(ll)ig[i<<1]*ig[i<<1]%p;
	}
	inv[1]=1;
	for (i=2;i<limit;i++) inv[i]=p-(ll)p/i*inv[p%i]%p;
}
inline void reverse(int limit,int *f)
{
	int lim=limit>>1;
	for (i=0;i<lim;i++) swap(f[i],f[limit-i-1]);
}
inline void dao(int *a,int n)
{
	for (i=1;i<n;i++) a[i-1]=(ll)a[i]*i%p;a[n-1]=0;
}
inline void ji(int *a,int n)
{
	for (i=n-1;~i;i--) a[i+1]=(ll)a[i]*inv[i+1]%p;
	a[0]=0;
}
void dft(int *a,int xs,int limit)
{
	register int i,j,k,l,w,wn,b,c;
	for (i=1;i<limit;i++) if (i<r[i]) swap(a[i],a[r[i]]);
	for (i=1;i<limit;i=l)
	{
		l=i<<1;
		if (xs) wn=ig[l]; else wn=yg[l];
		for (j=0;j<limit;j+=l)
		{
			w=1;
			for (k=0;k<i;k++,w=(ll)w*wn%p)
			{
				b=a[j|k];c=(ll)w*a[j|k|i]%p;
				a[j|k]=(b+c)%p;
				a[j|k|i]=(b-c+p)%p;
			}
		}
	}
	if (xs)
	{
		limit=ksm(limit,p-2);
		for (i=0;i<xs;i++) a[i]=(ll)a[i]*limit%p;
	}
}
void polymultiply(int *f,int *g,int limit)
{
	int i;
	dft(f,0,limit<<1);dft(g,0,limit<<1); 
	for (i=0;i<limit<<1;i++) f[i]=(ll)f[i]*g[i]%p;
	dft(f,limit,limit<<1);
}
void polyinv(int *f,int *g,int biglim)
{
	int i,j,l=1,limit;
	memset(g,0,biglim<<3);
	memset(invf,0,biglim<<3);
	g[0]=ksm(f[0],p-2);
	for (i=2;i<=biglim;i=limit,l++)
	{
		limit=i<<1;
		memcpy(invf,f,limit<<1);
		for (j=1;j<limit;j++) r[j]=r[j>>1]>>1|(j&1)<<l;
		dft(invf,0,limit);dft(g,0,limit);
		for (j=0;j<limit;j++) g[j]=(ll)g[j]*(p+2-(ll)g[j]*invf[j]%p)%p;
		dft(g,i,limit);
		memset(g+i,0,limit<<1);
	}
}
void polysqrt(int *f,int *g,int biglim)//??f
{
	memset(sqrtf,0,biglim<<3);
	memset(sqrtg,0,biglim<<3);
	memset(g,0,biglim<<3);
	int i,j,l=1,limit;
	g[0]=mosqrt(f[0]);
	if ((ll)g[0]*g[0]%p!=f[0]) while (1);
	for (i=2;i<=biglim;i=limit,l++)
	{
		limit=i<<1;
		polyinv(g,sqrtg,i);
		memcpy(sqrtf,f,limit<<1);
		dft(sqrtf,0,limit);dft(sqrtg,0,limit);dft(g,0,limit);
		for (j=0;j<limit;j++)
		{
			g[j]=(ll)sqrtg[j]*((ll)g[j]*g[j]%p+sqrtf[j])%p;
			if (g[j]&1) g[j]=g[j]+p>>1; else g[j]>>=1;
		}
		dft(g,i,limit);
		memset(g+i,0,limit<<1);
	}
}
void cdq(int L,int R,int *f,int *g)
{
	if (L==R) return;
	int mid=L+R>>1,siz=R-L+1,i;
	cdq(L,mid,f,g);
	limit=1;l=-1;
	while (limit<=siz) {limit<<=1;++l;}
	for (i=1;i<limit;i++) r[i]=r[i>>1]>>1|(i&1)<<l;
	memcpy(cdqf,f+L,mid-L+1<<2);
	memcpy(cdqg,g,siz<<2);
	dft(cdqf,0,limit);dft(cdqg,0,limit);
	for (i=0;i<limit;i++) cdqf[i]=(ll)cdqf[i]*cdqg[i]%p;
	dft(cdqf,siz,limit);
	for (i=mid+1;i<=R;i++) if ((f[i]=f[i]+cdqf[i-L])>=p) f[i]-=p;
	memset(cdqf,0,limit<<2);memset(cdqg,0,limit<<2);
	cdq(mid+1,R,f,g);
}
void polycdq(int *f,int *g,int limit)//f??
{
	cdq(0,limit-1,f,g);
}
void polydivide(int *f,int *g,int *q,int *r,int limit)
{
	
}
void polyln(int *f,int *g,int biglim)
{
	int i,limit=biglim<<1;
	memcpy(lnf,f,biglim<<2);
	memset(lnf+biglim,0,biglim<<2);
	polyinv(f,g,biglim);
	dao(lnf,biglim);
	dft(lnf,0,limit);dft(g,0,limit);
	for (i=0;i<limit;i++) g[i]=(ll)g[i]*lnf[i]%p;
	dft(g,biglim,limit);
	memset(g+biglim,0,biglim<<2);
	ji(g,biglim);
}
void polyexp(int *f,int *g,int biglim)
{
	memset(g,0,biglim<<3);
	memset(expf,0,biglim<<3);
	g[0]=1;
	int i,j,l=1,limit;
	for (i=2;i<=biglim;i=limit,l++)
	{
		limit=i<<1;
		polyln(g,expf,i);
		for (j=0;j<i;j++) expf[j]=(f[j]-expf[j]+p)%p;++expf[0];
		dft(g,0,limit);dft(expf,0,limit);
		for (j=0;j<limit;j++) g[j]=(ll)g[j]*expf[j]%p;
		dft(g,i,limit);
		memset(g+i,0,limit<<1);
	}
}
void polyksm1(int *f,int *g,int biglim,int cs)
{
	if (cs==0)
	{
		g[0]=ksm(f[0],mm);
		return;
	}
	int i,j,k=1,wy=0;
	if (f[0]==0)
	{
		for (i=1;i<biglim;i++) if (f[i]) break;
		for (j=0;j<biglim-i;j++) f[j]=f[j+i];
		memset(f+biglim-i,0,i<<2);
		if (((ll)i*cs>=biglim)||(sp)) return;
		wy=i*cs;
	}
	if (f[0]>1)
	{
		k=ksm(f[0],p-2);
		for (i=1;i<biglim;i++) f[i]=(ll)f[i]*k%p;
		k=ksm(f[0],mm);f[0]=1;
	}
	polyln(f,ksmf,biglim);
	for (i=0;i<biglim;i++) ksmf[i]=(ll)ksmf[i]*cs%p;
	polyexp(ksmf,g,biglim);
	if (k!=1)
	{
		for (i=0;i<biglim;i++) g[i]=(ll)g[i]*k%p;
	}
	if (wy)
	{
		for (i=biglim-1;i>=wy;i--) g[i]=g[i-wy];
		memset(g,0,wy<<2);  
	}
}
void polyksm2(int *f,int *g,int biglim,int cs)
{
	int limit=1,i,l=-1;
	while (limit<=biglim)
	{
		limit<<=1;++l;
	}
	int xs=ksm(f[0],p-2);
	for (i=1;i<n;i++) f[i]=(ll)f[i]*xs%p;
	xs=ksm(f[0],mm);f[0]=1;
	for (i=1;i<limit;i++) r[i]=r[i>>1]>>1|(i&1)<<l;g[0]=1;
	while (cs)
	{
		if (cs&1)
		{
			memcpy(ksmf,f,biglim<<2);
			memset(ksmf+biglim,0,biglim<<2);
			polymultiply(g,ksmf,biglim);
			memset(g+biglim,0,biglim<<2);
		}
		dft(f,0,limit);
		for (i=0;i<limit;i++) f[i]=(ll)f[i]*f[i]%p;
		dft(f,biglim,limit);
		memset(f+biglim,0,biglim<<2);
		cs>>=1;
	}//printf("%d %d\n",xs,g[0]);
	for (i=0;i<n;i++) g[i]=(ll)g[i]*xs%p;
}
void polyksm3(int *f,int *g,int biglim,int cs)
{
	int i;
	memset(ksmf,0,biglim<<3);
	memset(g,0,biglim<<3);
	polyln(f,ksmf,biglim);
	for (i=0;i<biglim;i++) ksmf[i]=(ll)ksmf[i]*cs%p;
	polyexp(ksmf,g,biglim);
}
void polysin(int *f,int *g,int biglim)
{
	int i;
	for (i=0;i<biglim;i++) g[i]=(ll)f[i]*I%p;
	polyexp(g,sinf,biglim);
	for (i=0;i<biglim;i++) if ((g[i]=p-(ll)f[i]*I%p)==p) g[i]-=p;
	polyexp(g,sing,biglim);
	for (i=0;i<biglim;i++) g[i]=(ll)(sinf[i]-sing[i]+p)*II%p;
	for (i=0;i<biglim;i++) if (g[i]&1) g[i]=g[i]+p>>1; else g[i]>>=1;
}
void polycos(int *f,int *g,int biglim)
{
	int i;
	for (i=0;i<biglim;i++) g[i]=(ll)f[i]*I%p;
	polyexp(g,cosf,biglim);
	for (i=0;i<biglim;i++) if ((g[i]=p-(ll)f[i]*I%p)==p) g[i]-=p;
	polyexp(g,cosg,biglim);
	for (i=0;i<biglim;i++) if ((g[i]=cosf[i]+cosg[i])>=p) g[i]-=p;
	for (i=0;i<biglim;i++) if (g[i]&1) g[i]=g[i]+p>>1; else g[i]>>=1;
}
void polytan(int *f,int *g,int biglim)
{
	polysin(f,tanf,biglim);
	polycos(f,tang,biglim);
	polyinv(tang,g,biglim);
	polymultiply(g,tanf,biglim);
}
void polycot(int *f,int *g,int biglim)
{
	polysin(f,cotf,biglim);
	polycos(f,cotg,biglim);
	polyinv(cotf,g,biglim);
	polymultiply(g,cotg,biglim);
}

int main(){
	int j,k;
	scanf("%d%d",&n,&k);
	m=n/2;
	n/=2;n*=9;
	limit=1;
	while (limit<=n) limit<<=1;
	for(i=1;i<=k;i++){
		scanf("%d",&j);f[j]++;
	}
	gg(limit<<1);
	polyksm1(f,g,limit,m);
	//for (i=0;i<n;i++) printf("%d ",g[i]);
	long long res=0;
	for(i=0;i<=n;i++){
		res+=1ll*g[i]*g[i];res%=p;
	}
	printf("%lld",res);
}