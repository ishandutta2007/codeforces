#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=81;
int n,xm;
int f[maxn][maxn][maxn*maxn];
int t[maxn],tp;
bool vis[maxn][maxn][maxn*maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();xm=(n*(n-1))>>1;
	for(register int i=1;i<=n;++i)
		if(read())t[++tp]=i;
	for(register int i=1;i<=n-tp+1;++i){
		f[1][i][abs(t[1]-i)]=(i-1)*(n-i-tp+1);
		vis[1][i][abs(t[1]-i)]=true;
	}
	for(register int i=1;i<tp;++i)
		for(register int j=i;j<=n;++j)
			for(register int k=0;k<=xm;++k){
				if(!vis[i][j][k])continue;
				for(register int l=j+1;l<=n;++l){
					f[i+1][l][k+abs(t[i+1]-l)]=max(f[i+1][l][k+abs(t[i+1]-l)],f[i][j][k]+(l-j-1)*(n-l-(tp-i-1)));
					vis[i+1][l][k+abs(t[i+1]-l)]=true;
				}
			}
	int ans=0;
	for(register int i=0;i<=xm;++i){
		for(register int j=1;j<=n;++j)
			ans=max(ans,f[tp][j][i]);
		printf("%d ",ans);
	}
	return 0;
}