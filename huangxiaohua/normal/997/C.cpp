#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,m,t;
ll sum,r1,r2,sum2,r3,r4,sb,res,n;
ll jc[1005000],inv[1005000],f[1005000];
ll ksm(ll a,ll p){
	ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;
}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>n;
	sum=ksm(3,n*n);
	r1=ksm(su(ksm(3,n),M-3),n);
	r2=su(sum,M-r1);
	res=(r2+r2)%M;
	for(i=1;i<=n;i++){
		sb=ksm(su(ksm(3,n-i),M-1),n);
		sb=su(ksm(3,n*(n-i)),M-sb);
		f[i]=c(n,i)*3%M*sb%M;
		if(i&1){
			res=su(res,M-f[i]);
		}
		else{
			res=su(res,f[i]);
		}
	}
	cout<<res;
}