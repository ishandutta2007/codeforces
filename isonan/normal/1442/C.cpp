#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

int n,m;
int head[200001],nxt[400001],b[400001],k=1;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int dis1[2][200001],dis[2][19][200001];
bool vis[2][200001],vis2[2][19][200001];
std::priority_queue<std::pair<int,int> >heap;
std::queue<std::pair<int,int> >q;
struct ans{
	long long k,p;
};
bool operator<=(ans a,ans b){
	bool rev=0;
	if(a.k==b.k)return a.p<b.p;
	if(a.k<b.k){
		ans t=a;
		a=b;
		b=t;
		rev=1;
	}
	if(b.p<a.p)return rev;
	long long v=(b.p-a.p)/((1ll<<a.k)-(1ll<<b.k)),Log=0;
	while((1ll<<Log)<=v)++Log;
	--Log;
	return (Log>=dis1[0][n])^(rev);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	memset(dis1,0x7f7f7f7f,sizeof dis1);
	dis1[0][1]=0;
	heap.push(std::make_pair(0,1));
	while(!heap.empty()){
		std::pair<int,int>now=heap.top();
		heap.pop();
		int bit=(now.second>n),p=now.second-bit*(n+1);
		if(vis[bit][p])continue;
		vis[bit][p]=1;
		for(int i=head[p];i;i=nxt[i])
			if(dis1[i&1][b[i]]>dis1[bit][p]+(bit!=(i&1))){
				dis1[i&1][b[i]]=dis1[bit][p]+(bit!=(i&1));
				heap.push(std::make_pair(-dis1[i&1][b[i]],(i&1)*(n+1)+b[i]));
			}
	}
	for(int i=1;i<=n;i++)dis1[0][i]=std::min(dis1[0][i],dis1[1][i]);
//	for(int i=1;i<=n;i++)printf("%d ",dis1[0][i]);putchar('\n');
	memset(dis,0x7f7f7f7f,sizeof dis);
	dis[0][0][1]=0;
	q.push(std::make_pair(0,1));
	while(!q.empty()){
		std::pair<int,int>now=q.front();
		q.pop();
		int stat=(now.second)/(n<<1|1);
		now.second-=stat*(n<<1|1);
		int bit=(now.second>n),p=now.second-bit*(n+1);
		for(int i=head[p];i;i=nxt[i]){
			int ne=stat+dis1[0][p]-dis1[0][b[i]]+(bit!=(i&1));
			if(ne<=18&&dis[i&1][ne][b[i]]>dis[bit][stat][p]+1){
				dis[i&1][ne][b[i]]=dis[bit][stat][p]+1;
				q.push(std::make_pair(-dis[i&1][ne][b[i]],ne*(n<<1|1)+(i&1)*(n+1)+b[i]));
			}
		}
	}
	ans fin=(ans){20ll,0x7f7f7f7fll};
	for(int i=0;i<2;i++)
		for(int j=0;j<19;j++){
//			printf("%d\n",dis[i][j][n]);
			if((ans){j,dis[i][j][n]-1}<=fin)fin=(ans){j,dis[i][j][n]-1};
		}
//	printf("%d\n",dis1[0][n]);
	int tem=1;
	for(int i=1;i<=dis1[0][n]+fin.k;i++)tem=1ll*tem*2%998244353;
	printf("%d\n",(tem+(fin.p+998244353)%998244353)%998244353);
}