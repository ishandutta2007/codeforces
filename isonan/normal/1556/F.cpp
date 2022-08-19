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
int n,a[14],f[1048576],win[14][14];
int v[1048576];
int stk[1048576],top;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			win[i][j]=mul(a[i],qsm(add(a[i],a[j]),P-2));
	for(int i=0;i<(1<<n);++i)f[i]=1;
	int ans=0;
	for(int i=1;i<(1<<n);++i){
		int x=((1<<n)-1)^i;
		top=0;
		for(int j=x;j;j=(j-1)&x)v[j]=1,stk[++top]=j;
		v[0]=1;
		for(int j=0;j<n;++j)
			if(!(i&(1<<j))){
				for(int k=0;k<n;++k)
					if(i&(1<<k)){
						v[1<<j]=mul(v[1<<j],win[k][j]);
					}
			}
		for(int j=top;j;--j){
			int u=stk[j];
			for(int k=0;k<n;++k)
				if(!((i|u)&(1<<k))){
					v[u|(1<<k)]=mul(v[u],v[1<<k]);
				}
		}
		for(int j=top;j;--j){
			int u=stk[j];
			f[i|u]=sub(f[i|u],mul(f[i],v[u]));
		}
		ans=add(ans,mul(__builtin_popcount(i),mul(f[i],v[x])));
	}
	printf("%d\n",ans);
}