#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define gc() (is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
#define flush()(fwrite(out,1,os-out,stdout),os=out)
#define put(x) (*os++=x,os==ot?flush():0)
#define P pair<int,int>
#define abs(x)(x>0?x:-(x))
#define fi first
#define se second
#define dis(x)(abs(d[x.fi]-d[x.se])+1)
#define get_pos(x,len)((d[x.fi]>d[x.se]?pos2[x.fi]:pos[x.fi])+len)
using namespace std;
const int N=3e5+5,Q=1<<21,M=N*2;
char in[Q],*is=in,*it=in,out[Q],*os=out,*ot=out+Q-1,o[30],c;
int n,T,x,y,p,q,ls1,ls2,ans;
P l1[999],l2[999],g[999];
int d[N],fa[N],ld[N],hv[N],pos[N],pos2[N],ds;
vector<int>e[N];
char s[N];
struct SA{
	int a[M],rk[M],sa[M],tp[M],t[M],h[20][M],lg[M],n,m;
	void rsort(){
		fo(i,0,m)t[i]=0;
		fo(i,1,n)++t[rk[tp[i]]];
		fo(i,1,m)t[i]+=t[i-1];
		fd(i,1,n)sa[t[rk[tp[i]]]--]=tp[i];
	}
	#define cmp(x,y)(tp[x]==tp[y]&&tp[x+w]==tp[y+w])
	void init(int _n){
		n=_n;
		fo(i,1,n)rk[tp[i]=i]=a[i];m=255;rsort();
		for(int j=1,w=1;j<n;w<<=1,m=j){
			j=0;
			fo(i,n-w+1,n)tp[++j]=i;
			fo(i,1,n)if(sa[i]>w)tp[++j]=sa[i]-w;
			rsort();memcpy(tp,rk,n*4+4);
			rk[sa[1]]=1;j=1;
			fo(i,2,n)rk[sa[i]]=cmp(sa[i-1],sa[i])?j:++j;
		}
		a[0]=a[n+1]=-1;
		for(int k=0,i=1,j;i<=n;h[0][rk[i++]]=k)
			for(k=k?k-1:0,j=sa[rk[i]-1];a[i+k]==a[j+k];)++k;
		fo(i,2,n)lg[i]=lg[i>>1]+1;
		fo(i,1,lg[n]){
			int nx=1<<i-1;
			fo(j,1,n-nx*2+1)h[i][j]=min(h[i-1][j],h[i-1][j+nx]);
		}
	}
	int get(int x,int y){
		if(x==y)return n-x+1;
		if((x=rk[x])>(y=rk[y]))swap(x,y);++x;
		int K=lg[y-x];
		return min(h[K][x],h[K][y-(1<<K)+1]);
	}
}A;
void R(int &n){
	for(n=0;(c=gc())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}
void W(int n){
	if(!n)put('0');
	for(c=0;n;n/=10)o[++c]=n%10+48;
	for(;c;)put(o[c--]);put('\n');
}
void dfs(int x){
	ld[x]=1;d[x]=d[fa[x]]+1;
	for(int i:e[x])if(i!=fa[x])
		fa[i]=x,dfs(i),ld[x]+=ld[i],(ld[i]>ld[hv[x]]?hv[x]=i:0);
}
void dfs2(int x,int st){
	ld[x]=st;
	pos[x]=++ds;A.a[ds]=s[x];
	pos2[x]=n*2-pos[x]+1;A.a[pos2[x]]=s[x];
	if(!hv[x])return;
	dfs2(hv[x],st);
	for(int i:e[x])if(i!=hv[x]&&i!=fa[x])dfs2(i,i);
}
void get(int x,int y,P *l,int &ls){
	int gs=ls=0;
	for(;ld[x]!=ld[y];)
		if(d[ld[x]]>d[ld[y]])
			l[++ls]=P(x,ld[x]),x=fa[ld[x]];
		else
			g[++gs]=P(ld[y],y),y=fa[ld[y]];
	l[++ls]=P(x,y);
	for(;gs;)l[++ls]=g[gs--];
}
int main(){
	R(n);
	for(;(c=gc())>'z'||c<'a';);
	fo(i,1,n)s[i]=c,c=gc();
	fo(i,2,n)R(x),R(y),e[x].push_back(y),e[y].push_back(x);
	dfs(1);
	dfs2(1,1);
	A.init(n*2);
	for(R(T);T--;){
		R(x);R(y);R(p);R(q);
		get(x,y,l1,ls1);
		get(p,q,l2,ls2);
		ans=0;
		int len1=0,len2=0,w1=1,w2=1;
		for(;w1<=ls1&&w2<=ls2;){
			int can=min(dis(l1[w1])-len1,dis(l2[w2])-len2);
			int wz1=get_pos(l1[w1],len1),wz2=get_pos(l2[w2],len2);
			can=min(can,A.get(wz1,wz2));
			if(!can)break;
			ans+=can;
			if((len1+=can)==dis(l1[w1]))++w1,len1=0;
			if((len2+=can)==dis(l2[w2]))++w2,len2=0;
		}
		W(ans);
	}
	flush();
}