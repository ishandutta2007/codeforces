#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,q,l,r,k,sn;
int s[N][26],st[N],w[N],d[N],fa[N],ss,tt;
int df[N],en[N],su[N],su2[N],o;
ll ans[N],t[N],tot;
struct nod{int l,r,i;};
vector<nod>Q[N];
vector<P>Q2[N];
vector<int>e[N];
char c[N];
void dfs(int x){
	df[x]=++ss;d[ss]=x;
	for(int i:e[x])dfs(i);
	en[x]=ss;
}
int main(){
	scanf("%d%d",&n,&q);
	fo(i,0,25)s[0][i]=1;tt=1;
	fo(i,1,n){
		scanf("\n%s",c+1);
		int len=strlen(c+1),j=1;
		st[i]=ss+1;
		fo(k,1,len){
			c[k]-='a';
			if(!s[j][c[k]])s[j][c[k]]=++tt;
			w[++ss]=j=s[j][c[k]];
		}
	}st[n+1]=ss+1;
	d[1]=1;
	for(int l=0,r=1,x,y,z;x=d[++l],l<=r;)
		fo(i,0,25)if(y=s[x][i]){
			d[++r]=y;
			for(z=fa[x];!s[z][i];)z=fa[z];
			fa[y]=s[z][i];
			e[fa[y]].pb(y);
		}
	sn=sqrt(ss);
	ss=0;dfs(1);
	fo(i,1,q){
		scanf("%d%d%d",&l,&r,&k);
		if(st[k+1]-st[k]>=sn)Q[k].pb((nod){l,r,i});
		else{
			Q2[l-1].pb(P(-k,i));
			Q2[r].pb(P(k,i));
		}
	}
	fo(i,1,n)if(st[i+1]-st[i]>=sn){
		memset(su,0,4*(ss+1));
		fo(j,st[i],st[i+1]-1)++su[w[j]];
		fd(j,1,ss)su[fa[d[j]]]+=su[d[j]];
		fo(j,1,n)t[j]=t[j-1]+su[w[st[j+1]-1]];
		for(nod j:Q[i])ans[j.i]=t[j.r]-t[j.l-1];
	}
	memset(su,0,4*ss+4);
	fo(i,1,n){
		int x=w[st[i+1]-1],wst=df[x]/sn,wen=en[x]/sn;
		if(wst==wen){
			fo(j,df[x],en[x])++su2[j];
		}else{
			fo(j,wst+1,wen-1)++su[j];
			fo(j,df[x],(wst+1)*sn-1)++su2[j];
			fo(j,wen*sn,en[x])++su2[j];
		}
		for(P j:Q2[i]){
			tot=0;o=j.fi<0?j.fi*=-1,-1:1;
			fo(k,st[j.fi],st[j.fi+1]-1){
				x=df[w[k]];
				tot+=su[x/sn]+su2[x];
			}
			ans[j.se]+=tot*o;
		}
	}
	fo(i,1,q)printf("%lld\n",ans[i]);
}