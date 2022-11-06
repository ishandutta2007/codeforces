#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>pre;
	vector<int>suf;
	vector<int>seg;
	vector<int>maxs;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
		pre.assign(2*size,0LL);
		suf.assign(2*size,0LL);
		seg.assign(2*size,0LL);
		maxs.assign(2*size,0LL);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			arr[x] = v;
			pre[x] = max(0LL,v);
			suf[x] = max(0LL,v);
			seg[x] = max(0LL,v);
			maxs[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr[x] = arr[2*x+1]+arr[2*x+2];
		pre[x] = max(pre[2*x+1],arr[2*x+1]+pre[2*x+2]);
		suf[x] = max(suf[2*x+2],suf[2*x+1]+arr[2*x+2]);
		seg[x] = max(seg[2*x+1],max(seg[2*x+2],suf[2*x+1]+pre[2*x+2]));
		maxs[x] = max(maxs[2*x+1],maxs[2*x+2]);
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	vector<int> query(int l,int r, int x, int lx, int rx){
		vector<int>res(4);//sum,prefix,suffix,segment
		if(lx>=r||l>=rx)return {0,0,0,0};
		if(lx>=l&&rx<=r){
			res[0] = arr[x];
			res[1] = pre[x];
			res[2] = suf[x];
			res[3] = seg[x];
			return res;
		}
		int m = (lx+rx)/2;
		vector<int>res1 = query(l,r,2*x+1,lx,m);
		vector<int>res2 = query(l,r,2*x+2,m,rx);
		res[0] = res1[0]+res2[0];
		res[1] = max(res1[1],res1[0]+res2[1]);
		res[2] = max(res2[2],res1[2]+res2[0]);
		res[3] = max(res1[3],max(res2[3],res1[2]+res2[1]));
		return res;
	}
	int query(int l, int r){
		vector<int>res = query(l,r,0,0,size);
		return res[3];
	}
	int query2(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return -1*(int)1e18;
		if(lx>=l&&rx<=r)return maxs[x];
		int m = (lx+rx)/2;
		int s1 = query2(l,r,2*x+1,lx,m);
		int s2 = query2(l,r,2*x+2,m,rx);
		return max(s1,s2);
	}
	int query2(int l, int r){
		return query2(l,r,0,0,size);
	}
};
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+5);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
struct SegTree2{
	int size;
	vector<int>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			arr[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return -(int)1e18;
		if(lx>=l&&rx<=r)return arr[x];
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return max(s1,s2);
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		arr[i]-=x;
	}
	BIT bit;
	bit.init(n);
	for(int i = 1; i<=n; i++){
		bit.update(i,arr[i]);
	}
	SegTree neg;
	SegTree pos;
	SegTree2 segtree;
	segtree.init(n+5);
	neg.init(n+5);
	pos.init(n+5);
	for(int i = 1; i<=n; i++){
		if(arr[i]<0){
			neg.set(i,abs(arr[i]));
			pos.set(i,arr[i]);
		}
		if(arr[i]>0){
			neg.set(i,-1*arr[i]);
			pos.set(i,arr[i]);
		}
		segtree.set(i,bit.query(i));
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		if(bit.query(l,r)!=0||segtree.query(l,r+1)-bit.query(l-1)>0){
			cout << "-1\n";
			continue;
		}
		int v = pos.query(l,r+1);
		int v2 = neg.query(l,r+1);
		assert(v>=0);
		assert(v2>=0);
		cout << max(v,v2) << "\n";
		//cout << max(pos.query(l,r+1),neg.query(l,r+1)) << "\n";
	}
	return 0;
}