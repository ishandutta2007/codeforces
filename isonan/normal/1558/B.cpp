#include <cstdio>
#include <algorithm>

int P=998244353;
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
int n,f[4000010];
int main(){
	scanf("%d%d",&n,&P);
	f[n]=1;
	for(int i=n;i;--i){
		f[i]=add(f[i],f[i+1]);
		for(int j=(i<<1);j<=n;j+=i){
			f[i]=add(f[i],sub(f[j],f[std::min(j+(j/i),n+1)]));
		}
		f[i]=add(f[i],f[i+1]);
	}
	printf("%d\n",sub(f[1],f[2]));
}