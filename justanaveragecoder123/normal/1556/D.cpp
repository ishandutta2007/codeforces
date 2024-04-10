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

vector<int> seq={1,6,4,2,3,5,4};
int opsc=0;

int query(int typ, int x, int y) {
	const string ops[2]={"and", "or"};
	cout<<ops[typ]<<" "<<x<<" "<<y<<"\n"<<flush;
	
	#ifdef LOCAL
	opsc++;
	if(typ==0) {
		return seq[x-1]&seq[y-1];
	}
	return seq[x-1]|seq[y-1];
	#else
	int res;
	cin>>res;
	return res;
	#endif
}

array<ll,3> solve() {
	array<ll,3> sums;
	sums[0]=query(0, 1,2)+query(1, 1,2);
	sums[1]=query(0, 2,3)+query(1, 2,3);
	sums[2]=query(0, 3,1)+query(1, 3,1);
	
	ll sum=(sums[0]+sums[1]+sums[2])/2;

	return {sum-sums[1], sum-sums[2], sum-sums[0]};
}

int main() {
	IO;
	int n,k;
	cin>>n>>k;
	
	array<ll,3> s=solve();
	
	vector<ll> ans(n+1);
	ans[1]=s[0];
	ans[2]=s[1];
	ans[3]=s[2];
	
	for(int i=4;i<=n;++i) {
		ll ss=query(0,1,i)+query(1,1,i);
		ans[i]=ss-ans[1];
	}
	
	sort(ans.begin(), ans.end());
	cout<<"finish "<<ans[k]<<"\n";
	
	//~ for(auto i:ans) cerr<<i<<" ";cerr<<"\n";
	
	assert(opsc<=2*n);
	
	return 0;
}