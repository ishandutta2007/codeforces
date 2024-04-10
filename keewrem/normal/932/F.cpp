#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
using namespace std;
typedef long long ll;
const int MAXN = 100010;


struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll a[MAXN],b[MAXN],ans[MAXN];
int r[MAXN],s[MAXN];
vi g[MAXN];
bool vis[MAXN];
LineContainer ch[MAXN];

void dfs(int n){
	s[n] = 1;
	for(auto x: g[n]){
		if(s[x])continue;
		dfs(x);
		if(s[x] > s[r[n]])r[n] = x;
		s[n]+=s[x];
	}
	if(r[n] == 0)r[n] = n;
	else r[n] = r[r[n]];

}

void kek(int n){
	vis[n] = 1;
	int d = 0;
	for(auto x: g[n]){
		if(vis[x]){d = x;continue;}
		kek(x);
	}
	for(auto x: g[n]){
		if(r[x]!=r[n] && x!=d)for(auto x: ch[r[x]])ch[r[n]].add(x.k,x.m);
	}
	if(ch[r[n]].empty())ans[n] = 0;
	else ans[n] = -ch[r[n]].query(a[n]);
	ch[r[n]].add(-b[n],-ans[n]);
}

void solve(){
	int N; cin >> N;
	for(int i = 1; i <= N; i++)cin >> a[i];
	for(int i = 1; i <= N; i++)cin >> b[i];
	int x,y;
	for(int i = 1; i < N; i++){
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	kek(1);
	for(int i = 1; i <= N; i++)cout << ans[i] << " \n"[i == N];
}


int main(){
	solve();
}