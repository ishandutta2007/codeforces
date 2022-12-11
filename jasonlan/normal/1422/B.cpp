#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=110;
int n,m;
long long ans,sum,a[maxn][maxn],d[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();m=read();
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=m;++j)
				a[i][j]=read();
		ans=0;
		for(register int i=1;i<=n-i+1;++i)
			for(register int j=1;j<=m-j+1;++j){
				if(i==n-i+1&&j==m-j+1);//Central
				else if(i==n-i+1)ans+=abs(a[i][j]-a[i][m-j+1]);
				else if(j==m-j+1)ans+=abs(a[i][j]-a[n-i+1][j]);
				else{
					d[0]=a[i][j];d[1]=a[i][m-j+1];d[2]=a[n-i+1][j];d[3]=a[n-i+1][m-j+1];
					sort(d,d+4);
					ans+=d[3]+d[2]-d[0]-d[1];
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}