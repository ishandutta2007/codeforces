#include <cstdio>

const int P=1000000007;
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
int n,k,f[2000001],ans;
int main(){
	scanf("%d%d",&n,&k);
// 	n=k=2000000;
	for(int i=1,last=0;i<=k;i++){
		last=add(last,f[i]);
		f[i]=sub(qsm(i,n),last);
		ans=add(ans,f[i]^i);
		int tem=sub(f[i],f[i-1]);
		for(int j=i+i;j<=k;j+=i)
			f[j]=add(f[j],tem);
	}
	printf("%d\n",ans);
}