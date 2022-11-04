#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000100,mod=998244353;
int res[N],one[N];

// prime[i] = highest prime factor of i
vector<int>prime;
vector<int>erat(int n){ // exclusive
	prime.resize(n);
	vector<int>res;
	for(int i=2;i<n;++i)if(!prime[i]){
		res.push_back(i);
		// has to be retarded for vector<int>prime
		for(int j=i;j<n;j+=i)prime[j]=i;
	}
	return res;
}
ll divs(int x){
	unordered_map<int,int>res;
	while(x!=1){
		++res[prime[x]];
		x/=prime[x];
	}
	ll divs=1;
	for(auto[k,n]:res)divs=divs*(n+1)%mod;
	return divs;
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	erat(n+1);
	ll sm=0;
	for(int i=1;i<=n;++i){
		ll dv=divs(i);
		res[i]=(sm+dv)%mod;
		sm=(sm+res[i])%mod;
	}
	cout<<res[n]<<endl;
}