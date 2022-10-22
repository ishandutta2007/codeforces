#include<cstdio>
#include<algorithm>
using namespace std;
int n,l[110],r[110];
double dp[110][110],ans[110][110],now[110],lst[110];
int a[210],b[210];
int main(){
	scanf("%d",&n); int cnt=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		a[++cnt]=l[i]; a[++cnt]=r[i];
	}
	sort(a+1,a+cnt+1); cnt=unique(a+1,a+cnt+1)-a-1;
	for (int t=1;t<cnt;t++){
		for (int i=1;i<=n;i++){
			double L=a[t],R=a[t+1];
			if (!(l[i]>=R||r[i]<=L)){
				for (int j=0;j<=n;j++)
					for (int k=0;k<=n;k++)
						dp[j][k]=0;
				dp[0][0]=1;
				int tot=0,tot2=0;
				for (int k=1;k<=n;k++)
					if (l[k]>=R||r[k]<=L){
						now[k]=0;
						if (r[k]<=L) tot2++;
					} else now[k]=(R-L)/(r[k]-l[k]),b[tot++]=k;
				for (int k=0;k<tot;k++){
					int u=b[k];
					if (u==i) continue;
					for (int x=k+1;x>=0;x--)
						for (int y=k+1-x;y>=0;y--){
							dp[x+1][y]+=dp[x][y]*lst[u];
							dp[x][y+1]+=dp[x][y]*now[u];
							dp[x][y]*=1.0-now[u]-lst[u];
						}
				}
				for (int k=0;k<tot;k++)
					for (int x=0;x<tot-k;x++){
						ans[i][tot2+k]+=dp[k][x]*now[i]/(1+x);
						ans[i][tot2+k+x+1]-=dp[k][x]*now[i]/(1+x);
					}
			}
		}
		for (int i=1;i<=n;i++) lst[i]+=now[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<n;j++){
			if (j) ans[i][j]+=ans[i][j-1],putchar(' ');
			printf("%.12lf",ans[i][j]);
		}
		putchar('\n');
	}
	return 0;
}