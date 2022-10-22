#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=500;
const int Maxk=10;
int n,m,k;
int val[Maxn+5][Maxn+5][Maxk+5];
int r_val[Maxn+5][Maxn+5],d_val[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("-1%c"," \n"[j==m]);
			}
		}
		return 0;
	}
	k>>=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&r_val[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&d_val[i][j]);
		}
	}
	memset(val,0x3f,sizeof val);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			val[i][j][0]=0;
		}
	}
	for(int t=1;t<=k;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i<n){
					val[i][j][t]=std::min(val[i][j][t],d_val[i][j]+val[i+1][j][t-1]);
				}
				if(j<m){
					val[i][j][t]=std::min(val[i][j][t],r_val[i][j]+val[i][j+1][t-1]);
				}
				if(i>1){
					val[i][j][t]=std::min(val[i][j][t],d_val[i-1][j]+val[i-1][j][t-1]);
				}
				if(j>1){
					val[i][j][t]=std::min(val[i][j][t],r_val[i][j-1]+val[i][j-1][t-1]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d%c",(val[i][j][k]<<1)," \n"[j==m]);
		}
	}
	return 0;
}