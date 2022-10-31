// Hydro submission #63298f0979b7c59ccd1edb7e@1663667978051
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
const int N=505, mod=998244353;
int n, ans, a[N], f[N][N];
signed main() {
	n=read();
	for(int i=1;i<=n;++i) {
		char c; scanf(" %c",&c);
		if(c=='-') a[i]=-1; else a[i]=read();
	}
	for(int p=1;p<=n;++p) {
		int x=a[p];
		if(x==-1) continue;
		for(int i=0;i<=500;++i) for(int j=0;j<=500;++j) f[i][j]=0;
		f[0][0]=1;
		for(int i=1;i<=n;++i) {
			if(i==p) { memcpy(f[i],f[i-1],sizeof(f[i])); continue; }
			for(int j=0;j<=n;++j) {
				if(a[i]==-1) {
					f[i][j]=(f[i-1][j]+f[i-1][j+1])%mod;
					if(i<p&&!j) (f[i][j]+=f[i-1][j])%=mod;
				} else if(a[i]<x||(a[i]==x&&i<p)){
				    f[i][j]=f[i-1][j];
				    if(j) (f[i][j]+=f[i-1][j-1])%=mod;
				} else if(a[i]>x||(a[i]==x&&i>p)) f[i][j]=2*f[i-1][j]%mod;
			}
//			if(a[i]>x||(a[i]==x&&i>p))
		}
		int sum=0;
		for(int i=0;i<=n;++i) (sum+=f[n][i])%=mod;
		(ans+=sum*x%mod)%=mod;
	}
	printf("%lld\n",ans);
}