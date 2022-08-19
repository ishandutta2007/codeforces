#include <cstdio>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int mat[2010][2010],f1[2010][2010],g1[2010][2010],f[2010][2010],g[2010][2010],pon[2010],n,m;
int get(){
	char ch=getchar();
	while(ch!='.'&&ch!='R')ch=getchar();
	return ch=='R';
}
int main(){
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mat[i][j]=get();
	f[1][1]=g[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j;--j)
			f1[i][j]=f1[i][j+1]+mat[i][j];
	for(int j=1;j<=m;j++)
		for(int i=n;i;i--)
			g1[i][j]=g1[i+1][j]+mat[i][j];
	for(int i=1;i<=m;i++)pon[i]=1;
	for(int i=1;i<=n;i++){
		int now=1;
		for(int j=1;j<=m;j++){
			while(g1[pon[j]+1][j]>n-i)++pon[j];
			if(i>1)g[i][j]=sub(f[i-1][j],f[pon[j]-1][j]);
		}
		for(int j=1;j<=m;j++)g[i][j]=add(g[i][j],g[i][j-1]);
		for(int j=1;j<=m;j++){
			while(f1[i][now+1]>m-j)++now;
			if(j>1)f[i][j]=sub(g[i][j-1],g[i][now-1]);
		}
		for(int j=1;j<=m;j++)f[i][j]=add(f[i][j],f[i-1][j]);
	}
	printf("%d",add(sub(f[n][m],f[n-1][m]),sub(g[n][m],g[n][m-1])));
}