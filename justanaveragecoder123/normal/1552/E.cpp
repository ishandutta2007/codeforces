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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

struct dat {
	int xx,yy,ind;
};
int main() {
	IO;
	int n,k;
	cin>>n>>k;
	vector<int> c(n*k);
	
	for(int i=0;i<n*k;++i) {
		cin>>c[i];
	}
	
	#ifdef LOCAL
	for(int i=0;i<n*k;++i) {
		c[i]=i/k+1;
	}
	for(int i=0;i<n*k;++i ){
		swap(c[i], c[uniform_int_distribution<int>(0, n*k-1)(rng)]);
	}
	for(int i=0;i<n*k;++i) cerr<<c[i]<<" ";cerr<<"\n";

	//~ random_shuffle(c.begin(), c.end(), rng);
	#endif 
	
	vector<pair<int,int>> ans(n,mp(-1,-1));
	
	int mx=(n+k-2)/(k-1);
	vector<dat> st;
	for(int i=0;i<n*k;++i) {
		if(ans[c[i]-1].xx!=-1) continue ;
		
		int j;
		for(j=0;j<sz(st);++j) {
			if(st[j].xx==c[i]) {
				break ;
			}
		}
		
		if(j<sz(st)) {
			ans[c[i]-1]={st[j].ind, i};
			st.erase(st.begin()+j);
			for(auto& j:st) j.yy++;
			for(auto it=st.begin();it!=st.end();) {
				if(it->yy==mx) {
					it=st.erase(it);
				}else {
					it++;
				}
			}
		}else {
			st.pb({c[i], 0, i});
		}
	}
	
	for(auto i:ans) cout<<i.xx+1<<" "<<i.yy+1<<"\n";
	cout<<flush;
	#ifdef LOCAL
	for(int i=0;i<n;++i) 
		assert(ans[i].xx>=0 && ans[i].yy>=0);
	#endif 
	return 0;
}