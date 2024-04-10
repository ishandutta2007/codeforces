#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a(200005);
int n,q;
struct SegTree{
	int size;
	vector<int>pre;
	vector<int>suf;
	vector<int>seg;
	vector<int>left;
	vector<int>right;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		pre.assign(2*size,0LL);
		suf.assign(2*size,0LL);
		seg.assign(2*size,0LL);
		left.assign(2*size,0LL);
		right.assign(2*size,0LL);
	}
	void build(int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<n){
				left[x] = a[lx];
				right[x] = a[lx];
				seg[x] = 1;
				pre[x] = 1;
				suf[x] = 1;
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		seg[x] = seg[2*x+1] + seg[2*x+2];
		if(right[2*x+1]<=left[2*x+2])seg[x]+=suf[2*x+1]*pre[2*x+2];
		pre[x] = pre[2*x+1];
		if(pre[2*x+1]*2==rx-lx&&right[2*x+1]<=left[2*x+2])pre[x]+=pre[2*x+2];
		suf[x] = suf[2*x+2];
		if(suf[2*x+2]*2==rx-lx&&right[2*x+1]<=left[2*x+2])suf[x]+=suf[2*x+1];
		left[x] = left[2*x+1];
		right[x] = right[2*x+2];
		//cout << lx << " " << rx-1 << " " << seg[x] << "\n";
	}
	void build(){
		build(0,0,size);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			left[x] = v;
			right[x] = v;
			seg[x] = 1;
			pre[x] = 1;
			suf[x] = 1;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		seg[x] = seg[2*x+1] + seg[2*x+2];
		if(right[2*x+1]<=left[2*x+2])seg[x]+=suf[2*x+1]*pre[2*x+2];
		pre[x] = pre[2*x+1];
		if(pre[2*x+1]*2==rx-lx&&right[2*x+1]<=left[2*x+2])pre[x]+=pre[2*x+2];
		suf[x] = suf[2*x+2];
		if(suf[2*x+2]*2==rx-lx&&right[2*x+1]<=left[2*x+2])suf[x]+=suf[2*x+1];
		left[x] = left[2*x+1];
		right[x] = right[2*x+2];
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	vector<int> query(int l,int r, int x, int lx, int rx){
		vector<int>ret(6);
		if(lx>=r||l>=rx)return ret;
		if(lx>=l&&rx<=r){
			ret[0] = pre[x]; ret[1] = suf[x]; ret[2] = seg[x]; ret[3] = left[x]; ret[4] = right[x]; ret[5] = rx-lx;
			return ret;
		}
		int m = (lx+rx)/2;
		vector<int>a = query(l,r,2*x+1,lx,m);
		vector<int>b = query(l,r,2*x+2,m,rx);
		if(a[2]==0)return b;
		if(b[2]==0)return a;
		ret[2] = a[2] + b[2];
		if(a[4]<=b[3])ret[2] += a[1]*b[0];
		ret[0] = a[0];
		if(a[0]==a[5]&&a[4]<=b[3])ret[0]+=b[0];
		ret[1] = b[1];
		if(b[1]==b[5]&&a[4]<=b[3])ret[1]+=a[1];
		ret[3] = a[3];
		ret[4] = b[4];
		ret[5] = a[5]+b[5];
		return ret;
	}
	vector<int> query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	SegTree segtree;
	segtree.init(n);
	segtree.build();
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int i,v;
			cin >> i >> v;
			i--;
			segtree.set(i,v);
		}
		else{
			int l,r;
			cin >> l >> r;
			l--;
			cout << segtree.query(l,r)[2] << "\n";
		}
	}
	return 0;
}