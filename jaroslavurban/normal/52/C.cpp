#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// query: range min / max
// update: range addition
#define NEUTRAL_DIFF ll(1e18)
#define NEUTRAL_SAME 0 
#define COMBINE_DIFF(a, b) min(a, b) // combining 2 different nodes
#define COMBINE_SAME(a, b) ((a) + (b)) // comb. 2 of the same node (b is the newer)
#define L(a) (2*a)
#define R(a) (2*a+1)
#define OUT (l>=rb || r<=lb)
#define IN (l<=lb && r>=rb)
template<class T>
struct segtree{
	int logN, N;
	vector<T> tree, lazy;
	segtree(vector<T> &a){
		N = a.size();
		logN = pow(2, ceil(log2(N)));
		tree.assign(2*logN, NEUTRAL_DIFF); // value for outside nodes
		lazy.assign(2*logN, NEUTRAL_SAME); // value for inside nodes also
		for (int i = 0; i < N; i++) tree[i + logN] = a[i];
		for (int i = logN - 1; i > 0; i--) tree[i] = COMBINE_DIFF(tree[L(i)], tree[R(i)]);
	}
	void applyLazy(int idx){
		if(lazy[idx] != NEUTRAL_SAME){ // you need this, I swear
			tree[idx] = COMBINE_SAME(tree[idx], lazy[idx]);
			lazy[L(idx)] = COMBINE_SAME(lazy[L(idx)], lazy[idx]);
			lazy[R(idx)] = COMBINE_SAME(lazy[R(idx)], lazy[idx]);
			lazy[idx] = NEUTRAL_SAME;
		}
	}
	T query(int l, int r) { return query(l, r, 0, logN, 1); }
	T query(int l, int r, int lb, int rb, int idx){
		if (OUT) return NEUTRAL_DIFF;
		if (IN) return COMBINE_SAME(tree[idx], lazy[idx]);
		applyLazy(idx);
		int mid = (lb + rb) / 2;
		return COMBINE_DIFF(query(l, r, lb, mid, L(idx)), query(l, r, mid, rb, R(idx)));
	}
	T update(int l, int r, int val) { return update(l, r, 0, logN, 1, val); }
	T update(int l, int r, int lb, int rb, int idx, int val){
		if (OUT) return COMBINE_SAME(tree[idx], lazy[idx]);
		if (IN) return COMBINE_SAME(tree[idx], lazy[idx] = COMBINE_SAME(lazy[idx], val));
		applyLazy(idx);
		int mid = (lb + rb) / 2;
		return tree[idx] = COMBINE_DIFF(update(l, r, lb, mid, L(idx), val),
																		update(l, r, mid, rb, R(idx), val));
	}
};

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	segtree<ll>st(a);
	char c;int q;cin>>q>>noskipws>>c;
	while(q--){
		string s;getline(cin,s);
		stringstream ss(s);
		int l,r,v;
		if(ss>>l>>r>>v){
			if(l<=r)st.update(l,r+1,v);
			else{
				st.update(0,r+1,v);
				st.update(l,n,v);
			}
		}
		else {
			if(l<=r)cout<<st.query(l,r+1)<<endl;
			else cout<<COMBINE_DIFF(st.query(0,r+1),st.query(l,n))<<endl;
		}
//		for(int i=0;i<3;++i)cout<<st.query(i,i+1)<<" ";cerr<<" <--- "<<endl;
	}
}