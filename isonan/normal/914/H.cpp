#include <cstdio>
#define int long long

int n,d,P,f[210][210],g[210][210],F[210],C[210][210];
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
signed main(){
	scanf("%lld%lld%lld",&n,&d,&P);
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	f[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<d;j++)F[i]=add(F[i],f[j][i-1]);
		for(int j=i;j;j--)
			for(int k=1;k<=i;k++)
				f[j][i]=add(f[j][i],mul(C[i-1][k-1],mul(f[j-1][i-k],F[k])));
	}
	int ans=0;
	for(int j=0;j<=d;j++)F[n]=add(F[n],f[j][n-1]);
	for(int i=0;i<n;i++)
		for(int j=0;j<=d;j++)
			for(int k=0;k+j<=d;k++)
				if(k!=1)ans=add(ans,mul(f[j][i],f[k][n-1-i]));
	printf("%lld",mul(ans,2ll*n%P*(n-1)%P));
}