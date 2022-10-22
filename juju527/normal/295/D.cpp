#include<bits/stdc++.h>
using namespace std;
const int maxn=2005,maxm=2005,mod=1e9+7;
int f[maxn][maxm];
int s[maxn][maxm],sc[maxn][maxm];
int p[maxn][maxm];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
int main(){
	int n,m;
	n=read();m=read();
	for(int i=2;i<=m;i++){
		f[1][i]=1;
		s[1][i]=add(s[1][i-1]+f[1][i]),sc[1][i]=add(sc[1][i-1]+1ll*i*f[1][i]%mod);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			f[i][j]=sub(1ll*(j+1)*s[i-1][j]%mod-sc[i-1][j]+1);
			s[i][j]=add(s[i][j-1]+f[i][j]),sc[i][j]=add(sc[i][j-1]+1ll*j*f[i][j]%mod);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=add(ans+1ll*(m-j+1)*f[i][j]%mod*sub(1ll*(j+1)*s[n-i][j-1]%mod-sc[n-i][j-1]+1)%mod);
	printf("%d\n",ans);
	return 0;
}