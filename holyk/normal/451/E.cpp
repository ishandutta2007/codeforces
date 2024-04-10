#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
template<typename T>
inline void rd(T&w){char c;
	while(!isdigit(c=getchar()));w=c&15;
	while(isdigit(c=getchar()))w=(w<<1)+(w<<3)+(c&15);
}
const int M=1e9+7;
int n;
ll r,sum,k,a[22],inv[22];
inline ll comb(ll n,ll m){
	if(m>n)return 0;
	ll ans=1;
	for(ll i=n-m+1;i<=n;++i)ans=i%M*ans%M;
	return ans*inv[m]%M;
}
int main(){
	rd(n),rd(r);
	inv[0]=inv[1]=1;
	REP(j,2,n)inv[j]=(M-M/j)*inv[M%j]%M;
	REP(j,2,n)inv[j]=inv[j]*inv[j-1]%M;
	REP(i,1,n)rd(a[i]);
	int st=(1<<n)-1;
	ll ans=0;
	REP(i,0,st){
		int m=0;ll t=0;
		REP(j,1,n)if(i>>j-1&1)m^=1,t+=a[j]+1;
		if(m)ans=(ans-comb(n+r-1-t,n-1)+M)%M;
		else ans=(ans+comb(n+r-1-t,n-1))%M;
	}
	cout<<ans;
	return 0;
}