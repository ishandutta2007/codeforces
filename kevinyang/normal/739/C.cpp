#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 300005;
vector<int>arr(mxn);
vector<int>dif(mxn);//difs[i] = arr[i+1]-arr[i]
int n;
struct SegTree{
	int size;
	vector<int>pre;
	vector<int>suf;
	vector<int>seg;
	vector<int>lval;
	vector<int>rval;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		pre.assign(2*size,0LL);
		suf.assign(2*size,0LL);
		seg.assign(2*size,0LL);
		lval.assign(2*size,0LL);
		rval.assign(2*size,0LL);
	}
	void build(int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<n){
				int v = dif[lx];
				if(v!=0)v/=abs(v);
				lval[x] = rval[x] = v;
				if(lval[x]!=0){
					pre[x] = suf[x] = seg[x] = 1;
				}
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		seg[x] = max({seg[2*x+1],seg[2*x+2]});
		if(rval[2*x+1]<=lval[2*x+2])seg[x] = max(seg[x],suf[2*x+1]+pre[2*x+2]);
		pre[x] = pre[2*x+1];
		if(m-lx==pre[2*x+1]&&rval[2*x+1]<=lval[2*x+2])pre[x] = pre[2*x+1]+pre[2*x+2];
		suf[x] = suf[2*x+2];
		if(rx-m==suf[2*x+2]&&rval[2*x+1]<=lval[2*x+2])suf[x] = suf[2*x+1]+suf[2*x+2];
		lval[x] = lval[2*x+1];
		rval[x] = rval[2*x+2];
	}
	void build(){
		build(0,0,size);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			if(v!=0)v/=abs(v);
			lval[x] = rval[x] = v;
			if(lval[x]!=0){
				pre[x] = suf[x] = seg[x] = 1;
			}
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		seg[x] = max({seg[2*x+1],seg[2*x+2]});
		if(rval[2*x+1]<=lval[2*x+2])seg[x] = max(seg[x],suf[2*x+1]+pre[2*x+2]);
		pre[x] = pre[2*x+1];
		if(m-lx==pre[2*x+1]&&rval[2*x+1]<=lval[2*x+2])pre[x] = pre[2*x+1]+pre[2*x+2];
		suf[x] = suf[2*x+2];
		if(rx-m==suf[2*x+2]&&rval[2*x+1]<=lval[2*x+2])suf[x] = suf[2*x+1]+suf[2*x+2];
		lval[x] = lval[2*x+1];
		rval[x] = rval[2*x+2];
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int query(){
		return seg[0];
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	SegTree segtree;
	segtree.init(n+1);
	for(int i = 1; i<n; i++){
		dif[i] = arr[i]-arr[i+1];
	}
	segtree.build();
	int q;
	cin >> q;
	while(q--){
		int l,r,d;
		cin >> l >> r >> d;
		dif[l-1]-=d;
		dif[r]+=d;
		if(l>1)segtree.set(l-1,dif[l-1]);
		if(r<n)segtree.set(r,dif[r]);
		cout << segtree.query()+1 << "\n";
	}
	return 0;
}