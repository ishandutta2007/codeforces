#include <cstdio>
#include <algorithm>

int n,m;
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int invmul[2040],_mul[4080],g[2040][2040];
int f(int n,int m){
	return mul(mul(_mul[n+m],invmul[n]),invmul[m]);
}
int main(){
	scanf("%d%d",&n,&m);
	if(n<m)std::swap(n,m);
	invmul[0]=invmul[1]=_mul[0]=_mul[1]=1;
	for(int i=2;i<=(n<<1);++i)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;++i)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n;++i)invmul[i]=mul(invmul[i-1],invmul[i]);
	int ans=0;
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			g[i][j]=add(g[i][j-1],mul(f(i,j-1),f(i-1,m-j)));
//			printf("%d %d %d %d %d\n",n,m,i,j,sub(g[i][j],g[i][j-1]));
		}
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)ans=add(ans,mul(sub(g[i][j],g[i][j-1]),g[n-i][m-j]));
	std::swap(n,m);
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j)g[i][j]=add(g[i][j-1],mul(f(i,j-1),f(i-1,m-j)));
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)ans=add(ans,mul(sub(g[i][j],g[i][j-1]),g[n-i][m-j-1]));
	printf("%d\n",mul(ans,2));
}