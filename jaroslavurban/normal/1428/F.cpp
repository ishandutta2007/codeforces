#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500100,inf=1e7;
int n;
string s;
// query: range min / max
// update: range addition

// if doing set as update, use ((b)==NEUTRAL_SAME?(a):(b))
// if doing addition as update, use (rb-lb)*val in update IN and /2 in applyLazy

#define NEUTRAL_DIFF 0 // the values will never be this extreme
#define NEUTRAL_SAME 0  // I will never update the tree with this
#define COMBINE_DIFF(a, b) ((a)+(b)) // combining 2 different nodes
#define COMBINE_SAME(a, b) ((a)+(b)) // comb. 2 of the same node (b is the newer)
#define L(a) (2*a)
#define R(a) (2*a+1)
#define OUT (l>=rb || r<=lb)
#define IN (l<=lb && r>=rb)
template<class T>
struct segtree{
	int logN, N;
	vector<T> tree, lazy;
	segtree(vector<T>a){
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
			lazy[L(idx)] = COMBINE_SAME(lazy[L(idx)], lazy[idx]/2);
			lazy[R(idx)] = COMBINE_SAME(lazy[R(idx)], lazy[idx]/2);
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
	T update(int l, int r, T val) { return update(l, r, 0, logN, 1, val); }
	T update(int l, int r, int lb, int rb, int idx, T val){
		if (OUT) return COMBINE_SAME(tree[idx], lazy[idx]);
		if (IN)	{
			lazy[idx] = COMBINE_SAME(lazy[idx], (rb-lb)*val);
			return COMBINE_SAME(tree[idx], lazy[idx]);
		}
		applyLazy(idx);
		int mid = (lb + rb) / 2;
		return tree[idx] = COMBINE_DIFF(update(l, r, lb, mid, L(idx), val),
																		update(l, r, mid, rb, R(idx), val));
	}
};
segtree<ll>st(vector<ll>(N,0));

int gp(ll fnd,int mx){
	int l=0,r=mx;
	while(l<r){
		int m=(l+r)/2;
		if(st.query(m,m+1)<=fnd)r=m;
		else l=m+1;
	}
	return l;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>s;
	ll cur=0,res=0;
	for(int i=0;i<n;++i){
		if(s[i]=='1')st.update(gp(cur++,i+1),i+1,1);
		else cur=0;
		res+=st.query(0,i+1);
	}
	cout<<res<<endl;
}