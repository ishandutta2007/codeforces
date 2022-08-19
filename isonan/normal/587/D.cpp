#include <cstdio>
#include <vector>
#include <cstring> 
#include <algorithm>

int n,m,con[100001][4],pre[100001],suf[100001],cnt;
int head[1000001],nxt[2000001],b[2000001],k;
int edg[1000001][2],Top;
int low[1000001],dfn[1000001],now,stk[1000010],top,ans[1000001],S;
bool instack[1000001],vis[1000001];
void push(int s,int t,bool bb=1){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	if(bb)++Top,edg[Top][0]=s,edg[Top][1]=t;
}
void tarjan(int x){
	dfn[x]=low[x]=++now;
	stk[++top]=x;
	instack[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]])tarjan(b[i]),low[x]=std::min(low[x],low[b[i]]);
		else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
	if(low[x]==dfn[x]){
		++S;
		do{
			ans[stk[top]]=S;
			instack[stk[top]]=0;
			--top;
		}while(stk[top+1]!=x);
	}
}
bool judge(int u){
	for(int i=1;i<=S;i++)vis[i]=0;
	for(int i=1;i<=m;i++)if(con[i][3]>u)vis[ans[i+m]]=1;
	for(int i=S;i;i--)
		if(vis[i])
			for(int j=head[i];j;j=nxt[j])
				vis[b[j]]=1;
	for(int i=1;i<=m;i++)if(!vis[ans[i]]&&!vis[ans[i+m]])vis[std::min(ans[i],ans[i+m])]=1;
	for(int i=S;i;i--)
		if(vis[i])
			for(int j=head[i];j;j=nxt[j])
				vis[b[j]]=1;
	for(int i=1;i<=m;i++)if(vis[ans[i]]&&vis[ans[i+m]])return 0;
	return 1;
} 
std::vector<int>adj[100001];
bool cmp(int a,int b){return con[a][2]<con[b][2]||(con[a][2]==con[b][2]&&a<b);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&con[i][0],&con[i][1],&con[i][2],&con[i][3]);
		adj[con[i][0]].push_back(i);
		adj[con[i][1]].push_back(i);
	}
	cnt=m<<1;
	for(int i=1;i<=n;i++){
		if(!adj[i].size())continue;
		for(int j=0;j<adj[i].size()-1;++j){
			pre[j]=++cnt;
			push(pre[j],adj[i][j]+m);
			if(j)push(pre[j],pre[j-1]);
		}
		for(int j=adj[i].size()-1;j>0;--j){
			suf[j]=++cnt;
			push(suf[j],adj[i][j]+m);
			if(j<adj[i].size()-1)push(suf[j],suf[j+1]);
		}
		for(int j=0;j<adj[i].size();++j){
			if(j)push(adj[i][j],pre[j-1]);
			if(j<adj[i].size()-1)push(adj[i][j],suf[j+1]);
		}
		std::sort(adj[i].begin(),adj[i].end(),cmp);
		for(int j=0,last=-1;j<adj[i].size();++j){
			if(j==adj[i].size()-1||con[adj[i][j]][2]!=con[adj[i][j+1]][2]){
				for(int k=last+1;k<j;++k){
					pre[k]=++cnt;
					push(pre[k],adj[i][k]);
					if(k>last+1)push(pre[k],pre[k-1]);
				}
				for(int k=j;k>last+1;--k){
					suf[k]=++cnt;
					push(suf[k],adj[i][k]);
					if(k<j)push(suf[k],suf[k+1]);
				}
				for(int k=last+1;k<=j;k++){
					if(k>last+1)push(adj[i][k]+m,pre[k-1]);
					if(k<j)push(adj[i][k]+m,suf[k+1]);
				}
				last=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++)if(!dfn[i])tarjan(i);
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=Top;i++)
		if(ans[edg[i][0]]!=ans[edg[i][1]])
			push(ans[edg[i][0]],ans[edg[i][1]],0);
	int l=0,r=1000000000,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==-1){puts("No");return 0;}
	puts("Yes");
	judge(ans);
	std::vector<int>out;
	for(int i=1;i<=m;i++)if(vis[::ans[i]])out.push_back(i);
	printf("%d %d\n",ans,out.size());
	for(int i=0;i<out.size();i++)
		printf("%d ",out[i]);
}