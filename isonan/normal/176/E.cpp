#include <cstdio>
#include <set>

std::set<int>exi;
int head[100001],nxt[200001],b[200001],k,n,q,dep[100001],fa[100001][21],dfn[100001],now,ord[100001];
long long v[200001],ans,length[100001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int f){
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	dfn[x]=++now;
	ord[now]=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			length[b[i]]=length[x]+v[i];
			dfs(b[i],x);
		}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
long long dis(int x,int y){x=ord[x],y=ord[y];return length[x]+length[y]-(length[LCA(x,y)]<<1);}
int main(){
	scanf("%d",&n);
	for(int i=1,s,t,val;i<n;i++){
		scanf("%d%d%d",&s,&t,&val);
		push(s,t,val);
		push(t,s,val);
	}
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1,tem;i<=q;i++){
		char ch=getchar();
		while(ch!='+'&&ch!='-'&&ch!='?')ch=getchar();
		if(ch=='+'){
			scanf("%d",&tem);
			tem=dfn[tem];
			auto x=exi.upper_bound(tem);
			int t1=0,t2=0;
			if(x!=exi.end())t2=*x;
			if(x!=exi.begin())t1=*(--x);
			exi.insert(tem);
			if(t1&&t2)ans-=dis(t1,t2);
			if(t1)ans+=dis(t1,tem);
			if(t2)ans+=dis(t2,tem);
		}
		else if(ch=='-'){
			scanf("%d",&tem);
			tem=dfn[tem];
			exi.erase(tem);
			auto x=exi.upper_bound(tem);
			int t1=0,t2=0;
			if(x!=exi.end())t2=*x;
			if(x!=exi.begin())t1=*(--x);
			if(t1&&t2)ans+=dis(t1,t2);
			if(t1)ans-=dis(t1,tem);
			if(t2)ans-=dis(t2,tem);
		}
		else{
			if(exi.empty())puts("0");
			else printf("%I64d\n",(ans+dis(*exi.begin(),*exi.rbegin()))>>1);
		}
	}
}