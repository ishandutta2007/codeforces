#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(x)for(int i=la[x];i;i=ne[i])
#define max(x,y)(d[x]<d[y]?x:y)
#define xam(x,y)(x>y?x:y)
#define ll long long
using namespace std;
const int N=2e5+5,M=4e5+5;
int n,m,q,la[N],ne[N],d[N],f[18][N],x,y,lc,df[N],en[N],ds;
int h[18][N],ps,ts,rt[N],ans,pl,pr,g[N];
struct no{int x,y;}p[M];
struct tree{int v,l,r;}t[M*20];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void P(int n){
	if(!n){putchar('0');putchar('\n');return;}
	if(n<0)putchar('-'),n=-n;
	char c[20];int j=0;
	for(;n;n/=10)c[++j]=n%10+48;
	while(j)putchar(c[j--]);putchar('\n');
}
void go(int x){
	d[x]=d[f[0][x]]+1;df[x]=++ds;
	fo(i,1,g[d[x]]){
		if(!f[i-1][x])break;
		f[i][x]=f[i-1][f[i-1][x]];
	}
	ff(x)go(i);en[x]=ds;
}
void dfs(int x){
	ff(x)dfs(i),h[0][x]=max(h[0][x],h[0][i]);
}
bool cmp(no x,no y){return x.x<y.x;}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	fd(i,0,g[d[x]-d[y]])if(d[x]-d[y]>=1<<i)x=f[i][x];
	if(x==y)return x;
	fd(i,0,g[d[x]])if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
void ch(int &v,int l,int r,int x){
	t[++ts]=t[v];v=ts;t[v].v++;
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch(t[v].l,l,m,x);else ch(t[v].r,m+1,r,x);
}
int qu(int v,int l,int r){
	if(!v||pl<=l&&r<=pr)return t[v].v;
	int m=l+r>>1;
	return (pl<=m?qu(t[v].l,l,m):0)+(pr>m?qu(t[v].r,m+1,r):0);
}
int main(){
//	freopen("car.in","r",stdin);
//	freopen("car.out","w",stdout);
	R(n);
	fo(i,2,n)R(f[0][i]),ne[i]=la[f[0][i]],la[f[0][i]]=i;
	fo(i,1,n)h[0][i]=i;
	fo(i,2,n)g[i]=g[i>>1]+1;
	go(1);
	R(m);
	fo(i,1,m){
		R(x);R(y);
		lc=lca(x,y);
		h[0][x]=max(h[0][x],lc);
		h[0][y]=max(h[0][y],lc);
		if(x!=lc&&y!=lc){
			if(df[x]>df[y])swap(x,y);
			p[++ps]=(no){df[x],df[y]};
		}
	}
	dfs(1);
	sort(p+1,p+ps+1,cmp);
	int j=1;
	fo(i,1,n){
		rt[i]=rt[i-1];
		for(;j<=ps&&p[j].x==i;j++)ch(rt[i],1,n,p[j].y);
	}
	fo(i,1,17)fo(j,1,n)h[i][j]=h[i-1][h[i-1][j]];
	for(R(q);q--;){
		R(x);R(y);lc=lca(x,y);
		if(x==lc)swap(x,y);
		ans=0;
		if(y==lc){
			if(x!=lc){
				fd(i,0,g[d[x]])if(h[i][x]&&d[h[i][x]]>d[lc])ans+=1<<i,x=h[i][x];
				if(d[h[0][x]]<=d[lc])ans++;else ans=-1;	
			}
		}else{
			fd(i,0,xam(g[d[x]],g[d[y]])){
				if(h[i][x]&&d[h[i][x]]>d[lc])ans+=1<<i,x=h[i][x];
				if(h[i][y]&&d[h[i][y]]>d[lc])ans+=1<<i,y=h[i][y];
			}
			if(df[x]>df[y])swap(x,y);
			pl=df[y];pr=en[y];
			if(qu(rt[en[x]],1,n)-qu(rt[df[x]-1],1,n))ans++;else{
				if(d[h[0][x]]<=d[lc]&&d[h[0][y]]<=d[lc])ans+=2;else ans=-1;
			}
		}
		P(ans);
	}
}