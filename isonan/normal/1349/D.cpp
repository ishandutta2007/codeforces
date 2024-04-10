#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,a[300010],sum,Inv[300010];
struct num{
	int k,b;
	num operator+(num a){return (num){add(k,a.k),add(b,a.b)};}
	num operator-(num a){return (num){sub(k,a.k),sub(b,a.b)};}
	num operator*(int x){return (num){mul(x,k),mul(x,b)};}
}f[300010];
int g[300010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),sum+=a[i];
	f[0]=(num){1,0};
	Inv[0]=Inv[1]=1;
	for(int i=2;i<=300000;i++)Inv[i]=mul(P-P/i,Inv[P%i]);
	int x;
	for(int i=0;i<sum;i++){
		num v=f[i]*sub(1,mul(mul(sum-i,Inv[sum]),mul(n-2,Inv[n-1]))); 
		if(i)v=v-f[i-1]*mul(i,Inv[sum]);
		v.b=sub(v.b,1);
		f[i+1]=v*mul(mul(n-1,sum),Inv[sum-i]);
	}
	int v=mul(sub(0,f[sum].b),qsm(f[sum].k,P-2));
	for(int i=0;i<=sum;i++)g[i]=add(mul(f[i].k,v),f[i].b);
	int fin=0;
	for(int i=1;i<=n;i++)fin=add(fin,g[a[i]]);
	fin=sub(fin,mul(g[0],n-1));
	printf("%d\n",mul(fin,qsm(n,P-2)));
}