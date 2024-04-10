#include <stdio.h>
typedef long long ll;
#define M 998244353
int i,j,k,n,m,rk[200500],a[200500],cur=1,cur2;
ll jc[200500],inv[200500],res;
ll c(int n,int m){if(m>n||m<0){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}

int main(){
	jc[0]=1;inv[0]=1;
	for(i=1;i<=200000;i++){jc[i]=jc[i-1]*i%M;}
	inv[200000]=532999597;
	for(i=199999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d",&n,&m);
	a[0]=n+1;
	for(i=1;i<=n;i++){
		scanf("%d",&k);k++;rk[k]=i;a[n+1-i]=k;
	}
	for(i=2;i<=n;i++){
		if(rk[a[i-1]+1]<rk[a[i]+1]){cur++;}else{cur2++;}
	}
	for(i=cur;i<=m;i++){
		res+=c(m,i)*c(cur2,i-cur)%M;res%=M;
	}
	printf("%lld",res);
}