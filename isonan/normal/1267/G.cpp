#include <cstdio>
#include <algorithm>

int n,x,c[101],sum,d[101];
double C[101][101];
double f[101][10001],ans;
int main(){
	scanf("%d%d",&n,&x);
	f[0][0]=1.;
	for(int i=1,tot;i<=n;i++){
		scanf("%d",c+i);
		for(int j=i-1;~j;--j)
			for(int k=0;k<=sum;k++)
				f[j+1][k+c[i]]+=f[j][k];
		sum+=c[i];
	}
	C[0][0]=1.0;
	for(int i=1;i<=n;i++){
		C[i][0]=1.0;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(int i=0;i<=n;i++)C[n][i]=1.0/C[n][i];
	for(int i=0;i<n;i++)
		for(int j=0;j<=sum;j++){
			ans+=f[i][j]*(C[n][i]*std::min((double)(sum-j)/(double)(n-i),(double)x*0.5*((((double)n)/(double)(n-i))+1.0)));
		}
	printf("%.9lf\n",ans);
}