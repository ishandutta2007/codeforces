#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ui unsigned int
#define ll long long
#define max(a,b)(a>b?a:b)
#define _(x)(x&-x)
using namespace std;
const int N=5e5+5,M=1e6+5;
int n,nn,x,a[N],m,p[N],q[N],an[N],la[N],ne[N],c[N],f[M],ans,tot,t[N];
int T[1<<16],T2[1<<16];
struct no{
	int x,w;
	no(int _x,int _w){x=_x;w=_w;T[x&65535]++;T2[x>>16]++;}
	no(){}
}b[M],z[M];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void P(int n){
	char c[20];int j=0;
	for(;n;n/=10)c[++j]=n%10+48;
	while(j)putchar(c[j--]);putchar('\n');
}
bool cmp(no x,no y){return x.x<y.x;}
int main(){
//	freopen("kite.in","r",stdin);
//	freopen("kite.out","w",stdout);
	R(n);R(m);
	fo(i,1,n)R(a[i]),b[i]=no(a[i],i);
	fo(i,1,m)R(x),R(c[i]),ne[i]=la[x],la[x]=i,b[n+i]=no(c[i],n+i);
	fo(i,1,65535)T[i]+=T[i-1],T2[i]+=T2[i-1];
	fd(i,1,n+m)z[T[b[i].x&65535]--]=b[i];
	fd(i,1,n+m)b[T2[z[i].x>>16]--]=z[i];
	fo(i,1,n+m){
		if(!nn||b[i].x!=b[nn].x)b[++nn]=b[i];
		if(b[i].w>n)c[b[i].w-n]=nn;else a[b[i].w]=nn;
	}
	fo(i,1,n){
		for(int j=la[i];j;j=ne[j]){
			ans=0;
			for(int x=c[j]-1;x;x-=_(x))ans=max(ans,f[x]);
			an[j]=ans+1;
		}
		ans=0;
		for(int x=a[i]-1;x;x-=_(x))ans=max(ans,f[x]);
		p[i]=ans+1;tot=max(tot,p[i]);
		for(int x=a[i];x<=nn;x+=_(x))f[x]=max(f[x],ans+1);
	}
	memset(f,0,sizeof f);
	fd(i,1,n){
		for(int j=la[i];j;j=ne[j]){
			ans=0;
			for(int x=nn-c[j];x;x-=_(x))ans=max(ans,f[x]);
			an[j]+=ans;
		}
		ans=0;
		for(int x=nn-a[i];x;x-=_(x))ans=max(ans,f[x]);
		q[i]+=ans;
		for(int x=nn-a[i]+1;x<=nn;x+=_(x))f[x]=max(f[x],ans+1);
	}
	fo(i,1,n)t[p[i]]+=p[i]+q[i]==tot;
	fo(i,1,n)for(int j=la[i];j;j=ne[j])
		if(p[i]+q[i]==tot&&t[p[i]]==1)an[j]=max(an[j],tot-1);else an[j]=max(an[j],tot);
	fo(i,1,m)P(an[i]);
}