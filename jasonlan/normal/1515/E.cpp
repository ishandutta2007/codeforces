#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=410;
int n,mod;
int f[maxn][maxn],C[maxn][maxn],mi[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int qmod(int x){
	return x>=mod?x-mod:x;
}
int main(){
	n=read();mod=read();
	mi[0]=1;
	for(int i=1;i<=n;++i)
		mi[i]=qmod(mi[i-1]<<1);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=qmod(C[i-1][j-1]+C[i-1][j]);
	}
	for(int i=1;i<=n;++i){
		f[i][i]=mi[i-1];
		for(int j=0;j<=i;++j){
			for(int k=1;k+i+1<=n;++k){
				f[i+1+k][k+j]=qmod(f[i+1+k][k+j]+1ll*f[i][j]*mi[k-1]%mod*C[k+j][k]%mod);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)
		ans=qmod(ans+f[n][i]);
	printf("%d\n",ans);
	return 0;
}