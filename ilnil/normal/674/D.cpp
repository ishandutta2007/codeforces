#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define x0 s[x][0]
#define x1 s[x][1]
#define add(x,y)(ad[x]+=y,c[x]+=y)
#define ll long long
#define P pair<ll,int>
#define mp(x,y) make_pair(x,y)
#define F first
#define S second
#define cg(i)(A[i].empty()?ch(1,1,n,i,1e18,0):ch(1,1,n,i,(*A[i].begin()).F+e[i],(*A[i].rbegin()).F+e[i]))
using namespace std;
const int N=1e5+5;
int n,m,a[N],d[N],op,x,y,cl[N],cs;
ll b[N],e[N],mi[N*4],ma[N*4],ad[N],dv,dv2;
ll c[N];
set<P>A[N];
void ch(int v,int l,int r,int w,ll x,ll y){
	if(l==r){
		mi[v]=x;ma[v]=y;
		return;
	}
	int m=l+r>>1;
	if(w<=m)ch(v*2,l,m,w,x,y);else ch(v*2|1,m+1,r,w,x,y);
	ma[v]=max(ma[v*2],ma[v*2|1]);
	mi[v]=min(mi[v*2],mi[v*2|1]);
}
int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%lld",&b[i]),d[i]=2;
	fo(i,1,n)scanf("%d",&a[i]),d[a[i]]++;
	fo(i,1,n){
		e[i]=b[i]/d[i];
		c[i]+=b[i]%d[i]+e[i];
		c[a[i]]+=e[i];
	}
	fo(i,1,n)A[a[i]].insert(mp(c[i],i));
	fo(i,1,n)cg(i);
	for(;m--;){
		scanf("%d",&op);
		if(op==3){
			printf("%lld %lld\n",mi[1],ma[1]);
		}
		if(op==2){
			scanf("%d",&x);
			printf("%lld\n",c[x]+e[a[x]]);
		}
		if(op==1){
			scanf("%d%d",&x,&y);
			if(a[x]==y)continue;
			int z=a[x];
			
			A[z].erase(mp(c[x],x));
			
			A[a[a[z]]].erase(mp(c[a[z]],a[z]));
			c[a[z]]-=e[z];
			
			dv=-e[x]-e[z]-b[z]%d[z];d[z]--;
			dv+=(e[z]=b[z]/d[z])+b[z]%d[z];
			
			c[a[z]]+=e[z];
			A[a[a[z]]].insert(mp(c[a[z]],a[z]));cg(a[a[z]]);
			
			A[a[z]].erase(mp(c[z],z));
			c[z]+=dv;
			A[a[z]].insert(mp(c[z],z));
			cg(a[z]);cg(z);
			
			A[a[a[y]]].erase(mp(c[a[y]],a[y]));
			c[a[y]]-=e[y];
			
			dv=e[x]-e[y]-b[y]%d[y];d[y]++;
			dv+=(e[y]=b[y]/d[y])+b[y]%d[y];
			
			c[a[y]]+=e[y];
			A[a[a[y]]].insert(mp(c[a[y]],a[y]));cg(a[a[y]]);
			
			A[a[y]].erase(mp(c[y],y));
			c[y]+=dv;
			A[a[y]].insert(mp(c[y],y));
			cg(a[y]);
			
			A[y].insert(mp(c[x],x));
			cg(y);
			
			a[x]=y;
		}
	}
}