#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int n,m;
bool vis[1001][1001];
struct point{
	int u,v,w;
}num[500001];
bool cmp(point a,point b){
	return a.w<b.w;
}
int f[2000001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int head[2000001],nxt[4000001],b[4000001],k;
int g[2000001];
int stk[2000001],top;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool Vis[2000001];
int main(){
	scanf("%d%d",&n,&m);
	int Sum=0;
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		num[i]=(point){u,v,w};
		Sum^=w;
	}
	if((1ll*(1ll*n*(n-1))/2ll)-1ll*m<=1ll*n-1ll){
//		putchar('*');
//		if(n>1000){
//			for(;;);
//		}
		for(int i=1;i<=m;++i)vis[num[i].u][num[i].v]=vis[num[i].v][num[i].u]=1;
		int top=m;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(!vis[i][j])num[++top]=(point){i,j,0};
		num[++top]=(point){-1,-1,Sum};
		std::sort(num+1,num+top+1,cmp);
		long long ans=1e18;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(!vis[i][j]){
					long long tem=0;
					for(int k=1;k<=n;++k)f[k]=0;
					for(int l=1;l<=top;++l){
						int u=num[l].u,v=num[l].v;
						if(u==i&&v==j)continue;
						if(!~u){
							if(find(i)!=find(j)){
								f[find(i)]=find(j);
								tem+=num[l].w;
							}
						}
						else{
							if(find(u)!=find(v)){
								f[find(u)]=find(v);
								tem+=num[l].w;
							}
						}
					}
//					printf("%d %d %lld\n",i,j,tem);
					ans=std::min(ans,tem);
				}
		printf("%lld\n",ans);
	}
	else{
		for(int i=1;i<=n;++i)f[i]=0,g[i]=1,stk[++top]=i;
		for(int i=1;i<=m;++i)push(num[i].u,num[i].v),push(num[i].v,num[i].u);
		for(int i=1;i<=n;++i){
			for(int j=head[i];j;j=nxt[j])
				if(find(b[j])!=find(i)){
					--g[find(b[j])];
					if(g[find(b[j])]==0)Vis[find(b[j])]=1;
				}
			for(int j=head[i];j;j=nxt[j])
				if(find(b[j])!=find(i)){
					++g[find(b[j])];
				}
			for(int j=1;j<=top;++j){
				int w=find(stk[j]);
				if(!Vis[w]&&w!=find(i)){
					f[w]=find(i);
					g[find(i)]+=g[w];
					stk[j]=stk[top];
					--top;
					--j;
				}
			}
			for(int j=1;j<=top;++j)Vis[stk[j]]=0;
		}
		std::sort(num+1,num+m+1,cmp);
		long long ans=0;
		for(int i=1;i<=m;++i){
			int u=find(num[i].u),v=find(num[i].v);
			if(u!=v)ans+=num[i].w,f[u]=v;
		}
		printf("%lld\n",ans);
	}
}