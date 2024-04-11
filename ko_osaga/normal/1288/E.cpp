#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 300005;
const int mod = 1e9 + 7;

struct seg{
	vector<int> tree[1050000];
	int lim;
	void init(int n, int *a){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=0; i<n; i++){
			if(a[i] > 1e9) continue;
			for(int j=i+lim; j; j>>=1){
				tree[j].push_back(a[i]);
			}
		}
		for(int i=1; i<1050000; i++) sort(tree[i].begin(), tree[i].end());
	}
	int query(int v, int x){
		return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
	}
	int query(int s, int e, int x){
		s += lim;
		e += lim;
		int ret = 0;
		while(s < e){
			if(s%2 == 1) ret += query(s++, x);
			if(e%2 == 0) ret += query(e--, x);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret += query(s, x);
		return ret;
	}
}seg;

struct ds{
	int nxt[MAXN];
	int mp[MAXN];
	void init(vector<int> a){
		int n = sz(a);
		for(int i=n-1; i>=0; i--){
			if(mp[a[i]]) nxt[i] = mp[a[i]];
			else nxt[i] = n + 10;
			mp[a[i]] = i;
		}
		seg.init(n, nxt);
	}
	int query(int l, int r){
		return r - l + 1 - seg.query(l, r, r);
	}
}ds;

vector<int> pos[MAXN];

struct bit{
	int tree[MAXN];
	void clear(){
		memset(tree, 0, sizeof(tree));
	}
	void add(int x, int v){
		while(x < MAXN){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int main(){
	int n, m; scanf("%d %d",&n,&m);
	vector<int> v(m);
	vector<int> minv(n + 1);
	vector<int> maxv(n + 1);
	vector<int> occur(n + 2);
	for(auto &i : v){
		scanf("%d",&i);
		occur[i] = 1;
	}
	for(int i=1; i<=n; i++){
		if(occur[i]){
			minv[i] = 1;
		}
		else{
			minv[i] = i;
		}
	}
	{
		fill(all(occur), 0);
		for(int i=0; i<m; i++) pos[v[i]].push_back(i);
		for(int i=1; i<=n; i++) pos[i].push_back(m);
		vector<pi> fst;
		for(int i=1; i<=n; i++) fst.emplace_back(pos[i][0], i);
		sort(all(fst));
		int ptr = 0;
		for(auto &i : fst){
			while(ptr < i.first){
				if(!occur[v[ptr]]){
					bit.add(v[ptr], 1);
					occur[v[ptr]] = 1;
				}
				ptr++;
			}
			maxv[i.second] = i.second + bit.query(n) - bit.query(i.second);
		}
		ds.init(v);
		for(int i=1; i<=n; i++){
			for(int j=1; j<sz(pos[i]); j++){
				maxv[i] = max(maxv[i], ds.query(pos[i][j-1], pos[i][j] - 1));
			}
		}
	}
	for(int i=1; i<=n; i++) printf("%d %d\n", minv[i], maxv[i]);
}