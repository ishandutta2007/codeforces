#include <cstdio>
#include <algorithm>

int n,head[300010],nxt[600010],b[600010],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int cnt[2];
void dfs(int x,int f,int c){
	++cnt[c];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,c^1);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0,0);
	printf("%d\n",std::min(cnt[0],cnt[1])-1);
}