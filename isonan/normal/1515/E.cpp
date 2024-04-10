#include <cstdio>

int n,M;
inline int mul(const int &a,const int &b){return 1ll*a*b%M;}
inline int add(int a,const int &b){a+=b;return(a>=M)?a-M:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+M:a;}
int f[401][401],g[401],h[401];
int invmul[401],_mul[401];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	scanf("%d%d",&n,&M);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n;++i)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;++i)invmul[i]=mul(M-M/i,invmul[M%i]);
	for(int i=2;i<=n;++i)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=2;i<=n;++i)h[i]=h[i-1]+(i%2==0); 
	g[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			g[i]=add(g[i],C(i-1,j-1));
		}
		g[i]=mul(g[i],invmul[i]);
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i){
//		printf("%d\n",mul(g[i],_mul[i]));
		for(int j=0;j<=n;++j){
			for(int k=1;k<=j;++k){
//				printf("%d %d %d\n",i,j,k);
				f[i][j]=add(f[i][j],mul(f[i-1][j-k],g[k]));
			}
		}
//		printf("%d %d\n",f[0][0],g[n]);
	}
	int ans=0;
	for(int i=0;i<=n;++i){
//		printf("%d\n",mul(f[i+1][n-i],_mul[n-i]));
		ans=add(ans,mul(f[i+1][n-i],_mul[n-i]));
	}
	printf("%d\n",ans);
}