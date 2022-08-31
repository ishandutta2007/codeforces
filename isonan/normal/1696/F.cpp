#include <cstdio>
#include <vector>

int t,n;
int u[1000001],v[1000001],cnt,map[101][101];
int f[1000001],g[1000001];
char str[1001];
std::vector<std::pair<int,int> >chck;
std::vector<int>care[1001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return;
	f[u]=v;
	g[v]+=g[u];
}
int head[1001],nxt[2001],b[2001],k;
int dis[1001][1001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool vvis[1001][1001];
void getdis(int x,int f,int p,int d=0){
	if(vvis[p][x])return;
	vvis[p][x]=1;
	dis[p][x]=d;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getdis(b[i],x,p,d+1);
		}
}
bool vis[101];
bool check(int x){
	k=0;
	for(int i=0;i<=n;++i)head[i]=vis[i]=0;
	for(int i=1;i<=cnt;++i)
		if(find(i)==x)push(u[i],v[i]),push(v[i],u[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			vvis[i][j]=0;
	for(int i=1;i<=n;++i)getdis(i,0,i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(!vvis[i][j])return 0;
	// for(int i=1;i<=n;++i,putchar('\n'))
	// 	for(int j=1;j<=n;++j)
	// 		printf("%d ",dis[i][j]);
	for(int i=1;i<=cnt;++i)
		if(dis[u[i]][v[i]]!=dis[u[find(i)]][v[find(i)]])
			return 0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<n;++j)vis[j]=0;
		for(int v:care[i]){
			// printf("%d care %d\n",i,v);
			if(vis[dis[i][v]])return 0;
			vis[dis[i][v]]=1;
		}
	}
	return 1;
}
int tag[1000001];
int now;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j){
				++cnt;
				u[cnt]=i;
				v[cnt]=j;
				f[cnt]=0;
				g[cnt]=1;
				map[i][j]=map[j][i]=cnt;
			}
		chck.clear();
		for(int i=2;i<=n;++i)merge(map[1][1],map[i][i]);
		for(int i=1;i<=n;++i)
			for(int j=1;i+j<=n;++j){
				scanf("%s",str+1);
				for(int k=1;k<=n;++k)
					if(str[k]=='1')merge(map[i][k],map[i+j][k]);
					else chck.push_back(std::make_pair(map[i][k],map[i+j][k]));
			}
		bool bad=0;
		for(auto v:chck){
			if(find(v.first)==find(v.second))bad=1;
		}
		for(int i=1;i<=n;++i){
			++now;
			care[i].clear();
			for(int j=1;j<=n;++j)
				if(tag[find(map[i][j])]!=now){
					// printf("%d %d %d\n",i,j,find(map[i][j]));
					care[i].push_back(j);
					tag[find(map[i][j])]=now;
				}
			// for(int v:care[i])printf("%d ",v);putchar('\n');
		}
		if(g[find(map[1][1])]!=n)bad=1;
		if(bad){
			puts("No");
			continue;
		}
		// for(int i=1;i<=cnt;++i)
		// 	if(!f[i]){
		// 		printf("(%d %d)",u[i],v[i]);
		// 		for(int j=1;j<=cnt;++j)
		// 			if(f[j]&&find(j)==i)printf("(%d %d)",u[j],v[j]);putchar('\n');
		// 	}
		bool bb=0;
		for(int i=1;i<=cnt;++i)
			if(!f[i]&&g[i]==n-1){
				if(check(i)){
					puts("Yes");
					bb=1;
					for(int j=1;j<=cnt;++j)
						if(find(j)==i)printf("%d %d\n",u[j],v[j]);
					break;
				}
			}
		if(!bb)puts("No");
	}
}