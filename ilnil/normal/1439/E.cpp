#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;++i)
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
int m,ss;
struct nod{
	P a;
	int dis[35],dir[35],len;
	void work(){
		P o=a;
		len=0;
		fo(i,0,29){
			if(o.fi>>i&1){
				if(len>0&&dir[len]==0)dis[len]+=1<<i;
				else dir[++len]=0,dis[len]=1<<i;
				o.fi-=1<<i;
			}
			if(o.se>>i&1){
				if(len>0&&dir[len]==1)dis[len]+=1<<i;
				else dir[++len]=1,dis[len]=1<<i;
				o.se-=1<<i;
			}
		}
		reverse(dis+1,dis+len+1);
		reverse(dir+1,dir+len+1);
	}
}a[N],b[N],s[N*4];
int fa[N*4],bz[N*4],bz2[N*4],dep[N*4],nums;
map<P,int>num;
vector<int>e[N*4];
int sts,st[N*4];
map<int,int>ad;
void R(nod &a){
	scanf("%d%d",&a.a.fi,&a.a.se);
	a.work();
	s[++ss]=a;
}
bool cmp2(nod a,nod b){return a.a==b.a;}
bool cmp(nod a,nod b){
	if(a.a==b.a)return 0;
	fo(i,1,min(a.len,b.len)){
		if(a.dir[i]!=b.dir[i])return a.dir[i]<b.dir[i];
		if(a.dis[i]<b.dis[i]){
			if(i==a.len)return 1;
			return a.dir[i+1]<b.dir[i];
		}
		if(b.dis[i]<a.dis[i]){
			if(i==b.len)return 0;
			return a.dir[i]<b.dir[i+1];
		}
	}
	return a.len<b.len;
}
P lca(nod a,nod b){
	if(a.a==b.a)return a.a;
	P o=P(0,0);
	fo(i,1,min(a.len,b.len)){
		if(a.dir[i]!=b.dir[i])return o;
		int dis=min(a.dis[i],b.dis[i]);
		a.dir[i]?o.se+=dis:o.fi+=dis;
		if(a.dis[i]!=b.dis[i])return o;
	}
	return o;
}
void link(int x,int y){
	fa[y]=x;e[x].push_back(y);
//	printf("%d %d %d\n",x,y,dep[y]);
}
void dfs(int x){
	for(int i:e[x])dfs(i),bz[x]+=bz[i];
	if(bz[x])ad[dep[x]]^=1,ad[dep[fa[x]]]^=1;else
	if(bz2[x])ad[dep[x]]^=1,(dep[x]>0?ad[dep[x]-1]^=1:0);
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&m);
	fo(i,1,m)R(a[i]),R(b[i]);
	sort(s+1,s+ss+1,cmp);
	ss=unique(s+1,s+ss+1,cmp2)-s-1;
	fo(i,2,ss)s[++ss].a=lca(s[i-1],s[i]),s[ss].work();
	sort(s+1,s+ss+1,cmp);
	ss=unique(s+1,s+ss+1,cmp2)-s-1;
//	fo(i,1,ss)fo(j,i+1,ss)
//		if(!(cmp(s[i],s[j])==1&&cmp(s[j],s[i])==0)){
//			int kk=0;
//		}
	fo(i,1,ss){
		num[s[i].a]=++nums;
		dep[nums]=s[i].a.fi+s[i].a.se;
		if(!sts){
			st[++sts]=i;
			continue;
		}
		for(;lca(s[st[sts]],s[i])!=s[st[sts]].a;)--sts;
		assert(sts);
		link(num[s[st[sts]].a],nums);
		st[++sts]=i;
	}
	fo(i,1,m){
		int x=num[a[i].a],y=num[b[i].a],z=num[lca(a[i],b[i])];
//		printf("%d %d %d\n",x,y,z);
		bz[x]++;bz[y]++;bz[z]-=2;
		bz2[z]=1;
	}
	dfs(1);
	int ans=0,c=0;
	for(auto i=ad.rbegin(),_e=ad.rend();i!=_e;++i){
		if((*i).se==1)++ans,c^=1;
//		printf("%d %d\n",(*i).fi,(*i).se);
	}
	if(c==1&&(*ad.begin()).fi>0)++ans;
	printf("%d\n",ans);
}