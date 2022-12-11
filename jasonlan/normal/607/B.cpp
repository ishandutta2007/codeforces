#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=510,INF=0x3f3f3f3f;
int n,a[maxn];
int f[maxn][maxn];
inline int read();
int main()
{
	n=read();
	for(register int i=0;i<n;++i)a[i]=read(),f[i][i]=1;
	for(register int i=0;i<n-1;++i)f[i][i+1]=(a[i]==a[i+1] ? 1 : 2 );
	for(register int i=2;i<n;++i)
		for(register int j=0;j<n-i+1;++j){
			if(a[j]==a[j+i])f[j][i+j]=f[j+1][i+j-1];
			else f[j][i+j]=INF;
			for(register int k=0;k<i;++k)
				f[j][i+j]=min(f[j][i+j],f[j][j+k]+f[j+k+1][j+i]);
		}
	printf("%d",f[0][n-1]);
	return 0;
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}