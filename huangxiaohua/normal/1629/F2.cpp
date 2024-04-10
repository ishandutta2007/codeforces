#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define dev 500000004
int i,j,k,n,m,t,sb;
ll jc[1005000],inv[1005000],res,pre[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>t;
	while(t--){
		cin>>n>>m>>sb;
		if(n==m){
			cout<<1ll*sb*n%M<<'\n';
			continue;
		}
		res=0;
		for(i=1;i<=m;i++){
			res=su(res,ksm(dev,n-i)%M*i%M*c(n-1-i,m-i)%M);
		}
		cout<<res*sb%M<<'\n';
	}
}