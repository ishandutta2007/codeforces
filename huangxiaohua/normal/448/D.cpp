#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
#define b(x) (1ll<<((x)-1))

int i,j,k,t;
ll n,m,lim,res=2e18,l=1,r=1e12,md;

int main(){
	scanf("%lld%lld%lld",&n,&m,&lim);
	while(l<=r){
		md=(l+r)/2;
		ll sum=0;
		for(ll i=1;i<=n;i++){
			sum+=min(m,md/i);
		}
		if(sum>=lim)res=min(res,md),r=md-1;
		else l=md+1;
	}
	cout<<res;
}