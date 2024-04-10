#include <cstdio>

int n,P,_mul[2500001],invmul[2500001];
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int main(){
	scanf("%d%d",&n,&P);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=add(ans,mul(n-i+1,mul(n-i+1,mul(_mul[i],_mul[n-i]))));
	}
	printf("%d\n",ans);
}