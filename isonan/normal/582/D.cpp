#include <cstdio>
#include <cstring>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
long long f[1001][3410],g[3410];
int F[3410][3410][2][2];
int p,a,nl;
char str[1001];
int fac(int n,int l=0){return ((1ll*(l+n)*(n-l+1))>>1)%P;}
int main(){
	scanf("%d%d",&p,&a);
	scanf("%s",str+1);
	nl=strlen(str+1);
	f[0][0]=1;
	f[0][1]=1;
	for(int i=1;i<=nl;i++){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for(int j=1;j<=f[i][0];j++)f[i][j]*=10;
		for(int j=1;j<=f[i][0];j++){
			f[i][j+1]+=f[i][j]/p;
			f[i][j]%=p;
		}
		while(f[i][f[i][0]+1]){
			++f[i][0];
			f[i][f[i][0]+1]+=f[i][f[i][0]]/p;
			f[i][f[i][0]]%=p;
		}
	}
	long long len=0;
	for(int i=1;i<=nl;i++){
		for(int j=1;j<=f[nl-i][0];j++)g[j]+=f[nl-i][j]*(str[i]-'0');
		len=std::max(len,f[nl-i][0]);
	}
	for(int i=1;i<=len;i++){
		g[i+1]+=g[i]/p;
		g[i]%=p;
	}
	while(g[len+1]){
		++len;
		g[len+1]+=g[len]/p;
		g[len]%=p;
	}
	if(a>=len){
		puts("0");
		return 0;
	}
	F[0][0][0][0]=F[0][0][1][0]=1;
	for(int i=1;i<=len;i++){
		for(int j=0;j<i;j++){
			F[i][j][0][0]=add(mul(fac(p-1),j?F[i-1][j-1][0][1]:0),mul(fac(p),F[i-1][j][0][0]));
			F[i][j][0][1]=add(mul(fac(p),j?F[i-1][j-1][0][1]:0),mul(fac(p-1),F[i-1][j][0][0]));
			F[i][j][1][0]=add(
							add(mul(fac(g[i]-1),j?F[i-1][j-1][0][1]:0),mul(fac(g[i]),F[i-1][j][0][0])),
							add(mul(g[i]+1,F[i-1][j][1][0]),mul(g[i],j?F[i-1][j-1][1][1]:0)));
			F[i][j][1][1]=add(
							add(mul(fac(p,p-g[i]+1),j?F[i-1][j-1][0][1]:0),mul(fac(p-1,p-g[i]),F[i-1][j][0][0])),
							add(F[i][j][1][1],add(mul(p-g[i],j?F[i-1][j-1][1][1]:0),mul(p-g[i]-1,F[i-1][j][1][0]))));
		}
	}
	int ans=0;
	for(int i=a;i<len;i++)ans=add(ans,F[len][i][1][0]);
	printf("%d",ans);
}