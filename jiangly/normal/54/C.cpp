#include<bits/stdc++.h>
typedef long long ll;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	int read_int(){
		int ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	ll read_ll(){
		ll ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
namespace algo{
	template<class T>const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
}
using namespace algo;
const int MAXN=1000;
int n,k;
double dp[2][MAXN+1];
ll calc(ll l,ll r){
	ll ans=0;
	for(ll s=1,i=0;i!=19;++i,s*=10){
		ll t=(s<<1)-1;
		ans+=max(0ll,min(t,r)-max(s,l)+1);
	}
	return ans;
}
void solve(){
	n=read_int();
	int cur=0;
	dp[0][0]=1;
	for(int i=0;i<n;++i){
		cur^=1;
		ll l=read_ll(),r=read_ll();
		double p=1.0*calc(l,r)/(r-l+1);
		dp[cur][0]=dp[!cur][0]*(1-p);
		for(int j=1;j<=i+1;++j)
			dp[cur][j]=dp[!cur][j-1]*p+dp[!cur][j]*(1-p);
	}
	k=read_int();
	double ans=0;
	for(int i=n;i*100>=n*k;--i)
		ans+=dp[cur][i];
	printf("%.15lf\n",ans);
}
int main(){
	solve();
	return 0;
}