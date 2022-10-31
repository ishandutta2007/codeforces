#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,it,num;
ll jc[10050],inv[10050],sb,f[605],g[605];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

bool chk(ll x,ll y){
	ll t1=x*y,t2;
	t2=sqrt(t1);
	return ((t2*t2)==t1||(t2*t2+t2+t2+1)==t1||(t2*t2-t2-t2+1)==t1);
}

int main() {
	ios::sync_with_stdio(0);
	jc[0]=inv[0]=1;
	for(i=1;i<=10000;i++){jc[i]=jc[i-1]*i%M;}
	inv[10000]=ksm(jc[10000],M-2);
	for(i=9999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	cin>>n;
	map<ll,ll> mp;
	for(i=1;i<=n;i++){
		cin>>sb;
		for(auto [i,j]:mp){
			if(chk(i,sb)){
				mp[i]++;goto aaa;
			}
		}
		mp[sb]++;
		aaa:;
	}
	f[0]=1;
	num=0;
	for(auto [x,y]:mp){
		memset(g,0,sizeof(g));
		for(i=0;i<=num;i++){
			for(j=0;j<y;j++){
				g[i+j]=su(g[i+j],f[i]*c(y-1,j)%M*c(num-i+y-j,y-j)%M);
			}
		}
		memcpy(f,g,sizeof(g));
		num+=y;
	}
	ll res=0;
	for(i=num;i>=0;i--){
		if(i&1)res=su(res,M-f[i]);
		else res=su(res,f[i]);
	}
	for(auto [x,y]:mp)res=res*jc[y]%M;
	cout<<res;
}