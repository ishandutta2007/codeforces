#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=105,inf=1e8;
int n,m,u,v,c,f,js;
int la[N],ans,dt,in[N];
int d[N*N*8],ds,fr[N],h[N];
bool bz[N];
struct nod{int ne,y,l,c;}e[N*8];
void link(int u,int v,int l,int c){
	e[++js]=(nod){la[u],v,l,c};la[u]=js;
	e[++js]=(nod){la[v],u,0,-c};la[v]=js;
}
int main(){
	cin>>n>>m;js=1;
	fo(i,1,m){
		cin>>u>>v>>c>>f;
		in[v]+=f;in[u]-=f;
		if(c<f){
			dt+=f-c;
			link(v,u,c,1);
			link(v,u,f-c,0);
			link(u,v,inf,2);
		}else{
			link(v,u,f,1);
			link(u,v,c-f,1);
			link(u,v,inf,2);
		}
	}
	link(n,1,inf,0);
	fo(i,1,n)
		if(in[i]<0)link(i,n+1,-in[i],0);
		else link(0,i,in[i],0);
	for(;;){
		fo(i,0,n+1)h[i]=inf;
		d[1]=0;h[0]=0;
		for(int l=0,r=1,x,y;x=d[++l],l<=r;bz[x]=0)
			for(int i=la[x];i;i=e[i].ne)
				if(e[i].l&&h[x]+e[i].c<h[y=e[i].y]){
					h[y]=h[x]+e[i].c;
					fr[y]=i;
					if(!bz[y])bz[y]=1,d[++r]=y;
				}
		if(h[n+1]==inf)break;
		int mi=inf;
		for(int x=n+1;x;x=e[fr[x]^1].y)
			mi=min(mi,e[fr[x]].l);
		ans+=mi*h[n+1];
		for(int x=n+1;x;x=e[fr[x]^1].y)
			e[fr[x]].l-=mi,e[fr[x]^1].l+=mi;
	}
	cout<<ans+dt;
}