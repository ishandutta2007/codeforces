#include <cstdio>
#include <cstring>
#include <algorithm>
 
int n,m,q,rt,head[600001],nxt[6000001],b[6000001],k=1,low[600010],dfn[600010],now,stk[600010],top,S,ans[600010],Ans[600010];
int bel[6000001],fa[300001][21],dep[600001],con[600001][2],Dfn[600010];
int Now;
bool instack[600001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t; 
}
void link(int s,int t){
	if(s==t)return;
//	if(Now==46560)fprintf(stderr,"%d %d\n",s,t);
	push(s,t);
	push(t,s);
}
void dfs(int x,int f){
//	printf("dfs %d %d\n",x,f);
	instack[x]=1;
	stk[++top]=x;
	low[x]=dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(f!=i){
//			printf("%d %d %d %d\n",b[i],x,low[x],dfn[x]);
			if(!dfn[b[i]])dfs(b[i],i^1),low[x]=std::min(low[x],low[b[i]]);
			else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
		}
	if(low[x]==dfn[x]){
		++S;
		bel[S]=rt;
		for(;;){
//			if(Now==46560)fprintf(stderr,"%d ",stk[top]);
			instack[stk[top]]=0;
			ans[stk[top]]=S;
			--top; 
			if(stk[top+1]==x)break;
		}
//		if(Now==46560)fprintf(stderr,"\n");
	}
}
void dfs2(int x,int f){
	Dfn[x]=++now;
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs2(b[i],x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
} 
int R,node[4200010],Que[300010];
int rotate(int element){
   (element+=R)%=n;
   return element?element:n;
}
bool cmp(int a,int b){
	return Dfn[a]<Dfn[b];
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),con[i][0]=u,con[i][1]=v,link(u,v);
	for(int i=1;i<=n;i++)if(!dfn[i])rt=i,dfs(i,0);
	for(int i=1;i<=n;i++)head[i]=0;k=1;
	memcpy(Ans,ans,sizeof ans);
	for(int i=1;i<=m;i++)if(Ans[con[i][0]]!=Ans[con[i][1]])link(Ans[con[i][0]],Ans[con[i][1]]);
	now=0;
	for(int i=1;i<=n;i++)
		if(bel[ans[i]]==i)dfs2(ans[i],0);
	for(int i=1;i<=n;i++)head[i]=instack[i]=dfn[i]=low[i]=0;k=1;
	for(int i=1,n,m;i<=q;i++){
		scanf("%d%d",&n,&m);
		Now=i;
//		if(i==2370)fprintf(stderr,"%d %d\n",n,m);
		for(int j=1;j<=n;j++)scanf("%d",node+j),node[j]=Ans[rotate(node[j])],Que[j]=node[j];//,printf("*%d\n",node[j]);
//		putchar('\n');
//		for(int j=1;j<=n;j++)if(i==46560)fprintf(stderr,"-%d\n",Que[j]);
		int que=n;
		for(int j=1,u,v;j<=m;j++){
			scanf("%d%d",&u,&v);
			u=rotate(u),v=rotate(v);
//			printf("%d %d\n",u,v);
			u=Ans[u],v=Ans[v];
			node[++n]=u,node[++n]=v;
			link(u,v);
		}
		int cnt=n;
		std::sort(node+1,node+n+1,cmp);
		top=0;
//		for(int j=1;j<=n;j++)printf("%d ",node[j]);putchar('\n');
		for(int j=1;j<=cnt;j++){
			int u=node[j];
			if(bel[u]!=bel[stk[top]]){
				for(int k=1;k<top;k++)link(stk[k],stk[k+1]);
				stk[top=1]=Ans[bel[u]];
				node[++n]=Ans[bel[u]];
			}
//			printf("%d %d\n",u,stk[top]);
			if(u==stk[top])continue;
			int lca=LCA(u,stk[top]);
			while(top>1&&dep[stk[top-1]]>=dep[lca])link(stk[top-1],stk[top]),--top;
			if(stk[top]!=lca){
				if(dep[stk[top]]>dep[lca])link(stk[top],lca),stk[top]=node[++n]=lca;
				else stk[++top]=node[++n]=lca;
			}
			stk[++top]=u;
		}
		for(int k=1;k<top;k++)link(stk[k+1],stk[k]);
		top=0;
//		for(int j=1;j<=n;j++)printf("-%d %d\n",node[j],dfn[node[j]]);
//		printf("%d\n",dfn[7]);
		dfs(Que[1],0);
		bool cando=1;
		for(int j=1;j<que;j++)if(Que[j]!=Que[j+1])cando=0;
		if(!cando){
			cando=1;
//			for(int j=1;j<=que;j++)if(i==46560)fprintf(stderr,"%d %d\n",Que[j],ans[Que[j]]);
			for(int j=1;j<que;j++){
				if(ans[Que[j]]!=ans[Que[j+1]]||!dfn[Que[j]])cando=0;
//				if(i==46560)fprintf(stderr,"%d %d %d\n",ans[Que[j]],ans[Que[j+1]],cando);
			}
		}
		if(!cando)puts("NO");
		else puts("YES"),R+=i;
//		printf("%d\n",i);
		R%=::n;
		for(int j=1;j<=n;j++)dfn[node[j]]=low[node[j]]=head[node[j]]=instack[node[j]]=0;
		k=1;
	}
}