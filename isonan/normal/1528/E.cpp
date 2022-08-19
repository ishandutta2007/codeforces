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
int n,f[1000010],g[1000010];
int C(int n,int m){
	int ans=1,inv=1;
	for(int i=0;i<m;++i)ans=mul(ans,add(n,i)),inv=mul(inv,i+1);
	return mul(ans,qsm(inv,P-2));
}
int main(){
	scanf("%d",&n);
	f[1]=g[1]=1;
	for(int i=2;i<=n+1;++i){
		f[i]=add(mul(f[i-1],g[i-2]),C(f[i-1],2));
		f[i]=add(f[i],f[i-1]);
		g[i]=add(g[i-1],f[i]);
	}
//	for(int i=1;i<=n+1;++i)printf("%d %d\n",f[i],g[i]);
	int ans=0;
	ans=add(ans,f[n+1]);
	ans=add(ans,mul(f[n],mul(mul(g[n-1],add(g[n-1],1)),(P+1)>>1)));
	ans=add(ans,mul(g[n-1],mul(mul(f[n],add(f[n],1)),(P+1)>>1)));
	ans=add(ans,mul(mul(mul(f[n],add(f[n],1)),add(f[n],2)),qsm(6,P-2)));
	ans=mul(ans,2);
	ans=sub(ans,1);
	for(int i=n+1;i;--i)
		f[i]=sub(f[i],f[i-1]);
	f[1]=0;
	for(int i=1;i<=n+1;++i)
		g[i]=add(g[i-1],f[i]);
//	for(int i=1;i<=n;++i)printf("%d %d\n",f[i],g[i]);
	for(int i=1;i<=n;++i)
		ans=add(ans,mul(f[i],g[n+1-i]));
	printf("%d\n",ans);
}