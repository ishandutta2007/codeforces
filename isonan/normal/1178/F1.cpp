#include <cstdio>
 
int n,m,c[510],f[510][510];
const int P=998244353;
inline int mul(const int &a,const int &b){
	return 1ll*a*b%P;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",c+i);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			if(i>j)f[i][j]=1;
	for(int gap=1;gap<=n;gap++)
		for(int i=1;i+gap-1<=n;i++){
			int j=i+gap-1;
			if(i==j){
				f[i][i]=1;
				continue;
			}
			int mx=0x7f7f7f7f,p=0;
			for(int k=i;k<=j;k++)
				if(c[k]<mx)mx=c[k],p=k;
			int tem0=0,tem1=0;
			for(int l=i;l<=p;l++)(tem0+=mul(f[i][l-1],f[l][p-1]))%=P;
			for(int m=p;m<=j;m++)(tem1+=mul(f[p+1][m],f[m+1][j]))%=P;
			f[i][j]=mul(tem0,tem1);
		}
	printf("%d\n",f[1][n]);
}