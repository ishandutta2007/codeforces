#include<bits/stdc++.h>
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
const int N=100010,LOG=20;
const ll inf=1e18;
int n,m,s,tot,st[LOG][N][2];
int nxt[N<<6],to[N<<6],hd[N<<6],C;
int opt,v,l,r,u,k;
ll d[N<<6],val[N<<6],w;
void link(int u,int v,int w){
	to[++C]=v,val[C]=w,nxt[C]=hd[u],hd[u]=C;
}
int q[N<<6],x,in[N<<6];
mt19937 rnd(time(0));
void chk(int g){
	if(d[q[l]]>d[q[g]])swap(q[g],q[l]);
}
signed main(){
	read(n,m,s),tot=n;
	for(rgi i=1;i<=n;++i)st[0][i][0]=st[0][i][1]=i;
	for(rgi w=1;w<LOG;++w){
		for(rgi i=1;i+(1<<w)-1<=n;++i){
			st[w][i][0]=++tot;
			link(st[w-1][i][0],tot,0),link(st[w-1][i+(1<<w-1)][0],tot,0);
			st[w][i][1]=++tot;
			link(tot,st[w-1][i][1],0),link(tot,st[w-1][i+(1<<w-1)][1],0);
		}
	}
	while(m--){
		read(opt,v);
		if(opt==1)read(u,w),link(v,u,w);
		else{
			read(l,r,w),k=log2(r-l+1);
			if(opt==2)link(v,st[k][l][1],w),link(v,st[k][r-(1<<k)+1][1],w);
			else link(st[k][l][0],v,w),link(st[k][r-(1<<k)+1][0],v,w);
		}
	}
	for(rgi i=1;i<=tot;++i)d[i]=inf;
	d[q[l=r=1]=s]=0;
	while(r>=l){
		for(rgi i=r;i>=l&&i>=r-3;--i)chk(i);
		for(rgi i=5;i;--i)chk(l+rnd()%(r-l+1));
		in[x=q[l++]]=0;
		for(rgi i=hd[x];i;i=nxt[i]){
			if(d[v=to[i]]>d[x]+val[i]){
				d[v]=d[x]+val[i];
				if(!in[v])in[q[++r]=v]=1;
			}
		}
	}
	for(rgi i=1;i<=n;++i)printf("%lld ",d[i]==inf?-1:d[i]);
	return 0;
}