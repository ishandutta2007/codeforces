#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

#define NEUTRAL -922337203685477580
#define NEUTRAL_LAZY 0
#define COMBINE(a, b) (max(a, b))
#define L(a) (2*a)
#define R(a) (2*a+1)
#define OUT (l>=rb || r<=lb)
#define LEAF (idx>=POW)
#define FULL (l<=lb && r>=rb)
struct segmentTree{
    ll POW, N;
    vector<ll> tree, lazy;
    segmentTree(vector<ll> &v){
        N = v.size();
        POW = pow(2, ceil(log2(N)));
        tree.assign(2*POW, NEUTRAL);
        lazy.assign(2*POW, NEUTRAL_LAZY);
        for (ll i = 0; i < N; i++) tree[i + POW] = v[i];
        for (ll i = POW - 1; i > 0; i--) tree[i] = COMBINE(tree[L(i)], tree[R(i)]);
    }
    ll realVal(ll idx) { return tree[idx] + lazy[idx]; }
    void applyLazy(ll idx){
        if (lazy[idx] != NEUTRAL_LAZY){
            tree[idx] = realVal(idx);
            lazy[L(idx)] += lazy[idx];
            lazy[R(idx)] += lazy[idx];
            lazy[idx] = NEUTRAL_LAZY;
        }
    }
    ll query(ll l, ll r) { return query(l, r, 0, POW, 1); }
    ll query(ll l, ll r, ll lb, ll rb, ll idx){
        if (OUT) return NEUTRAL;
        if (LEAF) return realVal(idx);
        if (FULL) return realVal(idx);
        applyLazy(idx);
        ll mid = (lb + rb) / 2;
        return COMBINE(query(l, r, lb, mid, L(idx)), query(l, r, mid, rb, R(idx)));
    }
    void update(ll l, ll r, ll val) { update(l, r, 0, POW, 1, val); }
    void update(ll l, ll r, ll lb, ll rb, ll idx, ll val){
        if (OUT) return;
        if (LEAF) { lazy[idx] += val; return; }
        if (FULL) { lazy[idx] += val; return; }
        applyLazy(idx);
        ll mid = (lb + rb) / 2;
        update(l, r, lb, mid, L(idx), val);
        update(l, r, mid, rb, R(idx), val);
        tree[idx] = COMBINE(realVal(L(idx)), realVal(R(idx)));
    }
};

const int N=200010;
int n,k,m;
set<pair<int,int>>f;
map<int,int>idxs;
main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>n>>k>>m;
	vector<ll>tmp(2*n);
	for(int i=0;i<2*n;++i)tmp[i]=i+1-n;
	segmentTree st(tmp);
	for(int i=0;i<m;++i){
		int x,y;cin>>x>>y;
		int idx=y+abs(x-k)-1;
		if(f.count({x,y})){
			f.erase({x,y});
			if(--idxs[idx]==0)idxs.erase(idx);
			st.update(0,idx,-1);
		}
		else{
			f.insert({x,y});
			++idxs[idx];
			st.update(0,idx,+1);
		}
//		for(int i=0;i<2*n;++i)cerr<<st.tree[i+st.POW]<<" ";
//		cerr<<endl;
//		for(int i=0;i<2*n;++i)cerr<<st.lazy[i+st.POW]<<" ";
//		cerr<<endl;
//		for(int i=0;i<2*n;++i)cerr<<st.query(i,i+1)<<" ";
//		cerr<<endl;
		int res=0;
		if(!idxs.empty())res=st.query(0,idxs.rbegin()->first+1);
		cout<<max(0,res)<<endl;
	}
}