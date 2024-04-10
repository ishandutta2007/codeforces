#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,l,r;
ll m,a[200500],res,sum;
ll jc[205000],inv[205000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=200000;i++){jc[i]=jc[i-1]*i%M;}
	inv[200000]=ksm(jc[200000],M-2);
	for(i=199999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);a[i]+=a[i-1];
	}
	for(i=1;i<=n;i++){
		if(a[i]+i<=m){res++;continue;}
		if(a[i]==m){res+=ksm(ksm(2,i),M-2);continue;}
		if(a[i]>m){break;}
		k=m-a[i];
		if(!r){
			r=k;
			for(j=0;j<=k;j++){sum=(sum+c(i,j))%M;}
			res+=sum*ksm(ksm(2,i),M-2)%M;continue;
		}
		while(r>k){
			sum=(M-c(i-1,r)%M+sum)%M;r--;
		}
		sum=(sum*2-c(i-1,r))%M;
		res+=sum*ksm(ksm(2,i),M-2)%M;
	}
	printf("%lld",res%M);
}