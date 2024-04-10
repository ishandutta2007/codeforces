#include<cstdio>
#include<cmath>
#define lowbit(a) a&(-a)
using namespace std;
int x,k;
double p,f[210][210];
int main(){
	scanf("%d%d%lf",&x,&k,&p); p/=100;
	for (int i=0;i<=k;i++) f[0][i]=log2(lowbit((x+i)));
	for (int i=0;i<k;i++)
		for (int j=0;j<=k;j++){
			if (j) f[i+1][j-1]+=(1-p)*f[i][j];
			if (j*2<=k) f[i+1][j*2]+=p*(f[i][j]+1);
		}
	printf("%.8lf\n",f[k][0]);
	return 0;
}