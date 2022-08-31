#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int head[7001],nxt[8000001],b[8000001],v[8000001],k=1,n,left[3001],lt,right[3001],rt,dis[7001],q[100001],h,t,S,T,p[7001];
int prime[200001],top;
bool pri[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val){
	push(s,t,val);
	push(t,s,0);
}
bool bfs(){
	h=t=0;
	q[++t]=S;
	dis[S]=0;
	for(int i=1;i<=T;i++)dis[i]=-1;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&dis[b[i]]==-1){
				dis[b[i]]=dis[q[h]]+1;
				if(b[i]==T)return 1;
				q[++t]=b[i];
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],std::min(v[i],flow-used));
			v[i]-=w;
			v[i^1]+=w;
			used+=w;
			if(w)p[x]=i;
			if(flow==used)return flow;
		}
	if(!used)dis[x]=0;
	return used;
}
signed main(){
	scanf("%lld",&n);
	S=0,T=(n<<1)+1;
	for(int i=1,t1,t2;i<=n;i++){
		scanf("%lld",&t1);
		for(int j=1;j<=t1;j++){
			scanf("%lld",&t2);
			link(i,t2+n,100000000000000000ll);
		}
	}
	long long sum=0;
	for(int i=1,tem;i<=n;i++){
		scanf("%lld",&tem);
		link(S,i,1000000000ll-tem);
		sum+=1000000000ll-tem;
	}
	for(int i=1;i<=n;i++)link(i+n,T,1000000000ll);
	int ans=0;
	while(bfs()){
		memcpy(p,head,sizeof p);
		ans+=dfs(S,0x7f7f7f7f);
	}
	printf("%lld\n",ans-sum);
}