#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
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
		if(sz[x]<sz[y]){
			parent[x] = y;
			sz[y]+=sz[x];
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
		}
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n+1);
		vector<int>b(n+1);
		vector<int>c(n+1);
		for(int i = 1; i<=n; i++){
			cin >> a[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> b[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> c[i];
		}
		vector<int>idx(n+1);
		for(int i = 1; i<=n; i++){
			idx[b[i]] = i;
		}
		DisjointSet ds;
		ds.init(n+5);
		for(int i = 1; i<=n; i++){
			int j = idx[a[i]];
			ds.Union(i,j);
		}
		set<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(ds.find(i));
		}
		int ans = 1;
		for(int i = 1; i<=n; i++){
			if(c[i]){
				int v = ds.find(i);
				if(s.find(v)!=s.end())s.erase(v);
			}
		}
		for(int nxt: s){
			if(ds.sz[nxt]!=1){
				ans*=2;
				ans%=mod;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}