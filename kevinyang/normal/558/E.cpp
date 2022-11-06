#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>val;//lazy
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(4*size,0LL);
		val.assign(4*size,-1LL);
	}
	void pushdown(int x, int len){
		if(val[x]==-1)return;
		int v = val[x];
		arr[x] = v*len; val[x] = -1;
		val[2*x+1] = v; val[2*x+2] = v;
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx)return;
		if(lx>=l&&rx<=r){
			arr[x]=v*(rx-lx);
			val[x] = -1;
			if(rx-lx==1)return;
			val[2*x+1] = v;
			val[2*x+2] = v;
			return;
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		pushdown(2*x+1,m-lx);
		pushdown(2*x+2,rx-m);
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = arr[2*x+1]+arr[2*x+2];
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return 0;
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		pushdown(2*x+1,m-lx);
		pushdown(2*x+2,rx-m);
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
int n,q;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	string s;
	cin >> s;
	vector<SegTree>st(26);
	for(int i = 0; i<26; i++){
		st[i].init(n);
	}
	for(int i = 0; i<n; i++){
		st[s[i]-'a'].set(i,i+1,1);
	}
	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		l--; r--;
		if(k==1){
			int cur = l;
			for(int i = 0; i<26; i++){
				int sum = st[i].query(l,r+1);
				st[i].set(l,r+1,0);
				st[i].set(cur,cur+sum,1);
				cur+=sum;
			}
		}
		else{
			int cur = l;
			for(int i = 25; i>=0; i--){
				int sum = st[i].query(l,r+1);
				st[i].set(l,r+1,0);
				st[i].set(cur,cur+sum,1);
				cur+=sum;
			}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<26; j++){
			if(st[j].query(i,i+1)==1){
				cout << ((char)('a'+j));
			}
		}
	}
	cout << "\n";
	return 0;
}