#include <cstdio>
#include <queue>

int t,n,c[501][501];
long long dis[501][501];
bool vis[501][501];
std::priority_queue<std::pair<long long,int> >heap;
int nxt(int x){
	if(x==n*2)return 1;
	return x+1;
}
int pre(int x){
	if(x==1)return 2*n;
	return x-1;
}
void check(int x,int y,long long v){
	v+=c[x][y];
	if(v<dis[x][y])dis[x][y]=v,heap.push(std::make_pair(-dis[x][y],((x-1)*2*n+y)));
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);++i)
			for(int j=1;j<=(n<<1);++j)
				scanf("%d",&c[i][j]),vis[i][j]=0;
		long long ans=0,ans2=1e18;
		for(int i=n+1;i<=(n<<1);++i)
			for(int j=n+1;j<=(n<<1);++j)
				ans+=c[i][j],c[i][j]=0;
		for(int i=1;i<=(n<<1);++i)
			for(int j=1;j<=(n<<1);++j){
				dis[i][j]=(i<=n&&j<=n)?0:1e18;
				if(i<=n&&j<=n){
					if((i==n||i==1)&&(j==n||j==1))
						heap.push(std::make_pair(0,((i-1)*(2*n)+j)));
				}
			}
		while(!heap.empty()){
			int v=heap.top().second;
			heap.pop();
			int x,y;
			y=(v%(2*n)==0)?2*n:(v%(2*n));
			x=(v-y)/(2*n)+1;
			if(vis[x][y])continue;
			if(x>n&&y>n)continue;
			vis[x][y]=1;
			check(pre(x),y,dis[x][y]);
			check(nxt(x),y,dis[x][y]);
			check(x,pre(y),dis[x][y]);
			check(x,nxt(y),dis[x][y]);
		}
		for(int i=n+1;i<=(n<<1);++i)
			for(int j=n+1;j<=(n<<1);++j)
				if((i==n+1||i==2*n)&&(j==n+1||j==2*n))
					ans2=std::min(ans2,dis[i][j]);
		printf("%lld\n",ans+ans2);
	}
}