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


struct segtree {
	struct node {
		ll dp[4][4]; //mincost of from -> to
		
		node() {
			for(auto& i:dp) 
				for(auto& j:i)
					j=1000000ll;
		}
		node(char c) {
			for(auto& i:dp) 
				for(auto& j:i)
					j=1000000ll;
					
			if(c=='a') {
				dp[0][0]=1;
				dp[0][1]=0;
				
				dp[1][1]=0;
				dp[1][2]=1;
				
				dp[2][2]=0;
				dp[2][3]=1;
				
				dp[3][3]=0;
			}else if(c=='b') {
				dp[0][0]=0;
				dp[0][1]=1;
				
				dp[1][1]=1;
				dp[1][2]=0;
				
				dp[2][2]=0;
				dp[2][3]=1;
				
				dp[3][3]=0;
			}else if(c=='c') {
				dp[0][0]=0;
				dp[0][1]=1;
				
				dp[1][1]=0;
				dp[1][2]=1;
				
				dp[2][2]=1;
				dp[2][3]=0;
				
				dp[3][3]=0;
			}
		}		

		node operator+(const node& b) {
			node res;
			for(int i=0;i<4;++i) {
				for(int j=i;j<4;++j) {
					for(int k=j;k<4;++k) {
						res.dp[i][k]=min(res.dp[i][k], dp[i][j]+b.dp[j][k]);
					}
				}
			}
			
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
	
	void build() {
		build(1, 0, n-1);
	}
	
	void build(int ind, int L, int R, const vector<char>& arr) {
		if(L==R) {
			tree[ind]=node(arr[L]);
		}else { 
			build(2*ind, L, (L+R)/2, arr);
			build(2*ind+1, (L+R)/2+1, R, arr);
			
			pull(ind, L, R);
		}
	}

	void build(int ind, int L, int R) {
		if(L!=R) { 
			build(2*ind, L, (L+R)/2);
			build(2*ind+1, (L+R)/2+1, R);
			
			pull(ind, L, R);
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
	
	void change(int ind, int L, int R, int i, char to) {
		if(R<i||i<L) return ;
		if(L==R) {
			tree[ind]=node(to);
			return ;
		}
		
		change(2*ind, L, (L+R)/2, i, to);
		change(2*ind+1, (L+R)/2+1, R, i, to);
		
		pull(ind, L, R);
	}
};

int main() {
	IO;
	int n,q;
	cin>>n>>q;
	vector<char> t(n);
	for(int i=0;i<n;++i) cin>>t[i];
	
	segtree st(n);
	st.build(1, 0, n-1, t);
	
	for(int i=0;i<q;++i) {
		int ind;
		char c;
		cin>>ind>>c;
		ind--;
		st.change(1, 0, n-1, ind, c);
		t[ind]=c;
		
		//~ string s(t.begin(), t.end());
		//~ cerr<<s<<"\n";
		
		cout<<min(st.tree[1].dp[0][0], min(st.tree[1].dp[0][1], st.tree[1].dp[0][2]))<<"\n";
	}
	
	return 0;
}