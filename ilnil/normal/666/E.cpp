#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=5e5+5,M=5e4+5;
char c[N];
int n,m,q,l,r,pl,pr;
int rt[N*2],ts,ans[N],ans2[N];
struct nod{int l,r,i,le;};
vector<nod>Q[N*2];
vector<pair<int,int>>ch[N*2];
bool cmp(nod a,nod b){return a.le>b.le;}
struct tree{
	int l,r,mx,w;
}t[M*17],an;
void up(tree &z,tree x,tree y){
	if(x.mx>=y.mx)z.mx=x.mx,z.w=x.w;else z.mx=y.mx,z.w=y.w;
}
void add(int &v,int l,int r,int x){
	if(!v)v=++ts;
	if(l==r){
		++t[v].mx;t[v].w=l;
		return;
	}
	int m=l+r>>1;
	if(x<=m)add(t[v].l,l,m,x);else add(t[v].r,m+1,r,x);
	up(t[v],t[t[v].l],t[t[v].r]);
}
void mer(int &v,int v1,int l,int r){
	if(!v||!v1){v^=v1;return;}
	if(l==r){
		t[v].mx+=t[v1].mx;
		return;
	}
	int m=l+r>>1;
	mer(t[v].l,t[v1].l,l,m);
	mer(t[v].r,t[v1].r,m+1,r);
	up(t[v],t[t[v].l],t[t[v].r]);
}
void qry(int v,int l,int r){
	if(pl<=l&&r<=pr||!v){
		up(an,an,t[v]);
		return;
	}
	int m=l+r>>1;
	if(pl<=m)qry(t[v].l,l,m);
	if(m<pr)qry(t[v].r,m+1,r);
}
struct SAM{
	int s[N*2][26],pr[N*2][19],d[N*2],t[N],w[N*2],wz[N],n,v,nv,no,la,tt;
	void init(){
		d[0]=-1;la=tt=1;
		fo(i,0,25)s[0][i]=1;
	}
	#define nw(x)(d[++tt]=x+1,tt)
	void add(int x){
		for(no=nw(d[la]);!s[la][x];la=pr[la][0])s[la][x]=no;
		if(d[v=s[la][x]]==d[la]+1)pr[no][0]=v;else{
			nv=nw(d[la]);pr[nv][0]=pr[v][0];pr[v][0]=pr[no][0]=nv;
			memcpy(s[nv],s[v],sizeof s[v]);
			for(;s[la][x]==v;la=pr[la][0])s[la][x]=nv;
		}wz[++n]=la=no;
	}
	void init2(){
		fo(i,1,tt)++t[d[i]];
		fo(i,1,n)t[i]+=t[i-1];
		fo(i,1,tt)w[t[d[i]]--]=i;
		fo(j,1,18)fo(i,1,tt)pr[i][j]=pr[pr[i][j-1]][j-1];
	}
	int get(int r,int len){
		r=wz[r];
		fd(i,0,18)if(d[pr[r][i]]>=len)r=pr[r][i];
		return r;
	}
}A;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	A.init();
	fo(i,1,n)A.add(c[i]-'a');
	A.init2();
	scanf("%d",&m);
	fo(i,1,m){
		scanf("\n%s",c+1);
		int len=strlen(c+1),j=1,s=0;
		fo(k,1,len){
			c[k]-='a';
			for(;!A.s[j][c[k]];)j=A.pr[j][0],s=A.d[j];
			j=A.s[j][c[k]];++s;
			ch[j].push_back(make_pair(s,i));
		}
	}
	scanf("%d",&q);
	fo(i,1,q){
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		int len=pr-pl+1;
		pr=A.get(pr,len);
		Q[pr].push_back((nod){l,r,i,len});
	}
	fd(i,2,A.tt){
		int x=A.w[i],w=ch[x].size()-1;
		sort(ch[x].begin(),ch[x].end());
		sort(Q[x].begin(),Q[x].end(),cmp);
		for(nod j:Q[x]){
			for(;~w&&ch[x][w].first>=j.le;--w)
				add(rt[x],1,m,ch[x][w].second);
			pl=j.l;pr=j.r;an.mx=an.w=0;
			qry(rt[x],1,m);
			if(an.w)ans[j.i]=an.w,ans2[j.i]=an.mx;
			else ans[j.i]=j.l;
		}
		for(;~w;--w)add(rt[x],1,m,ch[x][w].second);
		mer(rt[A.pr[x][0]],rt[x],1,m);
	}
	fo(i,1,q)printf("%d %d\n",ans[i],ans2[i]);
}