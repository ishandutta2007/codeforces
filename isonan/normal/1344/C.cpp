#include <cstdio>
#include <algorithm>
#include <queue>

std::queue<int>q;
int n,m,head[200001],nxt[200001],b[200001],k,con[2][200001],V[200001],d[200001];
bool cando[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&con[0][i],&con[1][i]);
	for(int fd=0;fd<2;fd++){
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)head[i]=0,d[i]=0,V[i]=i;
		k=0;
		for(int i=1;i<=m;i++)push(con[fd][i],con[fd^1][i]),++d[con[fd^1][i]];
		for(int i=1;i<=n;i++)if(!d[i])q.push(i);
		int tot=0;
		while(!q.empty()){
			++tot;
			int now=q.front();
			q.pop();
			for(int i=head[now];i;i=nxt[i]){
				if(b[i]>V[now])cando[b[i]]=1;
				V[b[i]]=std::min(V[b[i]],V[now]);
				if(!(--d[b[i]]))q.push(b[i]);
			}
		}
		if(tot<n){
			puts("-1");
			return 0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(!cando[i])++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)putchar(cando[i]?'E':'A');
}