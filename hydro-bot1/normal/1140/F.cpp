// Hydro submission #62ea22cffe2b11dfe8171e1a@1659511504332
//Code by fjy666(https://www.luogu.com.cn/user/366338)
//luogu-judger-enable-O2
#include <bits/stdc++.h>
using namespace std;
#define _rep(i_,a_,b_) for(int i_ = (a_); i_ <= (b_); ++i_)
#define _for(i_,a_,b_) for(int i_ = (a_); i_ < (b_); ++i_)
#define mid ((L+R) >> 1)
#define get(x) (((x) - 1) / kb + 1)
#define multiCase() int testCnt = in(); _rep(curCase,1,testCnt)
#define multi(init) int testCnt = (init); _rep(curCase,1,testCnt)
#ifdef ONLINE_JUDGE
#define debug(...) 
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;

int in(void) { int x; scanf("%d", &x); return x; }
ll inl(void) { ll x; scanf("%lld", &x); return x; }
template<typename T> void chkmax(T &a, const T &b) { a = max(a, b); } 
template<typename T> void chkmin(T &a, const T &b) { a = min(a, b); } 
const int kN = 600400;
int fa[kN], siza[kN], sizb[kN];
stack<pair<int,int> > s; 
ll ans;
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
void merge(int x, int y) {
	debug("Merging %d and %d\n", x, y);
	x = find(x), y = find(y);
	if(siza[x] + sizb[x] > siza[y] + sizb[y]) swap(x, y);
	debug("ans = %lld\n", ans);
	ans -= (ll) siza[x] * sizb[x] + (ll) siza[y] * sizb[y];
	debug("ans = %lld\n", ans);
	fa[x] = y, siza[y] += siza[x], sizb[y] += sizb[x];
	ans += (ll) siza[y] * sizb[y]; s.push(make_pair(x, y));
	debug("ans = %lld\n", ans);
}
void roll(void) {
	int x = s.top().first, y = s.top().second; s.pop();
	debug("Roll %d %d\n", x, y);
	ans -= (ll) siza[y] * sizb[y];
	fa[x] = x, siza[y] -= siza[x], sizb[y] -= sizb[x];
	ans += (ll) siza[x] * sizb[x] + (ll) siza[y] * sizb[y];
}

map<pair<int,int>, int> mp;

vector<pair<int,int> > t[kN << 2];
void insert(int x, int L, int R, int l, int r, int u, int v) {
	if(l <= L && R <= r) t[x].push_back(make_pair(u, v));
	else {
		if(l <= mid) insert(x << 1, L, mid, l, r, u, v);
		if(mid < r) insert(x << 1 | 1, mid + 1, R, l, r, u, v);
	}
}

void dfs(int x, int L, int R) {
	int cnt = 0;
	for(auto &[u, v] : t[x]) {
		if(find(u) == find(v + 300000)) continue;
		merge(u, v + 300000); ++cnt;
	}
	if(L == R) printf("%lld ", ans); else dfs(x << 1, L, mid), dfs(x << 1 | 1, mid + 1, R);
	multi(cnt) roll();
}

int main() { 
	_rep(i,1,300000) fa[i] = i, siza[i] = 1;
	_rep(i,300001,600000) fa[i] = i, sizb[i] = 1;
	int q = in();
	multi(q) {
		int x = in(), y = in();
		if(!mp[make_pair(x, y)]) mp[make_pair(x, y)] = curCase;
		else insert(1, 1, q, mp[make_pair(x, y)], curCase - 1, x, y), mp.erase(make_pair(x, y));
	}
	for(auto &[pii, tim] : mp) insert(1, 1, q, tim, q, pii.first, pii.second);
	dfs(1, 1, q);
	return 0;
}

/* 
a list of keywords
clear empty push_back pop_back push pop top front back
emplace_back emplace push_front pop_front insert erase
find count set reset bitset map vector string multiset
first second iterator prev next deque multimap reverse
sort begin end list modify query init check calc prime 
putchar getchar puts scanf printf max min swap replace
*/