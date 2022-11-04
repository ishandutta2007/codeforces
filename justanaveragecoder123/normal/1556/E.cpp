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


struct segtree {
	struct node {
		ll mn_prefix = 1e9;
		ll mx_prefix = -1e9;
		ll sum = 0;
		
		node() {}
		node(ll a) : mn_prefix(a), mx_prefix(a), sum(a) {}

		node operator+(const node& b) {
			node res;
			res.mn_prefix=min(mn_prefix, sum+b.mn_prefix);
			res.mx_prefix=max(mx_prefix, sum+b.mx_prefix);
			res.sum=sum+b.sum;
			return res;
		} 
	};

	

	inline void pull(int ind, int L, int R) {
		tree[ind]=tree[2*ind]+tree[2*ind+1];
	}

	int n;
	vector<node> tree;
	
	segtree(int n) : n(n) {
		tree.resize(4*n, node{});
	}
	
	void build(int ind, int L, int R, const vector<ll>& arr) {
		if(L==R) {
			tree[ind]=node(arr[L]);
		}else { 
			build(2*ind, L, (L+R)/2, arr);
			build(2*ind+1, (L+R)/2+1, R, arr);
			
			pull(ind, L, R);
			//~ LOG(ind);
			//~ LOG(tree[ind].sum);
			//~ LOG(tree[2*ind].sum);
			//~ LOG(tree[2*ind+1].sum);
		}
	}

	node query(int i, int j) {
		return query(1, 0, n-1, i, j);
	}
		
	node query(int ind, int L, int R, int i, int j) {
		if(R<i||j<L) return node{};
		
		if(i<=L && R<=j) {
			return tree[ind];
		}
		
		return query(2*ind, L, (L+R)/2, i, j)+query(2*ind+1, (L+R)/2+1, R, i, j);
	}

};

int main() {
	IO;
	int n,q;
	cin>>n>>q;
	vector<ll> a(n), b(n), c(n);
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) cin>>b[i];
	
	for(int i=0;i<n;++i) {
		c[i]=b[i]-a[i];
		//~ LOG(c[i]);
	}
	
	segtree st(n);
	st.build(1,0,n-1,c);
	
	//~ LOG(st.query(0,n-1).sum);
	//~ LOG(st.query(0,0).sum);
	//~ LOG(st.query(0,1).sum);
	//~ LOG(st.query(1,1).sum);
	//~ LOG(st.query(2,2).sum);
	//~ LOG(st.query(3,3).sum);
	
	for(int i=0;i<q;++i) {
		int l,r;
		cin>>l>>r;
		//~ LOG(l);
		//~ LOG(r);
		segtree::node res=st.query(l-1,r-1);
		//~ cerr<<res.sum<<" "<<res.mn_prefix<<" "<<res.mx_prefix<<"\n";
		if(res.mn_prefix<0 || res.sum!=0) cout<<"-1\n";
		else {
			cout<<res.mx_prefix<<"\n";
		}
	}

	
	return 0;
}