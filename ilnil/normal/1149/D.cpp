#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define P pair<int,int>
#define F first
#define S second
#define pb push_back
#define ll long long
#define max(a,b)(a>b?a:b)
using namespace std;
const int N=75,M=205,inf=1e9,ho=1e5+7;
int h[ho],wh[ho];
int n,m,a,b,an[N],x,y,ss,d[N][(1<<17)+5];
int f[N],si[N],be[N],bs;
int vv[N*N],as;
vector<P>v[N];
struct no{int x,y,v;}p[M];
bool cmp(no x,no y){return x.v<y.v;}
int F(int x){return x==f[x]?x:f[x]=F(f[x]);}
#define _(x)(be[f[x]]?1<<be[f[x]]-1:0)
struct nod{int x,s;};
vector<nod>Q[N*N];
int ha(int x){
	int y=x%ho;
	for(;wh[y]&&h[y]!=x;)++y==ho?y=0:0;
	return y;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	fo(i,1,m)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].v);
	sort(p+1,p+m+1,cmp);
	fo(i,1,n)f[i]=i,si[i]=1,an[i]=inf;
	fo(i,1,m){
		x=p[i].x;y=p[i].y;
		if(p[i].v==b){
			if(F(x)!=F(y))v[x].pb(P(y,b)),v[y].pb(P(x,b));
			continue;
		}
		v[x].pb(P(y,a));
		v[y].pb(P(x,a));
		if((x=F(x))!=(y=F(y)))si[x]+=si[y],f[y]=x;
	}
	fo(i,1,n)if(F(i)==i&&si[i]>3)be[i]=++bs;
	fo(i,0,n-1)fo(j,0,n-1-i)vv[++as]=i*a+j*b;
	sort(vv+1,vv+as+1);
	fo(i,0,as)h[ha(vv[i])]=vv[i],wh[ha(vv[i])]=i;
	
	fo(i,1,n)fo(j,0,1<<bs)d[i][j]=inf;
	Q[1].pb((nod){1,_(1)});
	an[1]=d[1][_(1)]=0;
	fo(o,1,as)for(auto &g:Q[o]){
		x=g.x;
		if(d[x][g.s]>vv[o])continue;
		for(auto &i:v[x]){
			ss=g.s;
			if(f[x]!=f[i.F]){
				if(ss&_(i.F))continue;
				ss|=_(i.F);
			}
			if(d[x][g.s]+i.S<d[i.F][ss]){
				d[i.F][ss]=d[x][g.s]+i.S;
				an[i.F]=min(an[i.F],d[i.F][ss]);
				Q[wh[ha(d[i.F][ss])]].pb((nod){i.F,ss});
			}
		}
	}
	fo(i,1,n)printf("%d ",an[i]);
}