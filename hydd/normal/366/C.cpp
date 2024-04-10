#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10000;
int n,k,a[110000],b[110000],f[110][31000];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]*=k;
	}
	for (int i=0;i<=n;i++)
		for (int j=-10000;j<=20000;j++)
			f[i][j+N]=-1;
	f[0][N]=0;
	for (int i=0;i<n;i++)
		for (int j=-10000;j<=20000;j++)
			if (f[i][j+N]!=-1){
				f[i+1][j+N]=max(f[i+1][j+N],f[i][j+N]);
				f[i+1][j+a[i+1]-b[i+1]+N]=max(f[i+1][j+a[i+1]-b[i+1]+N],f[i][j+N]+a[i+1]);
			}
	if (f[n][N]) printf("%d\n",f[n][N]);
	else puts("-1");
	return 0;
}