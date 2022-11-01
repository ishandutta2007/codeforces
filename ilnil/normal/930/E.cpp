#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define ll long long
#define max(a,b)(a>b?a:b)
using namespace std;
const int N=1e5+5,mo=1e9+7;
int k,n,m,nn,x,w[N*2],l[2][N*2],zz[2][N*2];
ll an,f[2][N*2],s[2][N*2],sf[N*2];
struct no{int x,y;}a[2][N];
bool bz[2][N*2];
ll ksm(ll x,int y){ll t=1;for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;return t;}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d%d",&k,&n,&m);w[++nn]=0;
	fo(i,1,n)scanf("%d%d",&a[0][i].x,&a[0][i].y),w[++nn]=a[0][i].y;
	fo(i,1,m)scanf("%d%d",&a[1][i].x,&a[1][i].y),w[++nn]=a[1][i].y;
	sort(w+1,w+nn+1);nn=unique(w+1,w+nn+1)-w-1;
	fo(i,1,n){
		x=a[0][i].x;a[0][i].x=lower_bound(w+1,w+nn+1,a[0][i].x)-w-1;
		a[0][i].y=lower_bound(w+1,w+nn+1,a[0][i].y)-w;
		if(x>zz[0][a[0][i].y])l[0][a[0][i].y]=a[0][i].x,zz[0][a[0][i].y]=x;
	}
	fo(i,1,m){
		x=a[1][i].x;a[1][i].x=lower_bound(w+1,w+nn+1,a[1][i].x)-w-1;
		a[1][i].y=lower_bound(w+1,w+nn+1,a[1][i].y)-w;
		if(x>zz[1][a[1][i].y])l[1][a[1][i].y]=a[1][i].x,zz[1][a[1][i].y]=x;
	}
	fo(i,1,nn){
		if(zz[0][i-1]>=zz[0][i])zz[0][i]=zz[0][i-1],bz[0][i]=1;
		if(zz[1][i-1]>=zz[1][i])zz[1][i]=zz[1][i-1],bz[1][i]=1;
	}
	sf[1]=1;f[0][1]=1;
	fo(i,2,nn){
		if(!bz[0][i])f[0][i]=(mo*2-ksm(2,zz[0][i]-1)*sf[l[0][i]]%mo-s[0][i-1]+s[0][l[0][i]])%mo;
		if(!bz[1][i])f[1][i]=(mo*2-ksm(2,zz[1][i]-1)*sf[l[1][i]]%mo-s[1][i-1]+s[1][l[1][i]])%mo;
		s[0][i]=(s[0][i-1]+f[0][i])%mo;
		s[1][i]=(s[1][i-1]+f[1][i])%mo;
		sf[i]=(sf[i-1]+(f[0][i]+f[1][i])*ksm(2,mo-1-w[i]))%mo;
	}
	printf("%I64d",sf[nn]*ksm(2,k)%mo);
}