#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,ou,tot;
ll jc[1005000],inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}


int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ou=tot=0;
		j=0;
		for(i=1;i<=n;i++){
			scanf("%1d",&k);
			if(!k){
				tot++;
				ou+=j/2;j=0;
			}
			else{j++;}
		}
		ou+=j/2;
		tot+=ou;
		printf("%lld\n",c(tot,ou));
	}
}