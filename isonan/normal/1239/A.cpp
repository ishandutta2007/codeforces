#include <cstdio>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int f[100001];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	f[1]=2;
	f[2]=4;
	for(int i=3;i<=100000;i++)f[i]=add(f[i-1],f[i-2]);
	printf("%d",sub(add(f[n],f[m]),2));
}