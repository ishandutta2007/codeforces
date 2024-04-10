// Hydro submission #62c541f08672efa577be982b@1657094641133
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
namespace code{
	#define R register
	char s[705];int n,a[705];
	int f[2][2],g[2][2],ans;
	const int mod=1e9+7;
	inline int pls(int x,int y){return x+y>=mod?x+y-mod:x+y;}
	inline int mul(int x,int y){return 1LL*x*y%mod;}
	inline void main(){
		scanf("%s",s+1),n=strlen(s+1);
		for(R int i=1;i<=n;i=-~i)a[i]=s[i]-48;
		for(R int p=1;p<=9;p=-~p){
			int now=0,nxt=1;
			f[now][0]=f[now][1]=g[now][0]=g[now][1]=0;
			g[now][1]=p;
			for(R int i=0;i<n;i=-~i){
				f[nxt][0]=f[nxt][1]=g[nxt][0]=g[nxt][1]=0;
				for(R int j=0;j<=1;j=-~j){
					int up=j?a[i+1]:9;
					for(R int k=0;k<=up;k=-~k){
						int l=j&&k==up;
						if(k<p)f[nxt][l]=pls(f[nxt][l],f[now][j]),g[nxt][l]=pls(g[nxt][l],g[now][j]);
						else if(k==p)f[nxt][l]=pls(f[nxt][l],pls(g[now][j],mul(10,f[now][j]))),g[nxt][l]=pls(g[nxt][l],g[now][j]);
						else f[nxt][l]=pls(f[nxt][l],mul(10,f[now][j])),g[nxt][l]=pls(g[nxt][l],mul(10,g[now][j]));
					}
				}
				now^=nxt^=now^=nxt;
			}
			ans=pls(ans,pls(f[now][0],f[now][1]));
		}
		printf("%d\n",ans);
	}
}
int main(){return code::main(),0;}