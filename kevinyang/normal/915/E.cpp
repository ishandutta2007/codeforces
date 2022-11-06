#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
int n,q;
vector<int>sorted;
int psa[2100001];
struct SegTree{
	int arr[4194304];
	int val[4194304];
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		memset(arr,0,sizeof(arr));
		memset(val,0,sizeof(val));
	}
	void pushdown(int x, int len, int len2){
		if(val[x]==-1)return;
		arr[x] = val[x]*len;
		if(len2>1){
			val[2*x+1] = val[x];
			val[2*x+2] = val[x];
		}
		val[x] = -1;
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x] = v;
			pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
			return;
		}
		int m = (lx+rx)/2;
		pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = arr[2*x+1]+arr[2*x+2];
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
			return 0;
		}
		if(lx>=l&&rx<=r){
			pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
			return arr[x];
		}
		int m = (lx+rx)/2;
		pushdown(x,psa[rx-1]-psa[lx-1],rx-lx);
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	memset(psa,0,sizeof(psa));
	int a[q+1][3];
	priority_queue<int,vector<int>,greater<int>>s;
	for(int i = 1; i<=q; i++){
		int l,r,k;
		cin >> l >> r >> k;
		a[i][0] = l; a[i][1] = r; a[i][2] = k;
		s.push(l); s.push(r);
		a[i][2]%=2;
	}
	vector<int>sorted; sorted.push_back(0);
	int prev = (int)2e9;
	while(s.size()){
		int v = s.top(); s.pop();
		if(v!=prev)sorted.push_back(v), sorted.push_back(v);
		prev = v;
	}
	sorted[0] = sorted[1]-1;
	for(int i = 1; i<sorted.size()-1; i++){
		if(i%2==1){
			psa[i] = 1+psa[i-1];
		}
		else{
			psa[i] = sorted[i+1]-sorted[i-1]-1+psa[i-1];
		}
	}
	SegTree segtree;
	segtree.init(1200001);
	int ans = sorted[1]-1 + n-sorted[sorted.size()-1];
	for(int i = 1; i<=q; i++){
		//cerr << "nae2\n";
		int l = lower_bound(sorted.begin(),sorted.end(),a[i][0])-sorted.begin();
		int r = lower_bound(sorted.begin(),sorted.end(),a[i][1])-sorted.begin();
		//cerr << l << " " << r << "\n";
		segtree.set(l,r+1,a[i][2]);
		//cerr << "nae\n";
		cout <<  n- segtree.query(1,1200001) << "\n";
	}
	return 0;
}