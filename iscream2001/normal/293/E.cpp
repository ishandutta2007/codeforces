#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+50;
typedef long long LL;
int to[N<<1],las[N<<1],fir[N],ds[N<<1],cnt;
inline void add_edge(int u,int v,int a){
	to[++cnt]=v;las[cnt]=fir[u];fir[u]=cnt;ds[cnt]=a;
	to[++cnt]=u;las[cnt]=fir[v];fir[v]=cnt;ds[cnt]=a;
}
inline int max(int u,int v){return u>v?u:v;}
inline int min(int u,int v){return u<v?u:v;}
int n,m,k,x,y;
int f[N],dis[N],dep[N],siz[N],vis[N];
int Cnt,rot,sum;
LL ans;
struct node{
	int dis,dep;
}sth[N];
struct Tree{
	int f[N];
	void insert(int u){
		if(u==0)return;
		for(int i=u;i<=n+1;i+=i&-i)f[i]++;
	}
	void erase(int u){
		if(u==0)return;
		for(int i=u;i<=n+1;i+=i&-i)f[i]--;
	}
	int Ans(int u){
		if(u<=0)return 0;
		int ret=0;
		for(int i=u;i;i&=i-1)ret+=f[i];
		return ret;
	}
}s;
bool mmp(const node &u,const node &v){
	return u.dis<v.dis;
}
void grot(int u,int v){
	siz[u]=1;f[u]=0;
	for(int i=fir[u];i;i=las[i])
	if(to[i]!=v&&!vis[to[i]]){
		grot(to[i],u);
		siz[u]+=siz[to[i]];
		f[u]=max(f[u],siz[to[i]]);
	}
	f[u]=max(f[u],sum-siz[u]);
	if(f[u]<f[rot])rot=u;
}
void gsth(int u,int v){
	sth[++Cnt]=(node){dis[u],dep[u]};
	for(int i=fir[u];i;i=las[i])
	if(to[i]!=v&&!vis[to[i]]){
		dis[to[i]]=dis[u]+ds[i];
		dep[to[i]]=dep[u]+1;
		gsth(to[i],u);
	}
}
LL calc(int u,int Dis,int Dep){
	Cnt=0;
	dis[u]=Dis;dep[u]=Dep;
	gsth(u,0);
	sort(sth+1,sth+Cnt+1,mmp);
	for(int i=1;i<=Cnt;i++)s.insert(sth[i].dep+1);
	int l=1,r=Cnt;LL res=0;
	while(l<r){
		if(sth[l].dis+sth[r].dis<=k){
			s.erase(sth[l].dep+1);
			res+=s.Ans(m-sth[l].dep+1);
			l++;
		}else{
			s.erase(sth[r].dep+1);
			r--;
		}
	}
	s.erase(sth[l].dep+1);
	return res;
}
void solve(int u){
	ans+=calc(u,0,0);vis[u]=1;
	for(int i=fir[u];i;i=las[i])
	if(!vis[to[i]]){
		ans-=calc(to[i],ds[i],1);
		rot=0;sum=siz[to[i]];
		grot(to[i],0);
		solve(rot);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		add_edge(x,i,y);
	}
	f[0]=sum=n;
	grot(1,0);
	solve(rot);
	printf("%I64d\n",ans);
}