#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=2e5+5;
int n,ans;
int s[N*2][26],pr[N*2],d[N*2],pos[N*2],tt,v,nv,no,la,T[N*2],D[N*2];
int fa[N*2],an[N*2];
int rt[N*2],tot;
struct nod{int l,r;}t[N*80];
char c[N];
#define nw(x)(d[++tt]=d[x]+1,tt)
void add(int x,int p){
	for(no=nw(la);!s[la][x];la=pr[la])s[la][x]=no;
	pos[no]=p;
	if(d[v=s[la][x]]==d[la]+1)pr[no]=v;else{
		nv=nw(la);pr[nv]=pr[v];pr[no]=pr[v]=nv;
		pos[nv]=pos[v];
		memcpy(s[nv],s[v],sizeof s[v]);
		for(;s[la][x]==v;la=pr[la])s[la][x]=nv;
	}la=no;
}
void ins(int &v,int l,int r,int x){
	v=++tot;
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ins(t[v].l,l,m,x);else ins(t[v].r,m+1,r,x);
}
int mer(int v,int v1,int l,int r){
	if(!v||!v1)return v|v1;
	int m=l+r>>1,a=++tot;
	t[a].l=mer(t[v].l,t[v1].l,l,m);
	t[a].r=mer(t[v].r,t[v1].r,m+1,r);
	return a;
}
int ck(int v,int l,int r,int pl,int pr){
	if(!v)return 0;
	if(pl<=l&&r<=pr)return 1;
	int m=l+r>>1;
	return (pl<=m&&ck(t[v].l,l,m,pl,pr))||(m<pr&&ck(t[v].r,m+1,r,pl,pr));
}
int main(){
	scanf("%d\n%s",&n,c+1);
	tt=la=1;d[0]=-1;
	fo(i,0,25)s[0][i]=1;
	fo(i,1,n)
		add(c[i]-'a',i),ins(rt[la],1,n,i);
	fo(i,1,tt)T[d[i]]++;
	fo(i,1,n)T[i]+=T[i-1];
	fd(i,1,tt)D[T[d[i]]--]=i;
	fd(i,2,tt)
		rt[pr[D[i]]]=mer(rt[pr[D[i]]],rt[D[i]],1,n);
	ans=1;
	fo(i,2,tt){
		int x=D[i],y=pr[x];
		if(y==1){
			an[x]=1;fa[x]=x;continue;
		}
		if(ck(rt[fa[y]],1,n,pos[x]-d[x]+d[fa[y]],pos[x]-1))
			an[x]=an[y]+1,fa[x]=x,ans=max(ans,an[x]);
		else 
			an[x]=an[y],fa[x]=fa[y];
	}
	cout<<ans;
}