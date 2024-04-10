#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn];
double f[maxn][maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)f[i][j]=(a[i]>a[j]);
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();b=read();
		for(int j=1;j<=n;j++){
			if(j==a||j==b)continue;
			double p=f[a][j]*0.5+f[b][j]*0.5;
			f[a][j]=f[b][j]=p;
			f[j][a]=f[j][b]=1-p;
		}
		f[a][b]=f[b][a]=0.5;
	}
	double sum=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)sum+=f[i][j];
	printf("%.9f\n",sum);
	return 0;
}