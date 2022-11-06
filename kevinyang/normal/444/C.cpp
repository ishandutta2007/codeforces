#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	vector<int>arr;
	vector<int>val;
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.resize(size*2);
		val.resize(size*2); 
	}
	void pushdown(int x, int len){
		if(val[x]==0)return;
		arr[x]+=len*val[x];
		if(len>1){
			val[2*x+1]+=val[x]; val[2*x+2]+=val[x];
		}
		val[x] = 0;
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x]+=v;
			pushdown(x,rx-lx);
			return;
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return 0;
		}
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
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
	int n,m;
	cin >> n >> m;
	set<pair<int,pair<int,int>>>s;// starting index, colour, length
	for(int i = 1; i<=n; i++){
		s.insert({i,{i,1}});
	}
	SegTree segtree;
	segtree.init(n+5);
	while(m--){
		int cm;
		cin >> cm;
		if(cm==1){
			int l,r,x;
			cin >> l >> r >> x;
			if(true){
				pair<int,pair<int,int>> p = {l,{(int)1e18,0}};
				auto val = *--s.upper_bound(p);
				if(val.first!=l){
					s.erase(val);
					auto add = val;
					add.second.second = l-add.first;
					s.insert(add);
					add = val;
					add.second.second = add.second.second-(l-add.first);
					add.first = l;
					s.insert(add);
				}
			}
			if(true){
				pair<int,pair<int,int>> p = {r+1,{(int)1e18,0}};
				auto val = *--s.upper_bound(p);
				if(val.first!=r+1){
					s.erase(val);
					auto add = val;
					add.second.second = r+1-add.first;
					s.insert(add);
					add = val;
					add.second.second = add.second.second-(r+1-add.first);
					add.first = r+1;
					s.insert(add);
				}
			}
			while(true){
				auto it = s.lower_bound({l,{0,0}});
				if(it==s.end())break;
				if((*it).first>r)break;
				int lx = (*it).first;
				int rx = lx + (*it).second.second;
				segtree.set(lx,rx,abs((*it).second.first-x));
				s.erase(it);
			}
			s.insert({l,{x,r-l+1}});
		}
		else{
			int l,r;
			cin >> l >> r;
			r++;
			cout << segtree.query(l,r) << "\n";
		}
	}
	return 0;
}