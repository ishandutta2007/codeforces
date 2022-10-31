#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,f[5050],it,x,y,p[5050];
ll jc[10050],inv[10050],res,g[5050];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
char s[5050];

int main() {
	ios::sync_with_stdio(0);
	jc[0]=inv[0]=1;
	for(i=1;i<=10000;i++){jc[i]=jc[i-1]*i%M;}
	inv[10000]=ksm(jc[10000],M-2);
	for(i=9999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++){
		p[i]=p[i-1];
		if(s[i]=='1'){
			f[++it]=i;p[i]++;
		}
	}
	f[0]=0;f[it+1]=n+1;
	if(it<m||!m){cout<<1;return 0;}
	for(i=m;i<=it;i++){
		res=su(res,c(f[i+1]-f[i-m]-1,m));
		if(i!=it){
			res=su(res,M-c(f[i+1]-f[i-m+1]-1,m-1));
		}
	}
	cout<<res;
}