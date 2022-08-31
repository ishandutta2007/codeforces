#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,d[100001];
int head[100001],nxt[200001],b[200001],k,con[100001][2];
int low[100001],dfn[100001],now,ans[100001],stk[100001],top,S,q[100001],h,t;
bool instack[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
//	printf("push %d %d\n",s,t);
}
std::vector<int>vec[100001];
void tarjan(int x){
	low[x]=dfn[x]=++now;
	instack[x]=1;
	stk[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]])tarjan(b[i]),low[x]=std::min(low[x],low[b[i]]);
		else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
	if(low[x]==dfn[x]){
		++S;
		do{
			ans[stk[top]]=S;
			vec[S].push_back(stk[top]);
			instack[stk[top]]=0;
			--top;
		}while(stk[top+1]!=x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),con[i][0]=u,con[i][1]=v;
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)head[i]=0;
	k=0;
	for(int i=1;i<=m;i++)
		if(ans[con[i][0]]!=ans[con[i][1]])++d[ans[con[i][1]]],push(ans[con[i][0]],ans[con[i][1]]);
	for(int i=1;i<=S;i++)if(!vec[i].empty()&&!d[i])q[++t]=i;
	while(h<t){
//		printf("%d %d\n",h,t);
		if(h+1==t){
			printf("! %d\n",vec[q[h+1]].back());
			return 0;
		}
		int x=q[h+1],y=q[h+2];
		int u=vec[x].back(),v=vec[y].back();
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int t;
		scanf("%d",&t);
		if(t==0){
			std::swap(x,y);
			std::swap(q[h+1],q[h+2]);
		}
		vec[y].pop_back();
		if(vec[y].empty()){
			std::swap(q[h+1],q[h+2]);
			++h;
			for(int i=head[y];i;i=nxt[i])
				if(!(--d[b[i]]))q[++::t]=b[i];
		}
	}
}