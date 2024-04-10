#include <cstdio>
#include <cstdlib>
#include <algorithm>

int n,m,head[100001],nxt[200001],b[200001],k,t,T,l[200001],r[100001],n1,n2=0x7f7f7f7f,type[100001];
int col[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int c){
	if(!(type[x]&c)||col[x]==(3-c)){
		puts("IMPOSSIBLE");
		exit(0);
	}
	if(col[x])return;
	col[x]=c;
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i],3-c);
}
int main(){
	scanf("%d%d%d%d",&t,&T,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i),n1=std::max(n1,l[i]),n2=std::min(n2,r[i]);
	if(n1+n2<t)n1=t-n2;
	if(n1+n2>T)n2=T-n1;
	if(n1<0||n2<0){puts("IMPOSSIBLE");return 0;}
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	for(int i=1;i<=n;i++){
		type[i]=(l[i]<=n1&&n1<=r[i])+(l[i]<=n2&&n2<=r[i])*2;
		if(!type[i]){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(type[i]!=3&&!col[i])dfs(i,type[i]);
	for(int i=1;i<=n;i++)
		if(!col[i])dfs(i,1);
	puts("POSSIBLE");
	printf("%d %d\n",n1,n2);
	for(int i=1;i<=n;i++)printf("%d",col[i]);
}