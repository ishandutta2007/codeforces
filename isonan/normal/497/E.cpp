#include <cstdio>

const int P=1000000007;
long long p=1ll*P*P;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int k;
long long n;
struct matrix{
	int num[31][31];
	matrix operator*(matrix a){
		matrix c;
		for(int i=0;i<=k;i++)
			for(int j=0;j<=k;j++){
				unsigned long long tem=0;
				for(int l=0;l<=k;l++)
					if((tem+=1ll*num[i][l]*a.num[l][j])>=p)tem-=p;
				c.num[i][j]=tem%P;
			}
		return c;
	}
}f[70][30];
int stk[70],top;
int main(){
	scanf("%lld%d",&n,&k);
	for(int i=0;i<k;i++){
		for(int j=0;j<=k;j++)f[0][i].num[j][j]=f[0][i].num[j][i]=1;
	}
	while(n){
		stk[top++]=n%k;
		n/=k;
	}
	for(int i=1;i<top;i++){
		for(int j=0;j<k;j++){
			for(int l=0;l<=k;l++)f[i][j].num[l][l]=1;
			for(int l=0;l<k;l++)f[i][j]=f[i][j]*f[i-1][(j+l)%k];
		}
	}
	matrix ans;
	for(int l=0;l<=k;l++)
		for(int m=0;m<=k;m++)
			ans.num[l][m]=(l==k&&m==k);
	for(int j=top-1,sum=0;~j;--j){
		for(int l=0;l<stk[j];l++){
			ans=ans*f[j][sum];
			sum=(sum+1)%k; 
		}
	}
	int fin=0;
	for(int i=0;i<=k;i++)fin=add(fin,ans.num[k][i]);
	printf("%d\n",fin);
}