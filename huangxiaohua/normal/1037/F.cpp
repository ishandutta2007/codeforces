#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k;
ll res,n,m,tmp;

set<ll> s;
vector<pair<ll,ll> >v;

ll get(ll x){
	ll y=x/(m-1);
	return ((x-(m-1))+(x-(m-1)*y))*y/2;
}

int main(){
	scanf("%lld%lld",&n,&m);
	s.insert(0);s.insert(n+1);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		v.push_back({-k,i});
	}
	sort(v.begin(),v.end());
	for(auto [i,j]:v){
		i=-i;
		auto l=s.upper_bound(j),r=l;
		l--;
		tmp=get((*r)-(*l)-1);
		tmp-=get((*r)-j-1);
		tmp-=get(j-(*l)-1);
		tmp%=M;
		res+=i*tmp;res%=M;
		s.insert(j);
	}
	printf("%lld",res);
}