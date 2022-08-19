#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 20005;
using pi = pair<lint, lint>;

int n, k;
int dp[MAXN], nxt[MAXN], a[MAXN];

using line_t = long long;
const line_t is_query = -1e18;

struct Line {
	line_t m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ();
		if (!s) return 0;
		line_t x = rhs.m;
		return b - s->b < (s->m - m) * x;
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
	}
	void insert_line(line_t m, line_t b) {
		m = -m, b = -b;
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	line_t query(line_t x) {
		if(empty()) return 1.5e9;
		auto l = *lower_bound((Line) { x, is_query });
		return -(int)round(l.m * x + l.b);
	}
}H;

struct foo{
	int curMax, dpv, idx;
};

struct cht{
	deque<pi> v;
	void clear(){ v.clear(); }
	bool bad(pi x, pi y, pi z){
		auto v1 = (long double)(y.second - x.second) / (x.first - y.first);
		auto v2 = (long double)(z.second - y.second) / (y.first - z.first);
		return v1 > v2;
	}
	void insert_line(lint x, lint y){
		if(v.size() && v.back().first == x){
			y = min(y, v.back().second);
			v.pop_back();
		}
		assert(v.empty() || v.back().first > x);
		while(v.size() >= 2 && bad(v[v.size() - 2], v.back(), pi(x, y))){
			v.pop_back();
		}
		v.emplace_back(x, y);
	}
	int query(int x){
		if(v.empty()) return 1e9;
		int s = 0, e = v.size() - 1;
		while(s != e){
			int m = (s+e)/2;
			if(v[m].first * x + v[m].second > v[m+1].first * x + v[m+1].second) s = m + 1;
			else e = m;
		}
		return v[s].first * x + v[s].second;
	}
	int yreuq(int x){
		return query(x);
	}

}cht;

int tab[MAXN];

void dnc(int s, int e){
	if(s == e) return;
	int m = (s+e)/2;
	dnc(s, m);
	dnc(m + 1, e);
	int curMax = 0;
	vector<foo> v;
	for(int i=m; i>=s; i--){
		if(dp[i] < 1e9) v.push_back({curMax, dp[i], i});
		curMax = max(curMax, a[i]);
	}
	tab[m] = 0;
	for(int i=m+1; i<=e; i++){
		tab[i] = max(tab[i-1], a[i]);
	}
	cht.clear();
	int ptr = v.size();
	for(int i=e; i>m; i--){
		while(ptr > 0 && v[ptr-1].curMax >= tab[i]){
			ptr--;
			auto j = v[ptr];
			cht.insert_line(j.curMax, j.dpv - j.idx * j.curMax);
		}
		nxt[i] = min(nxt[i], (int)cht.query(i));
	}
	cht.clear();
	ptr = 0;
	for(int i=m+1; i<=e; i++){
		while(ptr < v.size() && v[ptr].curMax < tab[i]){
			cht.insert_line(v[ptr].idx, v[ptr].dpv);
			ptr++;
		}
		nxt[i] = min(nxt[i], (int)cht.query(-tab[i]) + i * tab[i]);
	}
}
void solve(){
	dnc(0, n);
	/*
	for(int i=1; i<=n; i++){
		int curMax = 0;
		for(int j=i-1; j>=0; j--){
			curMax = max(curMax, a[j + 1]);
			nxt[i] = min(nxt[i], dp[j] - j * curMax + i * curMax);
		}
	}*/

}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		 scanf("%d",&a[i]);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i=1; i<=k; i++){
		memset(nxt, 0x3f, sizeof(nxt));
		solve();
		memcpy(dp, nxt, sizeof(dp));
	}
	cout << dp[n] << endl;
}