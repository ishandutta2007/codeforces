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
#define ins insert

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
struct dsu {
	vector<int> par;
	vector<int> sz;
	pair<set<pair<int,int>>, int> small, large;
	
	dsu(int n) : par(n,-1) {
		sz.assign(n,1);
		for(int i=0;i<n;++i) {
			add_to(small, make_pair(sz[i], i));
		}
	}
	
	void delete_from(pair<set<pair<int,int>>, int>& st, pair<int,int> val) {
		if(st.first.find(val)!=st.first.end()) {
			st.first.erase(val);
			st.second-=val.first;
		}
	}
	
	void add_to(pair<set<pair<int,int>>, int>& st, pair<int,int> val) {
		st.first.insert(val);
		st.second+=val.first;
	}
	
	
	int get(int x) {
		if(par[x]==-1) return x;
		return par[x]=get(par[x]);
	}
	
	bool merge(int x, int y) {
		int px=get(x), py=get(y);
		if(px==py) return false;
		
		if(sz[px]>sz[py]) {
			swap(px,py);
			swap(x,y); //:) lyft
		}
		
		delete_from(small, make_pair(sz[px], px));
		delete_from(large, make_pair(sz[px], px));
		
		delete_from(small, make_pair(sz[py], py));
		delete_from(large, make_pair(sz[py], py));
		
		sz[py]+=sz[px];
		par[px]=py;
		
		add_to(small, make_pair(sz[py], py));
		
		return true;
	}
	
	void fix(int cnt) {
		while(!small.xx.empty() && !large.xx.empty() && prev(small.xx.end())->first>large.xx.begin()->first) {
			auto val=*large.xx.begin();
			delete_from(large, val);
			add_to(small, val);
		}
		
		while(sz(large.xx)<cnt && !small.xx.empty()) {
			auto val=*prev(small.xx.end());
			delete_from(small, val);
			add_to(large, val);
		}
	}
};


int main() {
	IO;
	int n,m;
	cin>>n>>m;
	dsu d(n);
	int extra=0;
	for(int i=0;i<m;++i) {
		int a,b;
		cin>>a>>b;
		a--;b--;
		if(d.merge(a,b)) {

		}else {
			extra++;
		}
		//~ cerr<<a<<" "<<b<<" "<<extra<<"\n";
		d.fix(extra+1);
		
		cout<<min(n-1, d.large.yy-1)<<"\n";
		
	}
	
	
	return 0;
}