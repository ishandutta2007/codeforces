#include <stdio.h>
typedef long long ll;
#define M 998244353
int i,j,k,n,m,sb;
ll res,inv[10050],jc[10050],tmp;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){
	if(n==-1&&m==-1){return 1;}
	if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;
}
int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=10000;i++){jc[i]=jc[i-1]*i%M;}
	inv[10000]=265002293;
	for(i=9999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d%d",&n,&m,&sb);n--;
	for(i=sb;i<=m;i++){
		for(j=0;j<=n;j++){
			tmp=0;
			for(k=0;k<=n-j;k++){
				tmp+=((k&1)?-1:1)*c(m-i-j*i-k*i+(n-j-1),n-j-1)*c(n-j,k);tmp%=M;
			}
			res+=tmp*ksm(j+1,M-2)%M*c(n,j)%M;res%=M;
		}
	}
	res*=ksm(c(m-sb+n,n),M-2);
	printf("%lld",(res%M+M)%M);
}