#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct sweep{
	int s, e, x, loc;
	bool operator<(const sweep &s)const{
		return loc < s.loc;
	}
};

vector<sweep> v;

struct seg{
	struct node{
		int val, pos;
		bool operator<(const node &n)const{
			return val < n.val;
		}
	}tree[1050000];
	int lazy[1050000];
	void lazydown(int p){
		tree[2*p].val += lazy[p];
		tree[2*p+1].val += lazy[p];
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	void init(int s, int e, int p){
		if(s == e){
			tree[p].pos = s;
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m+1, e, 2*p+1);
		tree[p] = max(tree[2*p], tree[2*p+1]);
	}
	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].val += v;
			lazy[p] += v;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = max(tree[2*p], tree[2*p+1]);
	}
}seg;

int n, s[100005], e[100005], x[100005];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d %d %d",&s[i],&x[i],&e[i]);
		v.push_back({x[i], e[i], 1, s[i]});
		v.push_back({x[i], e[i], -1, x[i]+1});
	}
	int ans = 0, px = -1, py = -1;
	sort(v.begin(), v.end());
	seg.init(1, 300000, 1);
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[e].loc == v[i].loc){
			seg.add(v[e].s, v[e].e, 1, 300000, 1, v[e].x);
			e++;
		}
		if(ans < seg.tree[1].val){
			ans = seg.tree[1].val;
			px = v[i].loc;
			py = seg.tree[1].pos;
		}
		i = e;
	}
	cout << ans << endl;
	for(int i=1; i<=n; i++){
		if(s[i] <= px && e[i] >= py && px <= x[i] && x[i] <= py){
			printf("%d ", i);
		}
	}
}