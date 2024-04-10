#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int n,m;
char str[400010];
int hash(int i,int j){
	return (i-1)*m+j;
}
int head[400010],nxt[2000010],b[2000010],k;
int con[2000010][2],top;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void Push(int s,int t){
	++top;
	con[top][0]=s;
	con[top][1]=t;
	push(s,t);
}
bool vis[400010];
int vis2[400010];
int last[400010],a[400010];
int mn[400010],orig[400010],cnt,L[400010],R[400010];
namespace Tarjan{
	int dfn[400010],low[400010],stk[400010],top,now,ans[400010],S;
	bool instack[400010];
	void tarjan(int x){
		dfn[x]=low[x]=++now;
		instack[x]=1;
		stk[++top]=x;
		for(int i=head[x];i;i=nxt[i])
			if(!dfn[b[i]]){
				tarjan(b[i]);
				low[x]=std::min(low[x],low[b[i]]);
			}
			else if(instack[b[i]])
				low[x]=std::min(low[x],dfn[b[i]]);
		if(low[x]==dfn[x]){
			++S;
			mn[S]=0x7f7f7f7f;
			do{
				ans[stk[top]]=S;
				if(vis2[stk[top]])mn[S]=std::min(mn[S],vis2[stk[top]]);
				instack[stk[top--]]=0;
			}while(stk[top+1]!=x);
			if(mn[S]==0x7f7f7f7f)mn[S]=0;
		}
	}
}
using Tarjan::tarjan;
using Tarjan::dfn;
using Tarjan::ans;
using Tarjan::S;
int mx[400010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		for(int j=1;j<=m;++j)
			vis[hash(i,j)]=(str[j]=='#');
	}
	for(int i=1;i<=m;++i)scanf("%d",a+i);
	for(int i=n;i;--i){
		for(int j=1;j<=m;++j)
			if(vis[hash(i,j)]){
				if(last[j])Push(hash(i,j),hash(last[j],j));
				if(!(--a[j]))vis2[hash(i,j)]=j;
				last[j]=i;
			}
		for(int j=1;j<=m;++j)
			if(vis[hash(i,j)]){
				if(i>1&&vis[hash(i-1,j)])Push(hash(i,j),hash(i-1,j));
				if(last[j-1])Push(hash(i,j),hash(last[j-1],j-1));
				if(last[j+1])Push(hash(i,j),hash(last[j+1],j+1));
			}
	}
	for(int i=1;i<=n*m;++i)
		if(vis[i]&&!dfn[i])tarjan(i);
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=top;++i)
		if(ans[con[i][0]]!=ans[con[i][1]])push(ans[con[i][0]],ans[con[i][1]]);
	for(int i=S;i;--i){
		if(mn[i]){
			for(int j=head[i];j;j=nxt[j])
				mn[b[j]]=-1;
		}
	}
	for(int i=1;i<=S;++i)if(mn[i]>0)orig[++cnt]=mn[i];
	std::sort(orig+1,orig+cnt+1);
	for(int i=1;i<=S;++i)if(mn[i]>0)mn[i]=std::lower_bound(orig+1,orig+cnt+1,mn[i])-orig;
	for(int i=1;i<=S;++i){
		L[i]=cnt+1,R[i]=0;
		if(mn[i]>0)L[i]=R[i]=mn[i];
		for(int j=head[i];j;j=nxt[j])
			L[i]=std::min(L[i],L[b[j]]),
			R[i]=std::max(R[i],R[b[j]]);
		if(L[i]<=R[i])mx[L[i]-1]=std::max(mx[L[i]-1],R[i]);
	}
	for(int i=1;i<=cnt;++i)mx[i]=std::max(mx[i-1],mx[i]);
	int ans=0,now=0;
	while(now<cnt)++ans,now=mx[now];
	printf("%d\n",ans);
}