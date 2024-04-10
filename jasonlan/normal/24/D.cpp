#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=1010;
int n,m,x,y;
double f[maxn][maxn],g[maxn][maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void Gauss(){
	for(register int i=1;i<m;++i){
		double d=f[i+1][i]/f[i][i];
		f[i+1][i+1]-=f[i][i+1]*d;f[i+1][0]-=f[i][0]*d;
	}
	f[m][0]/=f[m][m];
	for(register int i=m-1;i;--i)
		f[i][0]=(f[i][0]-f[i][i+1]*f[i+1][0])/f[i][i];
}
int main()
{
	n=read();m=read();x=read();y=read();
	if(m==1){
		for(register int i=n-1;i;--i)
			g[i][1]=g[i+1][1]+2;
	}
	else{
		for(register int i=n-1;i>=x;--i){
			f[1][1]=2.0/3.0;f[1][2]=-1.0/3.0;f[1][0]=g[i+1][1]/3+1;
			for(register int j=2;j<m;++j){
				f[j][j-1]=f[j][j+1]=-0.25;f[j][j]=0.75;f[j][0]=g[i+1][j]/4+1;
			}
			f[m][m]=2.0/3.0;f[m][m-1]=-1.0/3.0;f[m][0]=g[i+1][m]/3+1;
			Gauss();
			for(register int j=1;j<=m;++j)
				g[i][j]=f[j][0];
		}
	}
	printf("%.9lf",g[x][y]);
	return 0;
}