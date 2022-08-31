#include <cstdio>
#include <cstring>
#include <algorithm>

int n,k,x[1001],y[1001],top;
int head[1001],nxt[1000010],b[1000010],K,d[1001],mid,pre[1000010];
bool good=0;
bool vis[1001];
int time[1001];
void push(int s,int t){
	nxt[++K]=head[s];
	pre[head[s]]=K;
	head[s]=K;
	b[K]=t;
	++d[t];
}
struct edge{
	int u,v,dis;
}num[1000010];
bool cmp(edge a,edge b){
	return a.dis>b.dis;
}
bool ans[1001];
int cnt,stk[1001],Top;
void dfs(int x,int used=0){
	if(used>k)return;
	if(x>n){
		good=1;
		memcpy(ans,vis,sizeof ans);
		return;
	}
	if(vis[x]){
		dfs(x+1,used);
		return;
	}
	int last=Top;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[b[i]]){
			vis[b[i]]=1;
			stk[++Top]=b[i];
			for(int j=head[b[i]];j;j=nxt[j]){
				--d[b[j]];
				if(pre[j^1])nxt[pre[j^1]]=nxt[j^1];
				if(nxt[j^1])pre[nxt[j^1]]=pre[j^1];
				if(head[b[j]]==(j^1))head[b[j]]=nxt[j^1];
			}
			++used;
		}
	dfs(x+1,used);
	while(Top>last){
		for(int j=head[stk[Top]];j;j=nxt[j]){
			if(pre[j^1])nxt[pre[j^1]]=j^1;
			if(nxt[j^1])pre[nxt[j^1]]=j^1;
			if(head[b[j]]==nxt[j^1])head[b[j]]=j^1;
			++d[b[j]];
		}
		vis[stk[Top--]]=0;
		--used;
	}
	if(d[x]<=1)return;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(pre[i^1])nxt[pre[i^1]]=nxt[i^1];
		if(nxt[i^1])pre[nxt[i^1]]=pre[i^1];
		if(head[b[i]]==(i^1))head[b[i]]=nxt[i^1];
		--d[b[i]],++cnt;
	}
	dfs(x+1,used+1);
	vis[x]=0;
	for(int i=head[x];i;i=nxt[i]){
		if(pre[i^1])nxt[pre[i^1]]=i^1;
		if(nxt[i^1])pre[nxt[i^1]]=i^1;
		if(head[b[i]]==nxt[i^1])head[b[i]]=i^1;
		++d[b[i]];
	}
//	printf("%d\n",cnt);
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			num[++top]=(edge){i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
//			printf("%d %d %d\n",i,j,num[top].dis);
		}
	std::sort(num+1,num+top+1,cmp);
	int l=1,r=top;
	while(l<=r){
		mid=(l+r)>>1;
		memset(head,0,sizeof head);
		memset(d,0,sizeof d);
		memset(vis,0,sizeof vis);
		K=1;
		good=0;
		for(int i=1;i<=mid;i++)push(num[i].u,num[i].v),push(num[i].v,num[i].u);
		int u=0;
		for(int i=1;i<=n;i++)
			if(d[i]>k){
				vis[i]=1;
				for(int j=head[i];j;j=nxt[j])--d[b[j]];
				++u;
			}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				while(vis[b[head[i]]])head[i]=nxt[head[i]];
				for(int j=head[i];j;j=nxt[j])
					while(vis[b[nxt[j]]])nxt[j]=nxt[nxt[j]];
			}
		dfs(1,u);
//		printf("%d\n",mid);
		if(good){
			l=mid+1;
		}
		else r=mid-1;
	}
//	printf("%d\n",cnt);
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=ans[i];
	for(int i=1;i<=n;i++)if(!ans[i]&&cnt<k)ans[i]=1,++cnt;
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
}