#include <cstdio>

int f[401],ans[401],t,P,_mul[401],invmul[401],g[401][401];
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
int C(int n,int m){return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
int main(){
	scanf("%d%d",&t,&P);
	ans[1]=1,ans[2]=2;
	f[1]=1,f[2]=1;
	_mul[0]=1,_mul[1]=1,_mul[2]=2;
	invmul[0]=1,invmul[1]=1,invmul[2]=(P+1)>>1;
	g[1][1]=1,g[2][1]=2,g[2][2]=1;
	for(int i=3;i<=400;i++){
		_mul[i]=mul(_mul[i-1],i);
		invmul[i]=qsm(_mul[i],P-2);
		for(int j=1;j<i;j++)
			f[i]=add(f[i],mul((j==1?1:sub(_mul[j],f[j])),_mul[i-j]));
		for(int j=2;j<=i;j++){
			for(int k=1;k<i;k++)
				g[i][j]=add(g[i][j],mul(g[k][j-1],_mul[i-k]));
		}
		g[i][1]=_mul[i];
		ans[i]=sub(_mul[i],mul(f[i],2));
		for(int j=4;j<i;j++){
			ans[i]=sub(ans[i],mul(ans[j],g[i][j]));
		}
//		printf("%d %d %d\n",_mul[i],f[i],ans[i]);
	}
	for(int i=1,n;i<=t;i++){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}