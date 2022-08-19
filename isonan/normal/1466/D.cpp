#include <cstdio>
#include <queue>
#include <algorithm>

int f[100001],t;
int head[100001],nxt[200001],b[200001],k,d[100001];
long long ans[100001];
long long w[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",w+i),d[i]=0;
		k=0;
		for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),++d[u],++d[v];
		long long ans=0;
		for(int i=1;i<=n;i++)ans+=((1ll*w[i]*d[i]));
		std::priority_queue<int>heap;
		for(int i=1;i<=n;i++)
			for(int j=1;j<d[i];j++)
				heap.push(-w[i]);
		for(int i=n-1;i;i--){
			::ans[i]=ans;
			if(i>1){
			ans+=heap.top();
			heap.pop();
			}
		}
		for(int i=1;i<=n-1;i++)printf("%lld ",::ans[i]);
		putchar('\n');
	}
}