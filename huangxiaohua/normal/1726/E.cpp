#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,sb[100500];
ll jc[1005000],inv[1005000],g[1005000],jc2[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main() {
	jc[0]=jc2[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	for(i=1;i<=1000000;i++){
		jc2[i]=jc2[i-1];
		if(i&1)jc2[i]=jc2[i]*i%M;
	}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	g[1]=g[0]=1;
	for(i=2;i<=300000;i++){
		g[i]=su(g[i-1],(i-1)*g[i-2]%M);
	}
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll res=0,t1;
		for(i=0;i<=n;i+=2){
			if(n-i-i<0)break;
			t1=c(n-i,i)*ksm(2,i/2)%M*g[n-i*2]%M*jc2[i]%M;
			res=su(res,t1);
		}
		cout<<res<<'\n';
	}
}//