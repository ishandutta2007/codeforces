#include <cstdio>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){return(a<b)?a-b+P:(a-b);}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int n,a[300001];
int _mul[300001],invmul[300001];
int C(int n,int m){
	return 1ll*_mul[n]*invmul[m]%P*invmul[n-m]%P;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d",a+i);
	
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=(n<<1);i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=(n<<1);i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=(n<<1);i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	std::sort(a+1,a+(n<<1)+1);
	int ans=0;
	for(int i=1;i<=(n<<1);i++){
		if(n-i+1>0){
			ans=sub(ans,mul(a[i],C((n<<1)-1,n)));
		}
		else{
			ans=add(ans,mul(a[i],C((n<<1)-1,n)));
		}
	}
	std::reverse(a+1,a+(n<<1)+1);
	for(int i=1;i<=(n<<1);i++){
		if(n-i+1>0){
			ans=add(ans,mul(a[i],C((n<<1)-1,n)));
		}
		else{
			ans=sub(ans,mul(a[i],C((n<<1)-1,n)));
		}
	}
	printf("%d\n",ans);
}