#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

struct disj{
	int pa[MAXN];
	lint is[MAXN], ie[MAXN];
	lint tot, cmp;
	lint getIntv(){ return tot; }
	lint getCmp(){ return cmp; }
	void init(int n, lint *a){
		cmp = n;
		tot = n;
		for(int i=0; i<n; i++){
			pa[i] = i;
			is[i] = ie[i] = a[i];
		}
	}
	int find(int x){ return pa[x] = (pa[x] == x ? x : find(pa[x])); }
	void uni(int x, int y){
		 x = find(x);
		 y = find(y);
		 if(x > y) swap(x, y);
		 cmp--;
		 tot += is[y] - ie[x] - 1;
		 pa[y] = x;
		 ie[x] = ie[y];
	}
}disj;

int n, q;
lint a[MAXN], ans[MAXN];
pi b[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	sort(a, a + n);
	disj.init(n, a);
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		lint l, r; scanf("%lld %lld",&l,&r);
		b[i] = pi(r - l, i);
	}
	vector<pi> ev;
	sort(b, b + q);
	for(int i=1; i<n; i++){
		ev.emplace_back(a[i] - a[i-1], i);
	}
	sort(ev.begin(), ev.end());
	int ptr = 0;
	for(int i=0; i<q; i++){
		while(ptr < ev.size() && ev[ptr].first <= b[i].first){
			disj.uni(ev[ptr].second - 1, ev[ptr].second);
			ptr++;
		}
		ans[b[i].second] = disj.getIntv() + (b[i].first) * disj.getCmp();
	}
	for(int i=0; i<q; i++) printf("%lld ", ans[i]);
}