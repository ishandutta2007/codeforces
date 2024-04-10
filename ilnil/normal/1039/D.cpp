#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y)(ne2[++js]=la2[x],la2[x]=js,tt[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define cmax(a,b)(b>a?a=b:0)
using namespace std;
const int N=1e5+5;
int n,x,y,la[N],ne[N*2],to[N*2],js,an[N],d[N],fa[N],f[N];
int la2[N],ne2[N],tt[N];
void get(int o){
	int ts=0,g;
	fd(i,1,n){
		x=d[i];g=0;
		for(int i=la2[x];i&&~g;i=ne2[i]){
			if(g+f[tt[i]]+1>=o)++ts,g=-1;else 
			if(g<f[tt[i]])g=f[tt[i]];
		}
		f[x]=g+1;
	}
	an[o]=ts;
}
void calc(int l,int r,int vl,int vr){
	if(r-l<=1)return;
	if(vl==vr){
		fo(i,l,r)an[i]=vl;
		return;
	}
	int mi=l+r>>1;get(mi);
	int vm=an[mi];
	calc(l,mi,vl,vm);calc(mi,r,vm,vr);
}
int main(){
	scanf("%d",&n);
	fo(i,2,n)scanf("%d%d",&x,&y),link(x,y),link(y,x);
	js=0;
	for(int t=0,w=d[1]=1;x=d[t+1],t++<w;)
		ff(i,x)if(to[i]!=fa[x])fa[to[i]]=x,d[++w]=to[i],link2(x,to[i]);
	get(n);an[1]=n;
	calc(1,n,n,an[n]);
	fo(i,1,n)printf("%d\n",an[i]);
}