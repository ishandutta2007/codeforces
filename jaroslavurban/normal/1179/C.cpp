#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// query: range min / max
// update: range addition

// if doing set as update, use ((b)==NEUTRAL_SAME?(a):(b))
// I think it should work

const ll inf=1e18;
#define NEUTRAL_DIFF -inf
#define NEUTRAL_SAME 0 
#define COMBINE_DIFF(a, b) max((a), (b)) // combining 2 different nodes
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
		if (IN)	{
			lazy[idx] = COMBINE_SAME(lazy[idx], val);
			return COMBINE_SAME(tree[idx], lazy[idx]);
		}
		applyLazy(idx);
		int mid = (lb + rb) / 2;
		return tree[idx] = COMBINE_DIFF(update(l, r, lb, mid, L(idx), val),
																		update(l, r, mid, rb, R(idx), val));
	}
};

const int N=1000100;
int n,m;
int a[N],b[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	vector<ll>tmp(N);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<m;++i)cin>>b[i];
	for(int i=0;i<n;++i)++tmp[a[i]];
	for(int i=0;i<m;++i)--tmp[b[i]];
	for(int i=N-2;i>=0;--i)tmp[i]+=tmp[i+1];
	segtree<ll>st(tmp);
	int q;cin>>q;
	while(q--){
		int t,idx,x;cin>>t>>idx>>x;--idx;
		if(t==1){
			st.update(0,a[idx]+1,-1);
			a[idx]=x;
			st.update(0,a[idx]+1,+1);
		} else{
			st.update(0,b[idx]+1,+1);
			b[idx]=x;
			st.update(0,b[idx]+1,-1);
		}
		int l=0,r=N-1;
		while(l<r){
			int m=(l+r)/2;
			if(st.query(m,N)>0)l=m+1;
			else r=m;
		}
		assert(st.query(l,l+1)<=0);
		assert(!l||st.query(l-1,l)>0);
		cout<<l-1<<endl;
//		for(int i=0;i<11;++i)cerr<<st.query(i,i+1)<<" ";cerr<<endl;
	}
}