#include <cstdio>
#include <queue>

std::queue<int>q[3];
int t,n,a[200001],head[200001],nxt[400001],b[400001],k,d[200001];
bool vis[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),head[i]=0,a[i]=(a[i]==0)?2:(a[i]-1);
		k=0;
		for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
		int fin=0x7f7f7f7f;
		for(int fd=0;fd<2;fd++){
			for(int i=1;i<=n;i++)vis[i]=d[i]=0;
			for(int i=1;i<=n;i++)
				for(int j=head[i];j;j=nxt[j])
					++d[i];
			for(int i=1;i<=n;i++)if(d[i]<=1)q[a[i]].push(i);
			int ans=0;
			for(int now=fd;!q[0].empty()||!q[1].empty()||!q[2].empty();now^=1){
				++ans;
				for(;;){
					int p=-1;
					if(!q[now].empty())p=q[now].front(),q[now].pop();
					else if(!q[2].empty())p=q[2].front(),q[2].pop();
					else break;
					if(vis[p])continue;
					vis[p]=1;
					for(int i=head[p];i;i=nxt[i])
						if(!vis[b[i]])
							if((--d[b[i]])<=1)q[a[b[i]]].push(b[i]);
				}
			}
			if(fin>ans)fin=ans;
		}
		printf("%d\n",fin);
	}
}