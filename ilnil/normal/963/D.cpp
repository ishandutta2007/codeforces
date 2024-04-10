#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll unsigned int
#define min(a,b)(a<b?a:b)
using namespace std;
const int N=1e5+5;
int q,k,g,pp[N],ps,X,Y;
char a[N],ch;
int ts,rt[N*2];
int f32[32]={0,1,28,2,29,14,24,3,30,22,20,15,25,17,4,8,31,27,13,23,21,19,16,7,26,12,18,6,11,5,10,9};
struct no{int l,r;ll v;}t[N*52];
void chh(int &v,int l,int r){
	v=++ts;t[v].v|=(ll)1<<Y;
	if(l==r)return;
	int m=l+r>>1;
	if(X<=m)chh(t[v].l,l,m);else chh(t[v].r,m+1,r);
}
void mer(int &v,int v1,int l,int r){
	if(!v1)return;
	if(!v){v=v1;return;}
	if(l==r){t[++ts]=t[v];t[v=ts].v|=t[v1].v;return;}
	int m=l+r>>1;
	t[++ts]=t[v];v=ts;
	mer(t[v].l,t[v1].l,l,m);mer(t[v].r,t[v1].r,m+1,r);
	t[v].v=t[t[v].l].v|t[t[v].r].v;
}
void fi(int v,int l,int r){
	if(!t[v].v)return;
	if(l==r){
		for(ll j=t[v].v,k;k=j&-j,k;j-=k)
			pp[++ps]=(l<<5)|f32[(k*0x077CB531U)>>27];
		return;
	}
	int m=l+r>>1;
	fi(t[v].l,l,m);fi(t[v].r,m+1,r);
}
struct sam{
	int n,nn,v,nv,la,tt,no,s[N*2][26],pr[N*2],ri[N*2],d[N*2],T[N*2],D[N*2],aa[N*2];
	void add(int x){
		for(d[no=++tt]=d[la]+1;!s[la][x];la=pr[la])s[la][x]=no;ri[no]++;aa[no]=n;
		if(d[v=s[la][x]]==d[la]+1)pr[no]=v;else{
			d[nv=++tt]=d[la]+1;pr[nv]=pr[v];
			memcpy(s[nv],s[v],sizeof s[v]);
			for(pr[no]=pr[v]=nv;s[la][x]==v;la=pr[la])s[la][x]=nv;
		}la=no;
	}
	void init(){
		fo(i,0,25)s[0][i]=1;
		la=tt=1;d[0]=-1;
		for(;(ch=getchar())>='a'&&ch<='z';)n++,add(ch-'a');nn=n>>5;
		fo(i,1,tt){
			T[d[i]]++;
			if(aa[i])X=aa[i]>>5,Y=aa[i]&31,chh(rt[i],0,nn);
		}
		fo(i,1,n)T[i]+=T[i-1];
		fo(i,1,tt)D[T[d[i]]--]=i;
		fd(i,2,tt){
			v=D[i];ri[pr[v]]+=ri[v];
			mer(rt[pr[v]],rt[v],0,nn);
		}
	}
	int run(){
		no=1;
		fo(i,1,g){
			if(!s[no][a[i]])return -1;
			no=s[no][a[i]];
		}
		if(ri[no]<k)return -1;
		ps=0;
		fi(rt[no],0,nn);
		int mi=n+1;
		fo(i,1,ps-k+1)mi=min(mi,pp[i+k-1]-pp[i]+g);
		return mi;
	}
}tr;
int main(){
	tr.init();
	for(scanf("%d",&q);q--;){
		scanf("%d",&k);g=0;
		for(;(ch=getchar())<'a'||ch>'z';);
		for(;ch>='a'&&ch<='z';ch=getchar())a[++g]=ch-'a';
		printf("%d\n",tr.run());
	}
}