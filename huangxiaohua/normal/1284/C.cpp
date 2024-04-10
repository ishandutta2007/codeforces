#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m,t,sb[100500];
ll jc[1005000],inv[1005000],M,n,res;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
int main() {
	scanf("%lld%lld",&n,&M);
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	for(i=1;i<=n;i++){
		res+=(n-i+1)*(n-i+1)%M*ksm(c(n,i),M-2)%M;res%=M;
	}
	res=res*jc[n]%M;
	printf("%lld",res);
}