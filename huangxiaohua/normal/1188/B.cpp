#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll,ll> mp;
ll M,t,m,res,sb;

int main(){
	scanf("%lld%lld%lld",&t,&M,&m);
	while(t--){
		scanf("%lld",&sb);
		sb=(sb*sb%M*sb%M*sb%M-m*sb%M+M)%M;
		res+=mp[sb];mp[sb]++;
	}
	printf("%lld",res);
}