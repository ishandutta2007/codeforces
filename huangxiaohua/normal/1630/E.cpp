#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,a[1005000],b[1005000],f[1005000],g[1005000];
ll jc[1005000],inv[1005000],res,sum,chu,sb,t1;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
vector<int> v;
ll get(ll x,ll y){
	ll ans=0;
	int i,j,k;
	sum=sum*ksm(c(n/x,y),M-2)%M;
	t1=n/x-y;
	for(i=1;i<=y;i++){
		ans=su(ans,c(y-1,i-1)*i%M*c(t1,i)%M*2%M);
		ans=su(ans,M-c(y-1,i-1)*i%M*c(t1-1,i)%M);
		if(i>1)ans=su(ans,c(y-1,i-1)*(i-1)%M*c(t1-1,i-2)%M);
	}
	ans=ans*sum%M*g[x]%M;
	sum=sum*c(n/x,y)%M;
	return ans;
}
void work(int x){
	sum=1;sb=n/x;
	int i,j,k;
	for(auto i:v)for(j=1;j<=b[i];j++){
		sum=sum*c(sb,i/x)%M;sb-=i/x;
	}
	chu=su(chu,sum*g[x]%M);
	for(auto i:v)res=su(res,get(x,i/x)*b[i]%M*x%M);
}
int main() {
	ios::sync_with_stdio(0);
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,n*4+50);
		memset(b,0,n*4+50);
		memset(g,0,n*4+50);
		for(i=1;i<=n;i++){
			cin>>k;a[k]++;
			g[n/__gcd(n,i)]++;
		}
		for(i=1;i<=n;i++)if(a[i])b[a[i]]++;
		if(b[n]){
			cout<<1<<'\n';continue;
		}
		v.clear();m=0;
		for(i=1;i<=n;i++)if(b[i]){
			v.push_back(i);m=__gcd(i,m);
		}
		res=sum=chu=0;
		for(i=1;i<=n;i++)if(!(m%i)){
			work(i);
		}
		res=res*ksm(chu,M-2)%M;
		cout<<res<<'\n';
	}//
}