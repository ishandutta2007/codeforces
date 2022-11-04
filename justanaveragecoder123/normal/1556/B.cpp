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

template<typename T>
struct fenwick {
	vector<T> arr;
	
	fenwick(size_t sz) {
		arr.assign(sz,0);
	}
	
	void incr(size_t x, T by) {
		for(;x<arr.size();x+=(x&(-x))) {
			arr[x]+=by;
		}
	} 
	
	T sum(T x) {
		T sum=0;
		for(;x>0;x-=(x&(-x))) {
			sum+=arr[x];
		}
		
		return sum;
	}
};


ll invs(vector<int> lst) {
	ll ans=0;
	fenwick<int> fw(sz(lst)+1);
	for(int i=0;i<sz(lst);++i) {
		ans+=i-fw.sum(lst[i]-1);
		fw.incr(lst[i], 1);
	}
	
	return ans;
}
	


int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> t(n);
		vector<int> cnt(2);
		
		vector<int> lst[2];
		
		for(int i=0;i<n;++i) {
			cin>>t[i];
			t[i]%=2;
			cnt[t[i]]++;
			lst[t[i]].pb(i);
		}
		
		if(min(cnt[0], cnt[1])+1<max(cnt[0], cnt[1])) {
			cout<<"-1\n";
			continue ;
		}
		
		auto gen=[&](int start) -> vector<int> {		
			vector<int> arr(n);
			vector<int> ind(2);
			int curr=start, num=1;
			while(ind[curr]<sz(lst[curr])) {
				arr[lst[curr][ind[curr]]]=num++;
				ind[curr]++;
				curr=1-curr;
			}
			
			return (num==n+1?arr:vector<int>(0));
		};
		
		ll ans=1LL<<60;
		
		{
			vector<int> arr=gen(0);
			//~ for(auto i:arr) cerr<<i<<" ";cerr<<"\n";
			if(sz(arr)>0) ans=min(ans, invs(arr));
		}
		
		{
			vector<int> arr=gen(1);
			//~ for(auto i:arr) cerr<<i<<" ";cerr<<"\n";
			//~ LOG(invs(arr));
			if(sz(arr)>0) ans=min(ans, invs(arr));
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}