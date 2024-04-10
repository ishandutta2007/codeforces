#include <cstdio>
#include <algorithm>

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
int f[1000010],g[1000010];
int main(){
	f[0]=1;
	for(int i=1;i<=1000000;++i){
		f[i]=add(qsm(2,i),0);
		// if(i<=100)printf("%d ",f[i]);
	}
	int t,n;
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		g[0]=2;
		for(int i=1;i<n;++i){
			g[i]=g[i-1];
			if(i>=n-i)g[i]=sub(g[i],g[i-(n-i)]);
			// else g[i]=add(g[i],1);
			g[i]=add(g[i],g[i-1]);
			// printf("%d\n",sub(g[i],g[i-1]));
		}
		int inv=qsm((P+1)>>1,n);
		// inv=1;
		for(int i=n-1;i;--i)g[i]=sub(g[i],g[i-1]);
		for(int i=1;i<=n;++i){
			// printf("%d\n",f[i]);
			printf("%d\n",mul(mul(f[i>>1],g[n-i]),inv));
		}
	}
}