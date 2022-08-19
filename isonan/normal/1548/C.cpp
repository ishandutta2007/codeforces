#include <cstdio>
const int P=1000000007;
	long long p=1ll*P*P;
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
	const int fac_size=3000010;
	int _mul[fac_size+1],invmul[fac_size+1],inv[fac_size+1];
	void init(int n=fac_size){
		inv[0]=inv[1]=_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
		for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
		for(int i=2;i<=n;i++)inv[i]=mul(P-P/i,inv[P%i]);
		for(int i=2;i<=n;i++)invmul[i]=mul(invmul[i-1],inv[i]);
	}
	int C(int n,int m){
		if(n<m||m<0)return 0;
		return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
	}
int f[3000001][3],n,q;
int inv3=qsm(3,P-2);
int main(){
	init();
	scanf("%d%d",&n,&q);
	f[0][0]=f[0][1]=f[0][2]=n;
	for(int i=1;i<=3*n;++i){
		int sum=C(3*n+1,i+1);
//		printf("%d\n",sum);
		int x0=f[i-1][1],x1=f[i-1][2],x2=f[i-1][0];
		x2=add(x2,C(0,i-1));
		x2=sub(x2,C(3*n,i-1));
		x2=add(x2,C(0,i));
		x2=sub(x2,C(3*n,i));
//		printf("%d %d %d\n",x0,x1,x2);
		f[i][0]=mul(inv3,add(add(add(x0,x0),x1),sum));
		f[i][2]=add(f[i][0],x2);
		f[i][1]=add(f[i][2],x1);
//		printf("%d %d %d\n",f[i][0],f[i][1],f[i][2]);
	}
	for(int i=1;i<=q;++i){
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x][0]);
	}
}