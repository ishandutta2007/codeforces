#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;
	template<class IT>inline void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
	}
};
using io::gi;
template<class IT>inline void _int(      IT &a,      IT &b  ){if(a>b)swap(a,b);}
template<class IT>inline void cmin(      IT &a,const IT &b=0){if(a>b)a=b;}
template<class IT>inline void cmax(      IT &a,const IT &b=0){if(a<b)a=b;}
template<class IT>inline IT   _min(const IT &a,const IT &b=0){return a>b? b:a;}
template<class IT>inline IT   _max(const IT &a,const IT &b=0){return a<b? b:a;}
template<class IT>inline IT   _abs(const IT &a              ){return a<0?-a:a;}

const int N=600005;
int h[N],f[N],g[N];
char s[N];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int L=1,R=1,n,m=0,t=0,z,y=0,x,l,r,k,j,i;
	scanf("%d",&n);if(n&1){printf("0\n1 1");return 0;}
	scanf("%s",s+1);
	for(i=1;i<=n;++i){if(s[i]=='(')h[i]=++t;else cmin(m,h[i]=--t);}
	if(t){printf("0\n1 1");return 0;}
	for(i=1;i<=n;++i)s[i+n]=s[i];
	for(i=1;i<=n;++i)h[i+n]=h[i];
	for(i=1;i<=n;++i)if(h[i]==m)f[++t]=i;
	++m;f[t+1]=n+f[1];
//	for(i=1;i<=t;++i)printf("%d ",f[i]);printf("F\n");
	for(i=1;i<=t;++i){
		for(x=0,j=l=f[i]+1,r=f[i+1];j<r;++j)if(h[j]==m)g[++x]=j;++m;
//		for(j=1;j<=x;++j)printf("%d ",g[j]);printf("G\n");
		for(j=1;j<x;++j){
			z=0;
			for(k=l=g[j]+1,r=g[j+1];k<r;++k)if(h[k]==m)++z;
			if(y<z){y=z;L=l;R=r;}
		}
		--m;
	}
//	printf("y=%d\n",y);
	y+=t;
	for(i=1;i<=t;++i){
		for(x=0,j=l=f[i]+1,r=f[i+1];j<r;++j)if(h[j]==m)++x;
		if(y<x){y=x;L=l;R=r;}
	}
	printf("%d\n%d %d",y,(L-1)%n+1,(R-1)%n+1);
	return 0;
}