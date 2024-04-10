#include <cstdio>
#include <cstring>
#include <algorithm>

int low[200001],dfn[200001],now,stk[200010],top,con[200001][2],Top;
bool instack[200001];
int head[200001],nxt[400001],b[400001],k,T,n,m,ans[200001],S;
char str[200001],cando;
bool vis[200001],cont[200001],hav[200001];
void push(int s,int t,bool bb=0){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	if(!bb){
		++Top;
		con[Top][0]=s;
		con[Top][1]=t;
	}
}
int v(int x){return x>n?x-n:x;}
void tarjan(int x){
	low[x]=dfn[x]=++now;
	stk[++top]=x;
	instack[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]])tarjan(b[i]),low[x]=std::min(low[x],low[b[i]]);
		else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
	if(low[x]==dfn[x]){
		++S;
		int mn=n+1,mx=0,cnt=0;
		do{
			ans[stk[top]]=S;
			instack[stk[top]]=0;
			int tem=v(stk[top]);
			if(vis[tem])mx=std::max(mx,tem),++cnt;
			else mn=std::min(mn,tem);
			--top;
		}while(stk[top+1]!=x);
		if(mn<mx||cnt>1)cando=0;
		cont[S]=hav[S]=cnt;
	}
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=(n<<1);i++)head[i]=vis[i]=cont[i]=hav[i]=low[i]=dfn[i]=instack[i]=ans[i]=str[i]=0;
		k=Top=top=S=now=0;
		cando=1;
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)vis[i]=str[i]=='A';
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			bool bb1=(u>=0),bb2=(v>=0);
			if(!bb1)u=-u;
			if(!bb2)v=-v;
			push(u+(bb1)*n,v+(!bb2)*n);
			push(v+(bb2)*n,u+(!bb1)*n);
		}
		for(int i=1;i<=(n<<1);i++)if(!dfn[i])tarjan(i);
		for(int i=1;i<=n;i++)if(ans[i]==ans[i+n])cando=0;
		for(int i=1;i<=S;i++)head[i]=0;
		k=0;
		for(int i=1;i<=Top;i++)
			if(ans[con[i][0]]!=ans[con[i][1]])
				push(ans[con[i][0]],ans[con[i][1]],1);
		for(int i=S;i;i--)
			if(hav[i])
				for(int j=head[i];j;j=nxt[j]){
					if(cont[b[j]])cando=0;
					hav[b[j]]=1;
				}
		if(cando)puts("TRUE");
		else puts("FALSE");
	}
}