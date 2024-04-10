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
int f[1501][1501],g[1501][1501],n,m,k,p,t1,t2,h[1501],_mul[100001],invmul[100001];
int sum[2][1510];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&k);
	p=mul(t1,qsm(t2,P-2));
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=k;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=k;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=k;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=0;i<=m&&i<=k;i++)h[i]=mul(mul(C(k,i),qsm(p,i)),qsm(sub(1,p),k-i));
	for(int i=1;i<=m;i++)f[0][i]=1;
	for(int i=1;i<m;i++)g[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			f[i-1][j]=add(f[i-1][j],f[i-1][j-1]),
			g[i-1][j]=add(g[i-1][j],g[i-1][j-1]);
		for(int j=1;j<=m;j++)
			sum[0][j]=add(sum[0][j-1],h[j-1]);
		for(int j=m;j;j--)
			sum[1][j]=add(sum[1][j+1],mul(h[m-j],sub(f[i-1][j],g[i-1][j-1])));
		for(int j=1;j<=m;j++)
			f[i][j]=add(f[i][j],mul(sum[0][j],sum[1][j]));
		for(int j=1;j<m;j++)
			g[i][j]=add(g[i][j],mul(sum[0][j],sum[1][j+1]));
		for(int j=1;j<=m;j++)
			sum[0][j]=add(sum[0][j-1],mul(h[j-1],sub(g[i-1][j-1],f[i-1][j-1])));
		for(int j=m;j;j--)
			sum[1][j]=add(sum[1][j+1],h[m-j]);
		for(int j=1;j<=m;j++)
			f[i][j]=add(f[i][j],mul(sum[0][j],sum[1][j]));
		for(int j=1;j<m;j++)
			g[i][j]=add(g[i][j],mul(sum[0][j],sum[1][j+1]));
	}
	int ans=0;
	for(int j=1;j<=m;j++)ans=add(ans,f[n][j]);
	for(int j=1;j<m;j++)ans=sub(ans,g[n][j]);
	printf("%d\n",ans);
}