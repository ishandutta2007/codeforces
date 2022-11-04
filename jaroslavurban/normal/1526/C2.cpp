#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// currently doing:
// query: max
// update: add
// change it yourself big boy
template<class T>
struct SegmentTree{
	int N,logN;
	vector<T>tree,lazy;
	SegmentTree(int n_):N(n_),logN(pow(2,ceil(log2(N)))){
		tree.assign(2*logN,1e18); // c
		lazy.assign(2*logN,0); // c
		for(int i=logN;i<logN+n_;++i)tree[i]=0;
		for(int i=logN-1;i>0;--i)tree[i]=min(tree[2*i],tree[2*i+1]); // c
	}
	void applylazy(int idx,int lb,int rb){
		if(lazy[idx]!=0){ // c
			tree[idx]=tree[idx]+lazy[idx]; // c
			lazy[2*idx]=lazy[2*idx]+lazy[idx]; // c
			lazy[2*idx+1]=lazy[2*idx+1]+lazy[idx]; // c
			lazy[idx]=0; // c
		}
	}
	T query(int l,int r){return query(l,r,0,logN,1);}
	T query(int l,int r,int lb,int rb,int idx){
		if(rb<=l||r<=lb)return 1e18; // c
		if(l<=lb&&rb<=r)return tree[idx]+lazy[idx]; // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return min(query(l,r,lb,mid,2*idx),query(l,r,mid,rb,2*idx+1)); // c
	}
	T update(int l,int r,T val){return update(l,r,0,logN,1,val);}
	T update(int l,int r,int lb,int rb,int idx,T val){
		if(rb<=l||r<=lb)return tree[idx]+lazy[idx]; // c
		if(l<=lb&&rb<=r)return tree[idx]+(lazy[idx]+=val); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return tree[idx]=min(update(l,r,lb,mid,2*idx,val),update(l,r,mid,rb,2*idx+1,val));
	}
};



signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	vector<pair<int,int>>negs;
	SegmentTree<ll>sg(n);
	int res=0;
	for(int i=0;i<n;++i){
		if(a[i]>=0){
			++res;
			sg.update(i,n,a[i]);
		}
		else negs.push_back({a[i],i});
	}
	sort(negs.rbegin(),negs.rend());
	for(auto[v,i]:negs){
		if(sg.query(i,n)>=-v){
			sg.update(i,n,v);
			++res;
		}
	}
	cout<<res<<"\n";
}