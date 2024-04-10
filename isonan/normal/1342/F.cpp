#include <cstdio>
#include <cassert>
#include <algorithm>

int T;
int f[32768][16][16],mn[32768][16];
int sum[32768],n,a[16];
bool vis[16];
int find(int x){
	int ans=0;
	for(int i=1;i<=x;++i)ans+=(!vis[i]);
	return ans;
}
void del(int i,int j){
	printf("%d %d\n",find(i),find(j));
	vis[i]=1;
}
int A[16],B[16];
bool cmp(int lhs,int rhs){
	return A[lhs]<A[rhs];
}
int main(){
	scanf("%d",&T);
	for(int i=0;i<(1<<15);++i)
		for(int j=0;j<=15;++j)
			for(int k=j+1;k<=15;++k)
				if(i&(1<<(k-1))){
					mn[i][j]=k;
					break;
				}
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<=n;++j)
				for(int k=0;k<=n;++k)
					f[i][j][k]=0x7f7f7f7f;
		f[0][0][0]=0;
		for(int i=0;i<(1<<n);++i)
			for(int j=1;j<=n;++j)
				if(!(i&(1<<(j-1))))sum[i|(1<<(j-1))]=sum[i]+a[j];
		for(int i=0;i<(1<<n);++i){
			int lim=__builtin_popcount(i);
			int x=((1<<n)-1)^i;
			for(int j=0;j<=n;++j){
				for(int k=0;k<=lim;++k)A[k]=f[i][j][k],B[k]=k;
				std::sort(B,B+lim+1,cmp);
				for(int k=0;k<=lim;++k)A[k]=f[i][j][B[k]];
				for(int s=x;s;s=(s-1)&x){
						if(mn[s][j]){
							int *b=f[i|s][mn[s][j]]+1,v=sum[s];
							for(int k=0;k<=lim;++k){
								if(v>A[k]){
									if(v<*(b+B[k]))*(b+B[k])=v;
								}
								else break;
							}
						}
				}
			}
		}
		int p1,p2,p3;
		// for(int i=0;i<(1<<n);++i)
		// 	for(int j=0;j<=n;++j)
		// 		for(int k=0;k<=n;++k)
		// 			printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
		for(int k=1;k<=n;++k)
			for(int j=1;j<=n;++j)
				if(f[(1<<n)-1][j][k]<0x7f7f7f7f)
					p1=(1<<n)-1,p2=j,p3=k;
		// printf("%d %d\n",n,p3);
		printf("%d\n",n-p3);
		for(;p1;){
			int x1=0,x2=0;
			for(int i=1;i<(1<<n);++i)
				if((i&p1)==i&&(i&(1<<(p2-1)))&&sum[i]==f[p1][p2][p3])
					for(int j=0;j<p2;++j)
						if(f[p1^i][j][p3-1]<sum[i])
							x1=i,x2=j;
			if(!x1&&!x2)return 0;
			for(int i=1;i<=n;++i)
				if((x1&(1<<(i-1)))&&i!=p2)del(i,p2);
			p1^=x1;
			p2=x2;
			--p3;
		}
	}
}