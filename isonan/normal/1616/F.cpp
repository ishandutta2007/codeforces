#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>

const int P=3;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int t,n,m;
int edg[101][101],c[256],cnt;
int map[10001][301];
bool vis[301];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		memset(edg,0,sizeof edg);
		cnt=0;
		for(int i=1,u,v;i<=m;++i){
			scanf("%d%d%d",&u,&v,c+i);
			c[i]%=3;
			if(u>v)std::swap(u,v);
			edg[u][v]=i;
		}
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					if(edg[i][j]&&edg[j][k]&&edg[i][k]){
						++cnt;
						memset(map[cnt],0,sizeof map[cnt]);
						int x=edg[i][j];
						if(c[x]==-1)map[cnt][x]=1;else map[cnt][m+1]=sub(map[cnt][m+1],c[x]);
						x=edg[j][k];
						if(c[x]==-1)map[cnt][x]=1;else map[cnt][m+1]=sub(map[cnt][m+1],c[x]);
						x=edg[i][k];
						if(c[x]==-1)map[cnt][x]=1;else map[cnt][m+1]=sub(map[cnt][m+1],c[x]);
					}
		int i=1,p=1;
		for(;p<=m&&i<=cnt;){
			for(int j=i;j<=cnt;++j)
				if(map[j][p]){
					std::swap(map[i],map[j]);
					break;
				}
			if(!map[i][p]){
				++p;
				continue;
			}
			if(map[i][p]==2){
				for(int k=1;k<=m+1;++k)map[i][k]=sub(0,map[i][k]);
			}
			for(int j=i+1;j<=cnt;++j)
				if(map[j][p]){
					bool bb=(map[j][p]==1);
					for(int k=1;k<=m+1;++k)map[j][k]=(bb?sub:add)(map[j][k],map[i][k]);
				}
			++p;
			++i;
		}
		// for(int i=1;i<=cnt;++i,putchar('\n'))
		// 	for(int j=1;j<=m+1;++j)
		// 		printf("%d ",map[i][j]);
		bool ans=0;
		for(int j=i;j<=cnt;++j)
			if(map[j][m+1]){
				puts("-1");
				ans=1;
				break;
			}
		if(ans)continue;
		for(int j=i-1;j;--j){
			int p=0;
			for(int k=1;k<=m;++k)
				if(map[j][k]){
					if(p){
						c[k]=0;
						for(int l=1;l<=cnt;++l)map[l][k]=0;
						continue;
					}
					p=k;
				}
			c[p]=map[j][m+1];
			for(int l=j-1;l;--l)
				if(map[l][p]){
					bool bb=(map[l][p]==1);
					for(int k=1;k<=m+1;++k)map[l][k]=(bb?sub:add)(map[l][k],map[j][k]);
				}
		}
		for(int i=1;i<=m;++i)printf("%d ",c[i]+3*(c[i]==0)+2*(c[i]==-1));putchar('\n');
	}
}