#include <cstdio>

int head[300001],nxt[600001],b[600001],k,cnt,n,f[300001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int find(int x){
	if(!f[x])return x;
	return f[x]=find(f[x]);
}
void dfs(int x){
	if(x<=n)printf("%d ",x);
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]);
}
int main(){
	scanf("%d",&n);
	cnt=n;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		x=find(x);
		y=find(y);
		f[x]=f[y]=++cnt;
		push(cnt,x);
		push(cnt,y);
	}
	dfs(cnt);
}