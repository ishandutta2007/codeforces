#include <cstdio>
#include <cassert>
#include <algorithm>

int n;
int head[100001],nxt[200001],b[200001],k,st[300001][21],dep[100001];
int fa[100001][21];
int start[100001],now,Log[300001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	st[++now][0]=dep[x];
	start[x]=now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			st[++now][0]=dep[x];
		}
}
int dist(int x,int y){
	int ans=dep[x]+dep[y];
	x=start[x],y=start[y];
	if(x>y)std::swap(x,y);
	int k=Log[y-x+1];
	return ans-(std::min(st[x][k],st[y-(1<<k)+1][k])<<1);
}
long long ans=0;
struct info{
	int u,v,d;
	bool add(int x){
		int d1=dist(u,x),d2=dist(v,x);
		if(d1>d||d2>d){
			if(d1>=d2)v=x,d=d1;
			else u=x,d=d2;
			return 1;
		}
		return 0;
	}
}tem[100001];
std::vector<std::pair<int,int> >que[100001];
long long S[200001],T[200001];
struct cen{
	int head[200001],nxt[400001],b[400001],k,mx[200001],full,root,size[200001],n;
	long long sum[200001],cnt[200001];
	long long sum2[200001],cnt2[200001];
	bool vis[200001];
	std::vector<int>fa[200001],dis[200001];
	void push(int s,int t){
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
	}
	void link(int s,int t){
//		printf("%d %d\n",s,t);
		push(s,t);
		push(t,s);
	}
	void getdis(int x,int f,int rt,int dis=0){
		fa[x].push_back(rt);
		cen::dis[x].push_back(dis);
		size[x]=1;
		for(int i=head[x];i;i=nxt[i])
			if(!vis[b[i]]&&b[i]!=f){
				getdis(b[i],x,rt,dis+1);
				size[x]+=size[b[i]];
			}
	}
	void getroot(int x,int f){
		size[x]=1,mx[x]=0;
		for(int i=head[x];i;i=nxt[i])
			if(!vis[b[i]]&&b[i]!=f){
				getroot(b[i],x);
				size[x]+=size[b[i]];
				mx[x]=std::max(mx[x],size[b[i]]);
			}
		mx[x]=std::max(mx[x],full-size[x]);
		if(mx[x]<mx[root])root=x;
	}
	void solve(int rt){
		vis[rt]=1;
		getdis(rt,0,rt,0);
		for(int i=head[rt];i;i=nxt[i])
			if(!vis[b[i]]){
				mx[root=0]=full=size[b[i]];
				getroot(b[i],0);
				solve(root);
			}
	}
	void init(){
		mx[root=0]=full=n;
		getroot(1,0);
		solve(root);
	}
	void add(int x,int y){
//		printf("Add %d %d\n",x,y);
		for(int i=0;i<fa[x].size();i++){
//			printf("%d\n",fa[x][i]);
			sum[fa[x][i]]+=dis[x][i]*y;
			cnt[fa[x][i]]+=y;
			if(i){
				sum2[fa[x][i]]+=dis[x][i-1]*y;
				cnt2[fa[x][i]]+=y;
			}
		}
	}
	long long query(int x){
		long long tot=0;
		for(int i=0;i<fa[x].size();i++){
//			printf("%d %d %d\n",fa[x][i],sum[fa[x][i]],cnt[fa[x][i]]);
			tot+=1ll*cnt[fa[x][i]]*dis[x][i]+sum[fa[x][i]];
			if(i<(int)fa[x].size()-1){
				tot-=1ll*cnt2[fa[x][i+1]]*dis[x][i]+sum2[fa[x][i+1]];
			}
		}
//		printf("query %d %d\n",x,tot);
		return tot;
	}
}c;
int getmid(int u,int v){
	if(dep[u]<dep[v])std::swap(u,v);
	int x=dist(u,v);
//	printf("getmid %d %d %d ",u,v,x);
	int l=x>>1;
	for(int i=20;~i;--i)
		if(l>=(1<<i))l-=1<<i,u=fa[u][i];
//	printf("%d\n",u+(x&1)*(n-1));
	return u+(x&1)*(n-1);
}
void solve(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	tem[mid+1]=(info){mid+1,mid+1,0};
	tem[mid]=(info){mid,mid,0};
	for(int i=mid+2;i<=r;i++)tem[i]=tem[i-1],tem[i].add(i);
	for(int i=mid-1;i>=l;i--)tem[i]=tem[i+1],tem[i].add(i);
	S[l-1]=0;
	for(int i=l;i<=mid;i++)S[i]=S[i-1]+tem[i].d,que[i].clear();
//	long long ans=0;
	for(int i=mid+1;i<=r;i++){
		int L=l,R=mid,M,A=mid+1;
		while(L<=R){
			M=(L+R)>>1;
			info now=tem[i];
			if(now.add(tem[M].u)||now.add(tem[M].v))L=M+1;
			else R=M-1,A=M;
		}
		L=l,R=mid,M;
		int B=mid+1;
//		for(int M=mid,last=0;M>=l;--M){
//			info now=tem[i];
//			now.add(tem[M].u);
//			now.add(tem[M].v);
//			printf("%d %d %d %d\n",tem[M].u,tem[M].v,now.u,now.v);
////			printf("%d %d\n",dist(tem[M].u,tem[M].v),dist(tem[M].u,tem[i].u));
//			if(tem[i].u==now.u||tem[i].v==now.v)assert(!last);
//			else last=1;
//		}
		while(L<=R){
			M=(L+R)>>1;
			info now=tem[i];
			now.add(tem[M].u);
			now.add(tem[M].v);
			if(tem[i].u==now.u||tem[i].v==now.v)R=M-1,B=M;
			else L=M+1;
		}
//		printf("%d %d %d\n",i,A,B);
//		assert(A>=B);
		ans+=(1ll*tem[i].d*(mid+1-A)+S[B-1])*2ll+S[A-1]-S[B-1];
		info now=tem[i];
		now.add(tem[B].u);
		now.add(tem[B].v);
		int p=(now.u==tem[i].u)?now.u:now.v;
		que[B].push_back(std::make_pair(p,1));
		que[A].push_back(std::make_pair(p,-1));
//		printf("%d\n",p);
	}
//	printf("%d\n",tem[l].d);
	info now=tem[l];
	now.add(tem[r].u);
	now.add(tem[r].v);
	int k=getmid(tem[l].u,tem[l].v);
//	printf("%d %d %d %d %d %d\n",k,dist(k,tem[l].u),dist(k,tem[l].v),dist(k,tem[r].u),dist(k,tem[r].v),tem[r].u);
//	printf("%d\n",now.d);
//	printf("%d\n",ans);
	for(int i=mid;i>=l;--i){
		c.add(getmid(tem[i].u,tem[i].v),1);
		for(int j=0;j<que[i].size();j++)
			ans+=(1ll*c.query(que[i][j].first)*que[i][j].second);
	}
	for(int i=mid;i>=l;--i)
		c.add(getmid(tem[i].u,tem[i].v),-1);
//	long long cnt=0;
//	for(int i=l;i<=mid;i++)
//		for(int j=mid+1;j<=r;j++){
//			info now=tem[j];
//			now.add(tem[i].u);
//			now.add(tem[i].v);
//			cnt+=now.d;
//		}
//	printf("solve %d %d\n",l,r);
//	printf("%lld %lld\n",cnt,ans>>1);
//	assert(cnt==ans>>1);
//	::ans+=ans;
	solve(l,mid);
	solve(mid+1,r);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=2;i<=now;i++)Log[i]=Log[i>>1]+1;
	for(int j=1;(1<<j)<=now;j++)
		for(int i=1;i+(1<<j)-1<=now;i++)
			st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	c.n=(n<<1)-1;
	for(int i=2;i<=n;i++)
		c.link(i,i+n-1),c.link(i+n-1,fa[i][0]);
//	c.init();
//	long long cnt=0;
//	int l,r,mid;
//	freopen("CON","r",stdin);
//	scanf("%d%d%d",&l,&mid,&r);
//	solve(l,r,mid);
//	printf("%d\n",n);
//	for(int i=1;i<=n;i++){
//		info tem=(info){i,i,0};
//		for(int j=i+1;j<=n;j++){
//			tem.add(j);
//			cnt+=tem.d;
//		}
//	}
	c.init();
	solve(1,n);
	printf("%lld\n",ans>>1ll);
}