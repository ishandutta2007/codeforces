#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int n,m,S,T;
int head[2001],nxt[200001],b[200001],v[200001],k;
long long dis1[2001],dis2[2001];
int q[1000001],h,t,orig[2001],p[2001];
long long cnt[2001][2001];
long long sum[2001][2001],f[2001][2001],g[2001][2001];
int last1[2001],last2[2001];
bool inq[2001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getdis(int s,int *dis){
	for(int i=1;i<=n;i++)inq[i]=0,dis[i]=1e18;
	h=t=0;
	q[++t]=s;
	dis[s]=0;
	while(h<t){
		inq[q[++h]]=0;
		for(int i=head[q[h]];i;i=nxt[i])
			if(dis[b[i]]>dis[q[h]]+v[i]){
				dis[b[i]]=dis[q[h]]+v[i];
				if(!inq[b[i]])inq[b[i]]=1,q[++t]=b[i];
			}
	}
	for(int i=1;i<=n;i++)orig[i]=dis[i];
	std::sort(orig+1,orig+n+1);
	int lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)dis[i]=std::lower_bound(orig+1,orig+lim+1,dis[i])-orig;
}
long long rect(long long a[2001][2001],int x1,int x2,int y1,int y2){
	if(x1>x2||y1>y2)return 0ll;
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&S,&T);
	long long Sum=0;
	for(int i=1;i<=n;i++)scanf("%lld",p+i),Sum+=p[i];
	for(int i=1,u,v,val;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&val);
		push(u,v,val),push(v,u,val);
	}
	getdis(S,dis1);
	getdis(T,dis2);
//	for(int i=1;i<=n;i++)printf("%d %d\n",dis1[i],dis2[i]);
	for(int i=1;i<=n;i++)++cnt[dis1[i]][dis2[i]],sum[dis1[i]][dis2[i]]+=p[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt[i][j]+=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	for(int i=0;i<=n;i++)last1[i]=last2[i]=n;
	long long ans=-1e18;
	for(int i=n;~i;i--)
		for(int j=n;~j;j--){
				if(rect(cnt,i+1,n,j+1,n)){
					while(rect(cnt,i+1,last1[j]-1,j+1,n))--last1[j];
					f[i][j]=g[last1[j]][j]-rect(sum,0,i,j+1,n);
					while(rect(cnt,i+1,n,j+1,last2[i]-1))--last2[i];
					g[i][j]=f[i][last2[i]];
				}
				if(!i&&!j)ans=f[i][j];
//				printf("%d %d %d %d\n",i,j,f[i][j],g[i][j]);
				if(j<n)f[i][j]=std::min(f[i][j],f[i][j+1]);
				g[i][j]+=rect(sum,0,i,j+1,n);
				if(i<n)g[i][j]=std::max(g[i+1][j],g[i][j]);
			}
//	printf("%d %d\n",ans,Sum);
	if(ans<(Sum-ans))puts("Cry");
	else if(ans==(Sum-ans))puts("Flowers");
	else puts("Break a heart");
}