#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=101000;
typedef long long ll;
int n,f[36][maxn];
ll k,g[36][maxn],m[36][maxn];
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();k=read();
	for(register int i=0;i<n;++i)
		f[0][i]=read();
	for(register int i=0;i<n;++i)
		g[0][i]=m[0][i]=read();
	for(register int i=1;k>>i;++i)
		for(register int j=0;j<n;++j){
			f[i][j]=f[i-1][f[i-1][j]];
			g[i][j]=g[i-1][j]+g[i-1][f[i-1][j]];
			m[i][j]=min(m[i-1][j],m[i-1][f[i-1][j]]);
		}
	for(register int i=0;i<n;++i){
		ll asum=0,amin=1ll<<30;
		for(register int j=0,p=i;k>>j;++j)
			if((k>>j)&1){
				asum+=g[j][p];
				amin=min(amin,m[j][p]);
				p=f[j][p];
			}
		printf("%lld %lld\n",asum,amin);
	}
	return 0;
}