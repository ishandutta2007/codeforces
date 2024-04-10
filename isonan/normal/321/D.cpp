#include <cstdio>
#include <algorithm>

int map[101][101],n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	int x=(n+1)>>1;
	long long ans=-1e18;
	for(int i=0;i<(1<<x);i++){
		long long tem=0;
		for(int j=0;j<x;j++){
			tem+=((i&(1<<j))?-1:1)*(map[x-1][j]);
			if(j!=x-1)tem+=((((i&(1<<j))!=0)==((i&(1<<(x-1)))!=0))?1:-1)*(map[x-1][j+x]);
		}
		for(int j=0;j<x-1;j++){
			long long v=-1e18;
			for(int bit=0;bit<2;bit++){
				long long ttem=0;
				ttem+=(bit?-1:1)*map[j][x-1];
				ttem+=((bit^((i&(1<<(x-1)))!=0))?-1:1)*map[j+x][x-1];
				for(int k=0;k<x-1;k++){
					long long vv=-1e18;
					for(int b=0;b<2;b++){
						long long u=0;
						u+=(b?-1:1)*map[j][k];
						u+=(b==bit?1:-1)*map[j][k+x];
						u+=(b==((i&(1<<k))!=0)?1:-1)*map[j+x][k];
						u+=((b^bit^((i&(1<<k))!=0)^((i&(1<<(x-1)))!=0))?-1:1)*map[j+x][k+x];
						vv=std::max(vv,u);
					}
					ttem+=vv;
				}
				v=std::max(v,ttem);
			}
			tem+=v;
		}
		ans=std::max(ans,tem);
	}
	printf("%lld\n",ans);
}