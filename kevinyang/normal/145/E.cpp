#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,m;
struct SegTree{
	vector<int>cnt4;
	vector<int>cnt7;
	vector<int>seg;
	vector<int>seg2;
	vector<int>val;
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		cnt4.resize(size*2);
		cnt7.resize(size*2);
		seg.resize(size*2);
		seg2.resize(size*2);
		val.resize(size*2); 
	}
	void pushdown(int x, int len){
		if(val[x]==0)return;
		swap(cnt7[x],cnt4[x]);
		swap(seg[x],seg2[x]);
		if(len>1){
			val[2*x+1]^=1; val[2*x+2]^=1;
		}
		val[x] = 0;
	}
	void build(int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<n){
				if(s[lx]=='4')cnt4[x]++;
				else cnt7[x]++;
				seg[x] = 1;
				seg2[x] = 1;
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		seg[x] = max(seg[2*x+1]+cnt7[2*x+2],cnt4[2*x+1]+seg[2*x+2]);
		seg2[x] = max(cnt7[2*x+1]+seg2[2*x+2],seg2[2*x+1]+cnt4[2*x+2]);
		cnt4[x] = cnt4[2*x+1]+cnt4[2*x+2];
		cnt7[x] = cnt7[2*x+1]+cnt7[2*x+2];
	}
	void build(){
		build(0,0,size);
	}
	void set(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x]^=1;
			pushdown(x,rx-lx);
			return;
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		set(l,r,2*x+1,lx,m);
		set(l,r,2*x+2,m,rx);
		seg[x] = max(seg[2*x+1]+cnt7[2*x+2],cnt4[2*x+1]+seg[2*x+2]);
		seg2[x] = max(cnt7[2*x+1]+seg2[2*x+2],seg2[2*x+1]+cnt4[2*x+2]);
		cnt4[x] = cnt4[2*x+1]+cnt4[2*x+2];
		cnt7[x] = cnt7[2*x+1]+cnt7[2*x+2];
	}
	void set(int l, int r){
		set(l,r,0,0,size);
	}
	int query(){
		return seg[0];
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	SegTree segtree;
	segtree.init(n);
	segtree.build();
	while(m--){
		string cm;
		cin >> cm;
		if(cm=="switch"){
			int l,r;
			cin >> l >> r;
			l--;
			segtree.set(l,r);
		}
		else{
			cout << segtree.query() << "\n";
		}
	}
	return 0;
}