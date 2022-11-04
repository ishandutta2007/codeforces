#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// currently doing:
// query: sum
// update: add
// change it yourself big boy
template<class T>
struct SegmentTree{
	int N,logN;
	vector<T>tree,lazy;
	SegmentTree(vector<T>a=vector<T>(200100)):N(a.size()),logN(pow(2,ceil(log2(N)))){
		tree.assign(2*logN,0); // c
		lazy.assign(2*logN,0); // c
		for(int i=0;i<N;++i)tree[i+logN]=a[i];
		for(int i=logN-1;i>0;--i)tree[i]=tree[2*i]+tree[2*i+1]; // c
	}
	void applylazy(int idx,int lb,int rb){
		if(lazy[idx]!=0){ // c
			tree[idx]=tree[idx]+lazy[idx]*(rb-lb); // c
			lazy[2*idx]=lazy[2*idx]+lazy[idx]; // c
			lazy[2*idx+1]=lazy[2*idx+1]+lazy[idx]; // c
			lazy[idx]=0; // c
		}
	}
	T query(int l,int r){return query(l,r,0,logN,1);}
	T query(int l,int r,int lb,int rb,int idx){
		if(rb<=l||r<=lb)return 0; // c
		if(l<=lb&&rb<=r)return tree[idx]+lazy[idx]*(rb-lb); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return query(l,r,lb,mid,2*idx)+query(l,r,mid,rb,2*idx+1); // c
	}
	T update(int l,int r,T val){return update(l,r,0,logN,1,val);}
	T update(int l,int r,int lb,int rb,int idx,T val){
		if(rb<=l||r<=lb)return tree[idx]+lazy[idx]*(rb-lb); // c
		if(l<=lb&&rb<=r)return tree[idx]+(lazy[idx]+=val)*(rb-lb); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return tree[idx]=update(l,r,lb,mid,2*idx,val)+update(l,r,mid,rb,2*idx+1,val); // c
	}
};

const int N=200100;
SegmentTree<ll>ones;
int asked[N];
int n,t;

int query(int r){
	if(!asked[r]){
		asked[r]=1;
		cout<<"? 1 "<<r+1<<endl;
		int res;cin>>res;
		ones.update(r,r+1,res-ones.query(r,r+1));
	}
	return ones.query(r,r+1);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>t;
	while(t--){
		int k;cin>>k;
		int l=0,r=n;
		while(l<r){
			int m=(l+r)/2;
			if(m+1-query(m)<k)l=m+1;
			else r=m;
		}
		cout<<"! "<<l+1<<endl;
		ones.update(l,N,1);
	}
}