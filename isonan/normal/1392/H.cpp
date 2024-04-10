#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,m,s;
int _mul[4000001],invmul[4000001];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=4000000;++i)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=4000000;++i)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=4000000;++i)invmul[i]=mul(invmul[i-1],invmul[i]);
	scanf("%d%d",&n,&m);
	s=add(1,mul(n,qsm(1+m,P-2)));
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=((i&1)?add:sub)(ans,mul(C(n,i),mul(i+m,qsm(i,P-2))));
	}
	printf("%d\n",mul(ans,s));
}