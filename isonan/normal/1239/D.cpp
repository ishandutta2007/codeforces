#include <cstdio>
#include <algorithm>

int t,n,m,head[1000001],nxt[2000001],b[2000001],k,cnt,dfn[1000001],low[1000001],now,stk[1000001],top,ans[1000001],con[1000001][2],S,size[1000001];
bool vis[1000001],instack[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void tarjan(int x){
	stk[++top]=x;
	instack[x]=1;
	dfn[x]=low[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]]){
			tarjan(b[i]);
			low[x]=std::min(low[x],low[b[i]]);
		}
		else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
	if(dfn[x]==low[x]){
		++S;
		do{
			instack[stk[top]]=0;
			ans[stk[top]]=S;
			--top;
			++size[S];
		}while(stk[top+1]!=x);
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)head[i]=vis[i]=dfn[i]=low[i]=instack[i]=size[i]=0;
		now=0;
		k=0;
		cnt=0;
		S=0;
		top=0;
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			con[i][0]=u,con[i][1]=v;
			push(u,v);
		}
		for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
		if(S==1){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=1;i<=m;i++)
				if(ans[con[i][0]]!=ans[con[i][1]]){
					vis[ans[con[i][0]]]=1;
				}
			int p=0;
			for(int i=1;i<=n;i++)
				if(!vis[ans[i]]){
					p=ans[i];
					break;
				}
			printf("%d %d\n",size[p],n-size[p]);
			for(int i=1;i<=n;i++)if(ans[i]==p)printf("%d ",i);putchar('\n');
			for(int i=1;i<=n;i++)if(ans[i]!=p)printf("%d ",i);putchar('\n');
		}
	}
}