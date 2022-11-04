#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// currently doing:
// query: max
// update: add
// change it yourself big boy
template<class T>
struct MaxSegmentTree{
	int N,logN;
	vector<T>tree,lazy;
	MaxSegmentTree(vector<T>a):N(a.size()),logN(pow(2,ceil(log2(N)))){
		tree.assign(2*logN,-1e9); // c
		lazy.assign(2*logN,0); // c
		for(int i=0;i<N;++i)tree[i+logN]=a[i];
		for(int i=logN-1;i>0;--i)tree[i]=max(tree[2*i],tree[2*i+1]); // c
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
		if(rb<=l||r<=lb)return -1e9; // c
		if(l<=lb&&rb<=r)return tree[idx]+lazy[idx]; // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return max(query(l,r,lb,mid,2*idx),query(l,r,mid,rb,2*idx+1)); // c
	}
	T update(int l,int r,T val){return update(l,r,0,logN,1,val);}
	T update(int l,int r,int lb,int rb,int idx,T val){
		if(rb<=l||r<=lb)return tree[idx]+lazy[idx]; // c
		if(l<=lb&&rb<=r)return tree[idx]+(lazy[idx]+=val); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return tree[idx]=max(update(l,r,lb,mid,2*idx,val),update(l,r,mid,rb,2*idx+1,val));
	}
};

template<class T>
struct MinSegmentTree{
	int N,logN;
	vector<T>tree,lazy;
	MinSegmentTree(vector<T>a):N(a.size()),logN(pow(2,ceil(log2(N)))){
		tree.assign(2*logN,+1e9); // c
		lazy.assign(2*logN,0); // c
		for(int i=0;i<N;++i)tree[i+logN]=a[i];
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
		if(rb<=l||r<=lb)return +1e9; // c
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



void ProGamerMove(){
	int n;cin>>n;
	map<int,vector<int>>pos;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		pos[a].push_back(i);
	}
	vector<int>tmp(n);
	iota(tmp.begin(),tmp.end(),1);
	MinSegmentTree<int>mn(tmp);
	MaxSegmentTree<int>mx(tmp);
	vector<ll>res(n);
	auto update=[&](int idx,int val){
		mn.update(idx,n,2*val);
		mx.update(idx,n,2*val);
	};
	auto check=[&](int idx){
		ll lftmn=0,lftmx=0,rghtmn=0,rghtmx=0;
		if(idx){
			ll totsmlft=idx?mn.query(idx-1,idx):0;
			// min left
			ll mxpref=max(0,mx.query(0,idx));
			lftmn=totsmlft-mxpref;
			// max left
			ll mnpref=min(0,mn.query(0,idx));
			lftmx=totsmlft-mnpref;
		}
		if(idx+1!=n){
			ll subtr=mn.query(idx,idx+1);
			// min right
			rghtmn=min(0ll,mn.query(idx+1,n)-subtr);
			// max right
			rghtmx=max(0ll,mx.query(idx+1,n)-subtr);
		}
		ll mncheck=lftmn+rghtmn;
		ll mnmid=(abs(mncheck)+1)/2;
		res[idx]=max(res[idx],abs(mncheck)-mnmid);
		ll mxcheck=lftmx+rghtmx;
		ll mxmid=(abs(mxcheck)+1)/2;
		res[idx]=max(res[idx],mxmid);
	};
	for(auto&[num,idxs]:pos){
		for(int idx:idxs){
			check(idx);
		}
		for(int idx:idxs){
			update(idx,-1);
		}
		for(int idx:idxs){
			check(idx);
		}
	}
	for(auto r:res)cout<<r<<" ";cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}