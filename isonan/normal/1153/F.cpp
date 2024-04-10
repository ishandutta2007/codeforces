#include <cstdio>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int inv(int a){return  (a<=1)?1:mul(P-P/a,inv(P%a));}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int f[4010][2010][2],n,k,l;
int main(){
	scanf("%d%d%d",&n,&k,&l);
	f[0][0][0]=1;
	for(int i=1;i<=(n<<1)+1;i++)
		for(int j=0;j<=n&&j<=i;j++){
			if(j>=k)f[i][j][1]=add(f[i][j][1],f[i-1][j][0]);
			f[i][j][1]=add(f[i][j][1],f[i-1][j-1][1]);
			f[i][j][0]=add(f[i][j][0],f[i-1][j-1][0]);
			f[i][j][1]=add(f[i][j][1],mul(f[i-1][j+1][1],j+1));
			f[i][j][0]=add(f[i][j][0],mul(f[i-1][j+1][0],j+1));
		}
	int ans=f[(n<<1)+1][0][1];
	for(int i=1;i<=n+1;i++)ans=mul(ans,inv(i+n));
	printf("%d\n",mul(mul(ans,l),qsm(2,n)));
}