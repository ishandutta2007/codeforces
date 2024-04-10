#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using std::max;

int head[2001],nxt[2000001],b[2000001],k,f[2001],comp[1001][1001],n,m,nodes,d[2001],q[2001],t,h,ans[2001],orig;
int get(){
	char ch=getchar();
	while(ch!='<'&&ch!='='&&ch!='>')ch=getchar();
	return (ch=='<')?(-1):((ch=='=')?0:1);
}
int find(int x){
	if(!f[x])return x;
	return f[x]=find(f[x]);
}
void unionn(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	f[x]=y;
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	++d[t];
}
bool vis[2001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			comp[i][j]=get();
			if(comp[i][j]==0)unionn(i,j+n);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(comp[i][j]){
				if(find(i)==find(j+n)){
					puts("No");
					return 0;
				}
//				printf("%d %d %d %d\n",i,j+n,find(i),find(j+n));
				if(comp[i][j]==-1)push(find(i),find(j+n));
				else push(find(j+n),find(i));
			}
	for(int i=1;i<=n+m;i++)if(!f[i]&&!d[i])q[++t]=i,ans[i]=1;
	while(h<t){
		++h;
		vis[q[h]]=1;
		for(int i=head[q[h]];i;i=nxt[i]){
			if(vis[b[i]]){
				puts("No");
				return 0;
			}
			ans[b[i]]=max(ans[b[i]],ans[q[h]]+1);
			if(!(--d[b[i]]))q[++t]=b[i];
		}
	}
	for(int i=1;i<=n+m;i++){
		if(!f[i]&&!vis[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d ",ans[find(i)]);putchar('\n');
	for(int i=1;i<=m;i++)printf("%d ",ans[find(i+n)]);putchar('\n');
}