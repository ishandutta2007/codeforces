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
int f[101][10001],c[101],b[101],n,q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",c+i);
	for(int i=2;i<=n;++i)scanf("%d",b+i);
	for(int i=2;i<=n;++i)b[i]+=b[i-1];
	scanf("%d",&q);
	for(int i=1,x;i<=q;++i){
		scanf("%d",&x);
		for(int j=0;j<=c[1];++j)
			if(j>=x)f[1][j]=1;
		int sum=c[1],Lim=0;
		for(int j=2;j<=n;++j){
			Lim+=b[j];
			for(int k=0;k<=sum;++k){
				int u=std::max(k,Lim+x*j);
				if(u<=sum+c[j]&&u<=k+c[j]){
					f[j][u]=add(f[j][u],f[j-1][k]);
					if(k+c[j]+1<=sum+c[j])
						f[j][k+c[j]+1]=sub(f[j][k+c[j]+1],f[j-1][k]);
				}
			}
			sum+=c[j];
			for(int k=0;k<=sum;++k)
				f[j][k]=add(f[j][k],f[j][k-1]);
//			for(int k=0;k<=sum;++k)
//				printf("%d ",f[j][k]);putchar('\n');
		}
		int ans=0;
		for(int k=0;k<=sum;++k)ans=add(ans,f[n][k]);
		printf("%d\n",ans);
	}
}