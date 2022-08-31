#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 100005;
const int MAXT = 270000;

struct seg{
	int tree[MAXT], lazy[MAXT];
	void lazydown(int p, int s, int e){
		if(lazy[p]){
			lazy[p] = 0;
			int m = (s+e)/2;
			lazy[2*p] ^= 1;
			lazy[2*p+1] ^= 1;
			tree[2*p] = m - s + 1 - tree[2*p];
			tree[2*p+1] = e - m - tree[2*p+1];
		}
	}
	void upd(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] = pe - ps + 1 - tree[p];
			lazy[p] ^= 1;
			return;
		}
		lazydown(p, ps, pe);
		int pm = (ps+pe)/2;
		upd(s, e, ps, pm, 2*p);
		upd(s, e, pm+1, pe, 2*p+1);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	int query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p, ps, pe);
		int pm = (ps+pe)/2;
		return query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1);
	}
}seg;

int n, q, a[MAXN];
vector<pi> evnt[MAXN];
int arr[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	for(int i=0; i<q; i++){
		int x, y; scanf("%d %d",&x,&y);
		x = lower_bound(a, a+n, x) - a;
		y = upper_bound(a, a+n, y) - a;
		evnt[x].emplace_back(x, y);
		evnt[y].emplace_back(x, y);
	}
	lint ret = 0;
	for(int i=0; i<n; i++){
		for(auto &j : evnt[i]){
			seg.upd(j.first, j.second - 1, 0, n - 1, 1);
		}
		int indeg = seg.query(i + 1, n - 1, 0, n - 1, 1) + i - seg.query(0, i - 1, 0, n - 1, 1);
		int outdeg = n - 1 - indeg;
		ret += 1ll * indeg * outdeg;
	}
	ret -= 1ll * n * (n - 1) * (n - 2) / 6;
	assert(ret % 2 == 0);
	cout << ret / 2 << endl;
}