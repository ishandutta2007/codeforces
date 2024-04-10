#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
struct node{
	int l,r;
	int e(){return ~l?abs(r-l)+1:0;}
	void chg(int x){
		rgi k=l<r;
		k?l+=x:l-=x;
		if(k!=(l<r)&&l!=r)l=-1;
	}
}f[99],g[99];
mt19937 rnd(time(0));
const int MD[]={1597623887,1201201201,1856423011,907520777},GB[]={170576683,1201201,6572597,16343071};
const int N=300010,SZ=1;
int n,m,u,v,w,d[N],fa[N],tp[N],sn[N],sz[N],id[N],sq[N],C,ans,t,cf,cg;
char s[N];
struct hash{
	int mod,B;
	ll hl[N],hr[N],p[N];
	int get(node y,int len){
		rgi l=y.l,r=y.r;
		if(l<r)return ((hl[l+len-1]-hl[l-1]*p[len])%mod+mod)%mod;
		return ((hr[l-len+1]-hr[l+1]*p[len])%mod+mod)%mod;
	}
	void init(int x,int y){
		mod=MD[x],B=GB[y],p[0]=1;
		FOR(i,1,n)p[i]=p[i-1]*B%mod,hl[i]=(hl[i-1]*B+s[sq[i]]-'a')%mod;
		ROF(i,n,1)hr[i]=(hr[i+1]*B+s[sq[i]]-'a')%mod;
	}
}ero[SZ];
vector<int>a[N];
void dfs(int x,int f){
	sz[x]=1,d[x]=d[fa[x]=f]+1;
	for(rgi to:a[x])if(to!=f){
		dfs(to,x),sz[x]+=sz[to];
		if(sz[to]>sz[sn[x]])sn[x]=to;
	}
}
void Dfs(int x,int f){
	sq[id[x]=++C]=x,tp[x]=f;
	if(sn[x])Dfs(sn[x],f);
	for(rgi to:a[x])if(to!=fa[x]&&to!=sn[x])Dfs(to,to);
}
int LCA(int u,int v){
	for(;tp[u]!=tp[v];u=fa[tp[u]]){
		if(d[tp[u]]<d[tp[v]])swap(u,v);
	}
	return d[u]<d[v]?u:v;
}
int equ(node x,node y,int len){
	FOR(i,0,SZ-1)if(ero[i].get(x,len)!=ero[i].get(y,len))return 0;
	return 1;
}
void init(node* f,int& c){
	scanf("%d%d",&u,&v),w=LCA(u,v),c=0;
	for(;d[tp[u]]>d[w];u=fa[tp[u]]){
		f[++c]={id[u],id[tp[u]]};
	}
	if(u!=w)f[++c]={id[u],id[w]+1};
	for(t=c;d[tp[v]]>d[w];v=fa[tp[v]]){
		f[++c]={id[tp[v]],id[v]};
	}
	f[++c]={id[w],id[v]},reverse(f+t+1,f+c+1);
}
void find(node x,node y){
	rgi l=0,r=min(x.e(),y.e());
	while(r>l+1){
		rgi mid=(l+r)/2;
		equ(x,y,mid)?l=mid:r=mid;
	}
	ans+=l;
}
signed main(){
	scanf("%d%s",&n,s+1);
	FOR(i,2,n)scanf("%d%d",&u,&v),a[u].pbk(v),a[v].pbk(u);
	static int perm[]={3,1,0,2};
	dfs(1,0),Dfs(1,1),scanf("%d",&m);
	FOR(i,0,SZ-1)ero[i].init(i,perm[i]);
	while(m--){
		init(f,cf),init(g,cg),ans=0,t=1;
		FOR(i,1,cf){
			for(node k=f[i];~k.l&&t<=cg;t+=!~g[t].l){
				rgi len=min(k.e(),g[t].e());
				if(equ(k,g[t],len))ans+=len,k.chg(len),g[t].chg(len);
				else find(k,g[t]),t=cg+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}