#include <cstdio>

const int P=1000000007;
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
int n,k,f[5001];
int main(){
	scanf("%d%d",&n,&k);
	int ans=1;
	f[0]=1;
	for(int i=1,tem;i<=n;i++){
		scanf("%d",&tem);
		ans=mul(ans,tem);
		for(int j=n;~j;--j){
			f[j]=mul(f[j],tem);
			if(j)f[j]=sub(f[j],f[j-1]);
		}
	}
	int inv=qsm(n,P-2);
	for(int i=0,Mul=1;i<=n;i++){
		ans=sub(ans,mul(f[i],Mul));
		Mul=mul(Mul,k-i);
		Mul=mul(Mul,inv);
	}
	printf("%d\n",ans);
}