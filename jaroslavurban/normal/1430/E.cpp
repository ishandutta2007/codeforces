#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// query: range min / max
// update: range addition

// if doing set as update, use ((b)==NEUTRAL_SAME?(a):(b))
// I think it should work
const ll N=200100,M=3030,inf=1e18;

#define NEUTRAL_DIFF inf // the values will never be this extreme
#define NEUTRAL_SAME 0  // I will never update the tree with this
#define COMBINE_DIFF(a, b) min((a), (b)) // combining 2 different nodes
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
int n;
string s;
vector<int>last[M];
int dest[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>s;
	vector<ll>tmp(n);
	iota(tmp.begin(),tmp.end(),0);
	segtree<ll>st(tmp);
	for(int i=0;i<n;++i)last[s[i]].push_back(i);
	for(int i=0;i<n;++i)dest[n-i-1]=s[i];
	ll res=0;
	for(int i=n-1;i>=0;--i){
		int type=dest[i];
		int idx=last[type].back();last[type].pop_back();
		int ridx=st.query(idx,idx+1);
		assert(ridx<=i);
//		cerr<<char(dest[i])<<" "<<ridx<<" "<<i<<endl;
		res+=i-ridx;
		st.update(idx,n,-1);
	}
	cout<<res<<endl;
}