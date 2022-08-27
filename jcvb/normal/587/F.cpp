#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;
const int inf=2147483647;
struct query{
	int i,k;int id;int sg;
}que[222222];
int n,q;
char buf[222222],*ptr=buf;
char *str[111111];int len[111111];
ll ans[111111];
int SZ = 333;
int cmpk(const query&a,const query&b){
	if(a.k==b.k)return a.i<b.i;
	return a.k<b.k;
}
int cmpi(const query&a,const query&b){
	return a.i<b.i;
}

struct node{
	int ch[26],p,l;
}t[222222];int ndtot,las;
int sz[222222];
int ord[222222];
void saminit(){
	while(ndtot){
		cl(t[ndtot].ch);
		t[ndtot].p=t[ndtot].l=0;
		sz[ndtot]=0;
		ndtot--;
	}
}
int add(int c){
	int p=las,np=++ndtot;
	t[np].l=t[p].l+1;
	sz[np]=1;
	for(;p && !t[p].ch[c];p=t[p].p)t[p].ch[c]=np;
	if(!p){
		t[np].p=1;
	}else{
		int q=t[p].ch[c];
		if(t[q].l==t[p].l+1)t[np].p=q;
		else{
			int nq=++ndtot;
			t[nq]=t[q];
			t[nq].l=t[p].l+1;
			t[q].p=t[np].p=nq;
			for(;p && t[p].ch[c]==q;p=t[p].p)t[p].ch[c]=nq;
		}
	}
	return np;
}
int cmpl(int i,int j){
	return t[i].l<t[j].l;
}
int ch[111111][26];
int le[111111];
int fail[111111];
int qu[111111];
void build(){
	int p=0,q=0;
	qu[q++]=0;
	while(p!=q){
		int u=qu[p++];
		for (int i=0;i<26;i++)
			if(ch[u][i]){
				int v=ch[u][i];
				qu[q++]=v;
				if(u==0)fail[v]=0;
				else fail[v]=ch[fail[u]][i];
			}else ch[u][i]=ch[fail[u]][i];
	}
}
struct edge{
	int v,next;
}e[222222];int g[222222];int etot=0;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int ind=0;
int dfn[222222],rig[222222];
void dfs(int u){
	dfn[u]=++ind;
	for (int i=g[u];~i;i=e[i].next)dfs(e[i].v);
	rig[u]=++ind;
}
int su[222222];
int suu[222222];
void bladd(int i,int d){
	int id=(i-1)/SZ+1;
	for (int j=i;j<=id*SZ;j++)su[j]+=d;
	for (int k=id;k<=ind/SZ+1;k++)suu[k]+=d;
}
int blque(int i){
	int id=(i-1)/SZ+1;
	return su[i]+suu[id-1];
}
int main()
{
	gn(n);gn(q);
	for (int i=1;i<=n;i++){
		scanf("%s",ptr);
		len[i]=strlen(ptr);
		str[i]=ptr;
		ptr+=len[i]+1;
	}
	for (int i=1;i<=q;i++){
		int l,r,k;
		gn(l);gn(r);gn(k);
		que[i*2-1]=(query){l-1,k,i,-1};
		que[i*2]=(query){r,k,i,+1};
	}
	q*=2;

	sort(que+1,que+1+q,cmpk);
	for (int i=1;i<=q;i++)if(i==1 || que[i].k!=que[i-1].k)
		if(len[que[i].k]>=SZ){
			int j=i;
			for (;j<=q && que[j].k==que[i].k;j++);
			saminit();

			las=ndtot=1;
			for (int k=0;k<len[que[i].k];k++)las=add(str[que[i].k][k]-'a');
			for (int x=1;x<=ndtot;x++)ord[x]=x;
			sort(ord+1,ord+1+ndtot,cmpl);
			for (int x=ndtot;x>=2;x--)sz[t[ord[x]].p]+=sz[ord[x]];

			ll su=0;
			for (int k=0,cur=i;k<=n;k++){
				if(k!=0){
					int p=1;
					for (int l=0;l<len[k];l++){
						p=t[p].ch[str[k][l]-'a'];
					}
					if(p)su+=sz[p];
				}
				while(cur<j && que[cur].i==k){
					ans[que[cur].id]+=que[cur].sg*su;
					cur++;
				}
			}
		}

	ndtot=1;
	for (int i=1;i<=n;i++){
		int p=0;
		for (int j=0;j<len[i];j++){
			if(!ch[p][str[i][j]-'a'])ch[p][str[i][j]-'a']=ndtot++;
			p=ch[p][str[i][j]-'a'];
		}
		le[i]=p;
	}
	build();
	memset(g,-1,sizeof(g));
	for (int i=1;i<ndtot;i++)ae(fail[i],i);
	dfs(0);
	sort(que+1,que+1+q,cmpi);
	for (int k=0,cur=1;k<=n;k++){
		if(k!=0){
			bladd(dfn[le[k]],+1);
			bladd(rig[le[k]],-1);
		}
		while(cur<=q && que[cur].i==k){
			if(len[que[cur].k]<SZ){
				ll su=0;
				int p=0;
				for (int j=0;j<len[que[cur].k];j++){
					p=ch[p][str[que[cur].k][j]-'a'];
					su+=blque(dfn[p]);
				}
				ans[que[cur].id]+=que[cur].sg*su;
			}
			cur++;
		}
	}
	q/=2;
	for (int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
	return 0;
}