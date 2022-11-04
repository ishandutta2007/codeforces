#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<int>prime;
vector<int>erat(int n){ // exclusive
	prime.resize(n);
	vector<int>res;
	for(int i=2;i<n;++i)if(!prime[i]){
		res.push_back(i);
		for(int j=i;j<n;j+=i)prime[j]=i;
	}
	return res;
}
unordered_map<int,int>factorize(int x){
	unordered_map<int,int>res;
	while(x!=1){
		++res[prime[x]];
		x/=prime[x];
	}
	return res;
}

const int mod=1e9+7;
vector<ll>nums;

ll cntdivs(ll num, ll n){
	return n/num;
}

void ProGamerMove(){
	ll n;cin>>n;
	ll res=0;
	for(int i=nums.size()-2;i>=0;--i){
//		cerr<<nums[i]<<endl;
		res=(res+(i+2)*(cntdivs(nums[i],n)-cntdivs(nums[i+1],n))%mod)%mod;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	erat(1e6);
	nums.push_back(1);
	unordered_map<int,int>amp;
	ll cn=1;
	for(int i=2;cn<=1e17;++i){
		auto mp=factorize(i);
		ll add=1;
		for(auto[key,cnt]:mp){
			add*=pow(key,max(0,cnt-amp[key]));
			amp[key]+=max(0,cnt-amp[key]);
		}
		cn*=add;
		nums.push_back(cn);
	}
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}