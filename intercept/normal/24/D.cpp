#include<bits/stdc++.h>
using namespace std;
const int M=1009;
int n,m,x,y;
double a[M],b[M],f[M][M];
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(m==1){
		for(int i=n-1;i>=x;--i){
			f[i][1]=f[i+1][1]+2.0;
		}
		printf("%.8lf",f[x][1]);
		return 0;
	}
	for(int i=n-1;i>=x;--i){
		a[1]=0.5;b[1]=0.5*f[i+1][1]+1.5;
		for(int j=2;j<m;++j){
			double x=0.75-a[j-1]/4;
			a[j]=0.25/x;
			b[j]=(0.25*(b[j-1]+f[i+1][j])+1)/x;
		}
		f[i][m]=(f[i+1][m]+b[m-1]+3.0)/(2.0-a[m-1]);
		for(int j=m-1;j>=1;--j)f[i][j]=f[i][j+1]*a[j]+b[j];
	}
	printf("%.8lf",f[x][y]);
	return 0;
}