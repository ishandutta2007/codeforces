#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=310,INF=0x3f3f3f3f;
int n;
int f[maxn<<1][maxn][maxn],a[maxn][maxn]; 
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=n;++j)
			a[i][j]=read();
	for(register int i=2;i<=n<<1;++i)
		for(register int j=1;j<=n;++j)
			for(register int k=1;k<=n;++k)
				f[i][j][k]=-INF;
	f[2][1][1]=a[1][1]*2;
	for(register int i=2;i<=n<<1;++i)
		for(register int j=1;j<=n&&j<i;++j)
			for(register int k=1;k<=n&&k<i;++k){
				if(j==k)f[i][j][k]-=a[j][i-j];
				if(j+1<=n&&k+1<=n)
					f[i+1][j+1][k+1]=max(f[i+1][j+1][k+1],f[i][j][k]+a[j+1][i-j]+a[k+1][i-k]);
				if(j+1<=n&&i-k+1<=n)
					f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[j+1][i-j]+a[k][i+1-k]);
				if(i-j+1<=n&&k+1<=n)
					f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[j][i+1-j]+a[k+1][i-k]);
				if(i-j+1<=n&&i-k+1<=n)
					f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[j][i+1-j]+a[k][i+1-k]);
			}
	printf("%d",f[n<<1][n][n]);
    return 0;
}