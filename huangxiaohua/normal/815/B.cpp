#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,sb[100500],x,y;

ll jc[1005000],inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}

ll a[200500],f1[200500],f2[200500],res;
int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if((n%4)==1){
		for(i=1;i<=n;i+=2){
			y=min(x,n-x);
			res+=c(n/2,y)*a[i]%M;
			//printf("%d\n",c(n/2,y));
			x++;
		}
		res=(res%M+M)%M;
		printf("%lld",res);return 0;
	}
	if((n%4)==2){
		for(i=1;i<=n;i+=2){
			y=min(x,n-x);
			res+=c(n/2-1,y)*a[i]%M;
			res+=c(n/2-1,y)*a[i+1]%M;
			//printf("%d\n",c(n/2-1,y));
			x++;
		}
		res=(res%M+M)%M;
		printf("%lld",res);return 0;
	}
	if((n%4)==3){
		for(i=1;i<n;i+=2){
			y=min(x,n-x);
			res+=c(n/2-1,y)*a[i]%M;
			res+=c(n/2-1,y)*a[i+1]%M;
			//printf("%d\n",c(n/2-1,y));
			x++;
		}
		x=0;
		for(i=2;i<=n;i+=2){
			y=min(x,n-x);
			res+=c(n/2-1,y)*a[i]%M;
			res-=c(n/2-1,y)*a[i+1]%M;
			//printf("%d\n",c(n/2-1,y));
			x++;
		}
		res=(res%M+M)%M;
		printf("%lld",res);return 0;
	}
	if((n%4)==0){
		for(i=1;i<=n;i+=2){
			y=min(x,n-x);
			res+=c(n/2-1,y)*a[i]%M;
			res-=c(n/2-1,y)*a[i+1]%M;
			//printf("%d\n",c(n/2-1,y));
			x++;
		}
		res=(res%M+M)%M;
		printf("%lld",res);return 0;
	}
}