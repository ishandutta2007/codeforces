#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

struct query{
	int pos, s, e, lim;
	bool operator<(const query &q)const{
		return pos < q.pos;
	}
}a[100005];


multiset<pi> tree[270000];
pi ans[270000];

void add(int pos, int t, int v, int s, int e, int p){
	if(s == e){
		tree[p].insert(pi(t, v));
		ans[p] = pi(tree[p].begin()->first, s);
		return;
	}
	int m = (s+e)/2;
	if(pos <= m) add(pos, t, v, s, m, 2*p);
	else add(pos, t, v, m+1, e, 2*p+1);
	ans[p] = min(ans[2*p], ans[2*p+1]);
}

lint erase(int pos, int s, int e, int p){
	if(s == e){
		assert(tree[p].size());
		lint ret = tree[p].begin()->second;
		tree[p].erase(tree[p].begin());
		if(tree[p].size()) ans[p] = pi(tree[p].begin()->first, s);
		else ans[p]= pi(2e9, s);
		return ret;
	}
	lint ret = 0;
	int m = (s+e)/2;
	if(pos <= m) ret = erase(pos, s, m, 2*p);
	else ret = erase(pos, m+1, e, 2*p+1);
	ans[p] = min(ans[2*p], ans[2*p+1]);
	return ret;
}

pi query(int s, int e, int ps, int pe, int p){
	if(e < ps || pe < s) return pi(2e9, 2e9);
	if(s <= ps && pe <= e){
		return ans[p];
	}
	int pm = (ps+pe)/2;
	return min(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
}

int w, h, n;

int main(){
	scanf("%d %d %d",&h,&w,&n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d",&a[i].pos,&a[i].s,&a[i].e,&a[i].lim);
	}
	sort(a, a+n);
	fill(ans, ans + 270000, pi(2e9, 2e9));
	for(int i=1; i<=w; i++) add(i, h+1, 1, 1, w, 1);
	for(int i=n-1; i>=0; i--){
		lint sum = 0;
		while(1){
			auto l = query(a[i].s, a[i].e, 1, w, 1);
			if(l.first <= min(h + 2, a[i].pos + a[i].lim)){
				sum += erase(l.second, 1,w, 1);
			}
			else break;
		}
		sum %= mod;
		int p = a[i].s - 1;
		if(p == 0) p = a[i].e + 1;
		add(p, a[i].pos, sum, 1, w, 1);
		p = a[i].e + 1;
		if(p > w) p = a[i].s - 1;
		add(p, a[i].pos, sum, 1, w, 1);
	}
	lint sum = 0;
	while(1){
		auto l = query(1, w, 1, w, 1);
		if(l.first <= h + 1){
			sum += erase(l.second, 1, w, 1);
		}
		else break;
	}
	cout << sum % mod;


}