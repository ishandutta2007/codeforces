#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		return find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		parent[x] = y;
		sz[y]+=sz[x];
	}
};
int mxn = 1000005;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	int cur = 1;
	vector<vector<int>>sets(mxn);
	for(int i = 1; i<mxn; i++){
		sets[i].push_back(i);
	}
	vector<int>val(mxn);
	vector<int>temp(mxn);
	map<int,int>hm;
	int last = 0;
	DisjointSet ds;
	ds.init(mxn);
	while(q--){
		int t;
		cin >> t;
		if(t==1){
			int l,r,w;
			cin >> l >> r >> w;
			l^=last;
			r^=last;
			w^=last;
			if(l>r)swap(l,r);
			l--;
			if(hm[l]==0){
				hm[l] = cur;
				cur++;
			}
			if(hm[r]==0){
				hm[r] = cur;
				cur++;
			}
			int x = hm[l]; int y = hm[r];
			if(ds.find(x)==ds.find(y))continue;
			int s1 = ds.find(x); int s2 = ds.find(y);
			if(ds.sz[s1]<ds.sz[s2]){
				for(int nxt: sets[s1]){
					sets[s2].push_back(nxt);
					temp[nxt] = (val[nxt]^val[x]^w^val[y]);
				}
				for(int nxt: sets[s1]){
					val[nxt] = temp[nxt];
				}
				sets[s1].clear();
				ds.Union(s1,s2);
			}
			else{
				for(int nxt: sets[s2]){
					sets[s1].push_back(nxt);
					temp[nxt] = (val[nxt]^val[x]^w^val[y]);
				}
				for(int nxt: sets[s2]){
					val[nxt] = temp[nxt];
				}
				sets[s2].clear();
				ds.Union(s2,s1);
			}
		}
		else{
			int l,r;
			cin >> l >> r;
			l^=last;
			r^=last;
			if(l>r)swap(l,r);   
			l--;
			if(hm[l]==0||hm[r]==0){
				cout << "-1\n";
				last = 1;
				continue;
			}
			l = hm[l]; r = hm[r];
			if(ds.find(l)==ds.find(r)){
				cout << (val[l]^val[r]) << "\n";
				last = (val[l]^val[r]);
			}
			else{
				last = 1;
				cout << "-1\n";
			}
		}
	}
	return 0;
}