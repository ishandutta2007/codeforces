#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t;
ll jc[200500],inv[200500],p[200500],res;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){
	if(m<0||m>n||n<0){return 0;}
	return jc[n]*inv[m]%M*inv[n-m]%M;
}
void init(){
	jc[0]=inv[0]=1;
	for(i=1;i<=200000;i++){jc[i]=jc[i-1]*i%M;}
	inv[200000]=ksm(jc[200000],M-2);
	for(i=199999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
}
int main(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);m--;
		res=0;
		for(i=1;i<=n;i++){
			ll sb=n-1ll*(i-1)*m;
			if(sb<0){p[i]=0;continue;}
			p[i]=c(sb,i)*ksm(c(n,i),M-2)%M;
		}
		for(i=1;i<=n;i++){
			res+=(p[i]-p[i+1])*(i+1)%M;
		}
		printf("%lld\n",(res%M+M)%M);
	}
}