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
int n,a[200010];
int invmul[6000001],_mul[6000001];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(_mul[n],mul(invmul[m],invmul[n-m]));
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",a+i);
	_mul[0]=1;
	for(int i=1;i<=600000;++i)_mul[i]=mul(_mul[i-1],i);
	invmul[0]=1;
	for(int i=1;i<=600000;++i)invmul[i]=mul(invmul[i-1],qsm(i,P-2));
	int ans=0;
	for(int i=0;i<=n;++i)ans=add(ans,C(a[i]+i,i+1));
	printf("%d\n",ans);
}