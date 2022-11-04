#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

#define mod 1000000007

ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powmod(a*a%mod,b/2)*a%mod;
	return powmod(a*a%mod,b/2);
}

int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		ll n,p;cin>>n>>p;
		vector<ll>nums(n);
		for(int i=0;i<n;++i)cin>>nums[i];
		if(p==1){
			cout<<n%2<<endl;
			continue;
		}
		sort(nums.begin(),nums.end());
		reverse(nums.begin(),nums.end());
		vector<ll>one,two;
		ll bigidx=0;
		while(1){
			if(bigidx>=n)break;
			one.push_back(nums[bigidx]);
			ll smallidx=bigidx+1;
			ll nwant=1,ofsz=nums[bigidx];
			while(nwant>0&&smallidx<n){
				for(int i=0;i<ofsz-nums[smallidx]&&nwant<n*n+100;++i)nwant*=p;
				ofsz=nums[smallidx];
				two.push_back(nums[smallidx]);
				--nwant;
				++smallidx;
			}
			bigidx=smallidx;
		}
		ll sm=0;
		for(auto num:one)sm=(sm+powmod(p,num))%mod;
		for(auto num:two)sm=(sm+mod-powmod(p,num))%mod;
		cout<<sm<<endl;
	}
}