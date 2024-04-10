// Hydro submission #631debbc32ae6c3198c712f9@1662905276633
#include<bits/stdc++.h>
using namespace std;
#define maxn 200009
#define maxm 3009
const long long mod=998244353;
int n,m,w[maxn],a[maxn];
int f[maxm][maxm],sums[2];
long long fp(long long x,int b){
	long long sum=1;
	while(b){
		if(b&1){
			sum=sum*x%mod;
		}
		x=x*x%mod;
		b>>=1;
	} 
	return sum;
}
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;if(x<0)x+=mod;
	return ;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	
	}
	for(int i=1;i<=n;i++){
		w[i]=read();
		sums[a[i]]+=w[i];
		sums[a[i]]%=mod;
	}
	long long csum=(sums[0]+sums[1])%mod;
	f[0][0]=1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m-i;j++){
			int inv=fp(csum-i+j,mod-2);
			add(f[i+1][j],1ll*f[i][j]*(sums[0]-i)%mod*inv%mod);
			add(f[i][j+1],1ll*f[i][j]*(sums[1]+j)%mod*inv%mod);
		}
	}
	int s0=0,s1=0;
	for(int i=0;i<=m;i++){
		add(s0,1ll*(sums[0]-i+mod)%mod*f[i][m-i]%mod);
		add(s1,1ll*(sums[1]+m-i)%mod*f[i][m-i]%mod);
	}
	int inv0=fp(sums[0],mod-2),inv1=fp(sums[1],mod-2);
	for(int i=1;i<=n;i++){
		long long ans=0;
		if(a[i]){
			ans=1ll*s1*w[i]%mod*inv1%mod;
		}
		else{
			ans=1ll*s0*w[i]%mod*inv0%mod;
		}
		printf("%lld\n",ans);
	}
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}