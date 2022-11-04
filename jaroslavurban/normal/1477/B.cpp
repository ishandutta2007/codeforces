#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

// currently doing:
// query: sum
// update: set
// change it yourself big boy
template<class T>
struct SegmentTree{
	int N,logN;
	vector<T>tree,lazy;
	SegmentTree(vector<T>a):N(a.size()),logN(pow(2,ceil(log2(N)))){
		tree.assign(2*logN,0); // c
		lazy.assign(2*logN,-1); // c
		for(int i=0;i<N;++i)tree[i+logN]=a[i];
		for(int i=logN-1;i>0;--i)tree[i]=tree[2*i]+tree[2*i+1]; // c
	}
	void applylazy(int idx,int lb,int rb){
		if(lazy[idx]!=-1){ // c
			tree[idx]=lazy[idx]*(rb-lb); // c
			lazy[2*idx]=lazy[idx]; // c
			lazy[2*idx+1]=lazy[idx]; // c
			lazy[idx]=-1; // c
		}
	}
	T query(int l,int r){return query(l,r,0,logN,1);}
	T query(int l,int r,int lb,int rb,int idx){
		if(rb<=l||r<=lb)return 0; // c
		if(l<=lb&&rb<=r)return (~lazy[idx]?lazy[idx]*(rb-lb):tree[idx]); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return query(l,r,lb,mid,2*idx)+query(l,r,mid,rb,2*idx+1); // c
	}
	T update(int l,int r,T val){return update(l,r,0,logN,1,val);}
	T update(int l,int r,int lb,int rb,int idx,T val){
		if(rb<=l||r<=lb)return (~lazy[idx]?lazy[idx]*(rb-lb):tree[idx]); // c
		if(l<=lb&&rb<=r)return (lazy[idx]=val)*(rb-lb); // c
		applylazy(idx,lb,rb);
		int mid=(lb+rb)/2;
		return tree[idx]=update(l,r,lb,mid,2*idx,val)+update(l,r,mid,rb,2*idx+1,val); // c
	}
};

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,q;cin>>n>>q;
		string s,f;cin>>s>>f;
		vector<int>tmp(n);
		for(int i=0;i<n;++i)tmp[i]=f[i]=='1';
		SegmentTree<int>st(tmp);
		bool pos=true;
		vector<pair<int,int>>qs(q);
		for(int i=0;i<q;++i)cin>>qs[i].first>>qs[i].second;
		for(int i=q-1;i>=0;--i){
			--qs[i].first;
			int len=qs[i].second-qs[i].first;
			int sm=st.query(qs[i].first,qs[i].second);
			if(2*sm==len){pos=false;break;}
			st.update(qs[i].first,qs[i].second,2*sm>len);
		}
		for(int i=0;i<n;++i)if(st.query(i,i+1)!=(s[i]=='1'))pos=false;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}