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


int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<ll> a(n);
		vector<ll> b(n);
		for(int i=0;i<n;++i) {
			cin>>a[i];
		}
		for(int j=0;j<n;++j) {
			cin>>b[j];
		}
		
		sort(all(a));
		sort(all(b));
		
		int lg=ceil(log2(n))+3;
		int ans=-1;
		for(int i=lg;i>=0;i--) {
			int add=ans+(1<<i);
			vector<ll> A=a, B=b;
			reverse(all(B));
			for(int j=0;j<add;++j) {
				A.push_back(100);
				B.push_back(0);
			}
			reverse(all(B));
			
			int need=(add+n)-(add+n)/4;
			//~ LOG(need);
			ll sa=0,sb=0;
			for(int j=sz(A)-1;j>sz(A)-1-need;j--) {
				sa+=A[j];
				sb+=B[j];
			}
			
			if(sa<sb) ans=add;
		}
		cout<<ans+1<<"\n";
	}

	return 0;
}