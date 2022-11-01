#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=505;
int n,m,k,a[N][N],b[N][N],dis[N][N],ans[N][N];
int work(int x,int y){
	dis[x][y]=0;
	for(int u=1;u<=k/2;u++){
		for(int i=std::max(1,x-u),ie=std::min(n,x+u);i<=ie;i++){
			int v=u-std::abs(x-i);
			for(int j=y-v,je=std::min(m,y+v);j<=je;j+=2) if(j>=1){
				int td=1e9;
				td=std::min(td,dis[i-1][j]+b[i-1][j]);
				td=std::min(td,dis[i+1][j]+b[i][j]);
				td=std::min(td,dis[i][j-1]+a[i][j-1]);
				td=std::min(td,dis[i][j+1]+a[i][j]);
				dis[i][j]=td;
			}
		}
	}
	int res=1e9;
	for(int i=std::max(1,x-k/2),ie=std::min(n,x+k/2);i<=ie;i++){
		int v=k/2-std::abs(x-i);
		for(int j=y-v,je=std::min(m,y+v);j<=je;j+=2) if(j>=1){
			res=std::min(res,dis[i][j]);
		}
	}
	for(int i=std::max(1,x-k/2),ie=std::min(n,x+k/2);i<=ie;i++){
		int v=k/2-std::abs(x-i);
		for(int j=std::max(1,y-v),je=std::min(m,y+v);j<=je;j++){
			dis[i][j]=0x1f1f1f1f;
		}
	}
	return res*2;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k%2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("-1 ");
			puts("");
		}
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m-1;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n-1;i++) for(int j=1;j<=m;j++)scanf("%d",&b[i][j]);
	memset(dis,0x1f,sizeof(dis));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)ans[i][j]=work(i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%d ",ans[i][j]);
		puts("");
	}
}