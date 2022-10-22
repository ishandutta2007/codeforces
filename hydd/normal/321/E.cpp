#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long ll;
int n,k,sum[4100][4100];
ll f[810][4100];
ll w(int x,int y){
	return sum[y][y]-sum[y][x-1]-sum[x-1][y]+sum[x-1][x-1];
}
void solve(int now,int l,int r,int x,int y){
	if (l>r) return;
	int mid=(l+r)>>1,fr=x;
	for (int i=x;i<mid&&i<=y;i++)
		if (f[now-1][i]+w(i+1,mid)<f[now][mid]){
			f[now][mid]=f[now-1][i]+w(i+1,mid);
			fr=i;
		}
	solve(now,l,mid-1,x,fr); solve(now,mid+1,r,fr,y);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			scanf("%d",&sum[i][j]);
			sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
		}
	memset(f,0x3f,sizeof(f)); f[0][0]=0;
	for (int i=1;i<=k;i++){
		solve(i,1,n,0,n);
	}
	printf("%lld\n",f[k][n]/2);
	return 0;
}