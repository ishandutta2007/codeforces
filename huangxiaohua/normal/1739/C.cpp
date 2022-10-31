#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t;
ll jc[1005000],inv[1005000],r1,r2,r3;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>t;
	while(t--){
		cin>>n;
		r1=0;
		for(i=0;i<=n;i+=4){
			r1+=c(n-i-1,n/2-i/2-1);
			r1%=M;
		}
		for(i=2;i<=n;i+=4){
			r1+=c(n-i-2,n/2-i/2-2);
			r1%=M;
		}
		r3=1;
		r2=(c(n,n/2)-r1-r3);
		r2=(r2%M+M)%M;
		cout<<r1<<' '<<r2<<' '<<r3<<'\n';
	}
	
}