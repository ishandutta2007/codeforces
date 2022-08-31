#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){
	return 1ll*a*b%P;
}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int w,h;
int main(){
	scanf("%d%d",&w,&h);
	printf("%d",qsm(2,w+h));
}