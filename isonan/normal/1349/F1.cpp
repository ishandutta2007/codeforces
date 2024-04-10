#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int inv[5001],f[5001][5001],g[5001],n,C[5001][5001],_mul[5001],invmul[5001];
int main(){
	scanf("%d",&n);
	f[0][0]=1;
	C[0][0]=1;
	_mul[0]=_mul[1]=1;
	invmul[0]=invmul[1]=1;
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			f[i][j]=mul(j,add(f[i-1][j],f[i-1][j-1]));
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			g[j]=add(g[j],mul(f[i][i-j],invmul[i]));
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=0;j<n;j++)
			ans=(((i-j)&1)?sub:add)(ans,mul(C[j][i],g[j]));
		ans=mul(ans,_mul[n]);
		printf("%d ",ans);
	}
}