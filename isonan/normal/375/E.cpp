#include <cstdio>
#include <vector>

std::vector<int>f[501][501];
int best[510][510],head[510],nxt[1010],b[1010],k,size[510],col[510];
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
long long dis[510][510],n,DIS,cnt,v[1010];
void push(int s,int t,long long val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getdis(int x,int f,int pre,long long dist){
	dis[x][pre]=dist;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getdis(b[i],x,pre,dist+v[i]);
}
void dfs(int x,int F){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
//			printf("%d %hd\n",b[i],x);
			dfs(b[i],x);
			size[x]+=size[b[i]];
		}
	for(int i=1;i<=n;i++){
		f[x][i].resize(min(size[x],cnt)+1);
		for(int j=0;j<f[x][i].size();j++)f[x][i][j]=(n<<1)+1;
//		printf("%hd %hd %lld %lld\n",x,i,dis[x][i],DIS);
		if(dis[x][i]>DIS)continue;
//		printf("%hd %hd %lld %lld\n",x,i,dis[x][i],DIS);
		f[x][i][1]=col[i]==0;
		size[x]=1;
		for(int j=head[x];j;j=nxt[j])
			if(b[j]!=F){
				int tmp;
				for(int k=min(cnt,size[x]+size[b[j]]);~k;k--){
					tmp=(n<<1)+1;
					for(int l=max(k-size[x],0);l<=size[b[j]]&&l<=k;l++)
						tmp=min(tmp,f[x][i][k-l]+best[b[j]][l]);
					for(int l=max(k-size[x],0)+1;l<=size[b[j]]&&l<=k;l++)
						tmp=min(tmp,f[x][i][k-l+1]+f[b[j]][i][l]-(col[i]==0));
					f[x][i][k]=tmp;
				}
				size[x]+=size[b[j]];
				f[b[j]][i].clear();
			}
	}
	for(int i=0;i<=size[x]&&i<=cnt;i++){
		best[x][i]=(n<<1)+1;
		for(int j=1;j<=n;j++)
			best[x][i]=min(best[x][i],f[x][j][i]);
	}
}
signed main(){
	scanf("%I64d%I64d",&n,&DIS);
	for(int i=1;i<=n;i++){
		scanf("%d",col+i);
		cnt+=col[i];
	}
	int x,y;
	long long z;
	for(int i=1;i<n;i++){
		scanf("%d%d%I64d",&x,&y,&z);
		push(x,y,z);
		push(y,x,z);
	}
	for(int i=1;i<=n;i++)getdis(i,0,i,0);
	dfs(1,0);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			for(int k=0;k<=size[i]&&k<=cnt;k++)
//				if(f[i][j][k]!=(n<<1)+1)printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
	int getans=(n<<1)+1;
	for(int i=0;i<=cnt;i++)getans=min(getans,best[1][i]);
	printf("%d",getans==(n<<1)+1?-1:getans);
}