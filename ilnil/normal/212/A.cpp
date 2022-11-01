#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define gc()(it==is?it=(is=in)+fread(in,1,Q,stdin),(it==is?EOF:*is++):*is++)
using namespace std;
const int N=305,Q=(1<<21)+1;
char in[Q],*is=in,*it=in,c;
void R(int &n){
	for(n=0;(c=gc())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}
int na,nb,m,k,x,y,du[N*2],ans,be[N*N],w[N],w2[N],kk,c1,c2;
int js,g[N*2],id[10005][305],f[10005][305];
void rv(int x,int c1,int c2){
	swap(f[x][c1],f[x][c2]);
	swap(id[x][c1],id[x][c2]);
	be[id[x][c2]]=c2;
	if(f[x][c2])rv(f[x][c2],c2,c1);
}
int main(){
	R(na);R(nb);R(m);R(k);
	fo(i,1,m){
		R(x);R(y);du[x]++;du[y+na]++;
		if(g[x]%k==0)w[x]=++js;
		if(g[na+y]%k==0)w2[y]=++js;
		g[x]++;g[na+y]++;
		x=w[x];y=w2[y];
		c1=0,c2=0;
		fo(j,1,k)if(!f[x][j]){c1=j;break;}
		fo(j,1,k)if(!f[y][j]){c2=j;break;}
		if(f[y][c1])rv(y,c1,c2);
		f[x][c1]=y;id[x][c1]=i;
		f[y][c1]=x;id[y][c1]=i;
		be[i]=c1;
	}
	fo(i,1,na+nb)ans+=(du[i]%k>0);
	printf("%d\n",ans);
	fo(i,1,m)printf("%d ",be[i]);
}