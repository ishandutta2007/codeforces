#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define db double
#define abs(x)(x>0?x:-(x))
using namespace std;
const int N=3e5+5;
const db eps=1e-9;
int n,m,q,qs,x,y,z,ans,rt;
vector<int>e[N],e2[N];
map<int,int>pos[N];
int si[N],fa[N],qu[N];
bool vi[N];
struct node{
	db ang;int sum;
};
vector<node>c[N];
struct nod{
	db x,y;
	nod(db _x=0,db _y=0){x=_x;y=_y;}
	nod operator-(const nod &b){return nod(x-b.x,y-b.y);}
}a[N];
db cross(nod a,nod b){return a.x*b.y-a.y*b.x;}
db ang(nod a,nod b){return atan2(a.y-b.y,a.x-b.x);}
bool cmp(node a,node b){return a.ang<b.ang;}
void dfs(int x){
	si[x]=1;vi[x]=1;
	for(int i:e[x])if(!vi[i]){
		fa[i]=x;
		e2[x].push_back(i);
		dfs(i);
		si[x]+=si[i];
	}
	qs=0;
	for(int i:e2[x])c[x].push_back((node){ang(a[i],a[x]),-si[i]});
	c[x].push_back((node){ang(a[fa[x]],a[x]),si[x]});
	sort(c[x].begin(),c[x].end(),cmp);
	fd(i,0,c[x].size()-2)c[x][i].sum+=c[x][i+1].sum;
}
int get(vector<node>&c,db x){
	int pos=upper_bound(c.begin(),c.end(),(node){x,0},cmp)-c.begin();
	return pos==c.size()?0:c[pos].sum;
}
int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,m)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	a[0].x=1e9+5;
	fo(i,1,n){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if(a[i].x<a[rt].x)rt=i;
	}
	a[0]=nod(-2e9,-2e9);
	dfs(rt);
	scanf("%d",&q);
	fo(o,1,q){
		scanf("%d",&qs);
		fo(i,1,qs)scanf("%d",&qu[i]);
		db sum=0;
		fo(i,2,qs-1)
			sum+=cross(a[qu[i]]-a[qu[1]],a[qu[i+1]]-a[qu[1]]);
		if(sum<-eps)reverse(qu+2,qu+qs+1);
		qu[0]=qu[qs];qu[qs+1]=qu[1];
		ans=0;
		fo(i,1,qs){
			db x=ang(a[qu[i-1]],a[qu[i]]),y=ang(a[qu[i+1]],a[qu[i]]);
			int z=qu[i];
			if(x<y)ans+=get(c[z],x+eps)-get(c[z],y-eps);
			else ans+=c[z][0].sum-(get(c[z],y-eps)-get(c[z],x+eps));
		}
		printf("%d\n",ans);
	}
}