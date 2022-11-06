#include <bits/stdc++.h>
using namespace std;
#define int long long
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
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>val;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
		val.assign(2*size,0LL);
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx)return;
		if(lx>=l&&rx<=r){
			arr[x]+=v;
			val[x]+=v*(rx-lx);
			return;
		}
		int m = (lx+rx)/2;
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		val[x] = val[2*x+1]+val[2*x+2];
		val[x]= val[x]+arr[x]*(rx-lx);
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l,int r,int cur, int x, int lx, int rx){
		if(lx>=r||l>=rx)return 0;
		if(lx>=l&&rx<=r)return (val[x]+cur*(rx-lx));
		int m = (lx+rx)/2;
		int s1 = query(l,r,(cur+arr[x]),2*x+1,lx,m);
		int s2 = query(l,r,(cur+arr[x]),2*x+2,m,rx);
		return (s1+s2);
	}
	int query(int l, int r){
		return query(l,r,0,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	string s;
	cin >> s;
	for(int i = 1; i<=n; i++){
		if(s[i-1]=='1')arr[i] = 1;
	}
	BIT bit;
	bit.init(n);
	SegTree segtree;
	segtree.init(n+5);
	int cur = 0;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(arr[i]==1){
			cur++;
		}
		else{
			cur = 0;
			ans+=segtree.query(1,n+1);
			continue;
		}
		int low = 0; int high = n; int mid = (low+high)/2;
		while(low+1<high){
			if(bit.query(mid)<cur){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		bit.update(high,1);
		bit.update(i+1,-1);
		segtree.set(high,i+1,1);
		ans+=segtree.query(1,n+1);
	}
	cout << ans << "\n";
	return 0;
}