#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

using ll = long long;
using ull = unsigned long long ;
using ld = long double ;
using str = string;
using ordered_set=tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)


ll bk[200101];
ll sum[200101];
const ll mod=998244353;

int main() {
	IO;
	int n;
	cin>>n;
	vector<int> x(n), y(n), s(n);
	vector<pair<int,int>> ord;
	for(int i=0;i<n;++i) {
		cin>>x[i]>>y[i]>>s[i];
		ord.push_back({x[i], i});
	} 
	
	bk[0]=x[0]-y[0];
	sum[0]=bk[0];
	for(int i=1;i<n;++i) {
		bk[i]=x[i]-y[i];
		
		auto it=lower_bound(all(ord), mp(y[i], 0));
		if(it->yy!=i) {
			bk[i]=(bk[i]+sum[i-1]-(it->yy?sum[it->yy-1]:0));
		}
		
		sum[i]=(sum[i-1]+bk[i])%mod;
		//~ for(int j=0;j<n;++j) {
			//~ if(y[i]<x[j] && x[j]<x[i]) bk[i]=(bk[i]+bk[j])%mod;
		//~ }
	}
	
	ll ans=1;
	ll bef=0;
	for(int i=0;i<n;++i) {
		ans=(ans+x[i]-bef)%mod;
		if(s[i]) {
			ans=(ans+bk[i])%mod;
		}
		bef=x[i];
	}
	
	if(ans<0) ans+=mod;
	cout<<ans<<"\n";
	return 0;
}