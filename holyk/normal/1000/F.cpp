#include<bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader{
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
}rd;

template <class T> inline bool smin(T&x, const T&y){return y < x ? x = y, 1 : 0;}
template <class T> inline bool smax(T&x, const T&y){return x < y ? x = y, 1 : 0;}

typedef long long ll;
typedef std::pair<int, int> pii;
const int N(5e5 + 5);
int n, a[N], mp[N];
std::vector<pii> g[N];
int ans[N];
pii min[N << 2];
#define ls o << 1
#define rs o << 1 | 1
inline void update(int o, int l, int r, int x, int y){
	if(l == r)return min[o] = {y, y <= n ? l : 0}, void();
	int mid = l + r >> 1;
	if(x <= mid)update(ls, l, mid, x, y);
	else update(rs, mid + 1, r, x, y);
	min[o] = std::min(min[ls], min[rs]);
}
inline pii ask(int o, int l, int r, int x, int y){
	if(min[o].first >= x || r < x || l > y)return {1e9, 0};
	if(x <= l && r <= y)return min[o];
	int mid = l + r >> 1;
	return std::min(ask(ls, l, mid, x, y), ask(rs, mid + 1, r, x, y));
}
void build(int o, int l, int r){
	min[o] = {1e9, 0};
	if(l == r)return;
}
int main(){
	n = rd;
	REP(i, 1, n)a[i] = rd;
	int m = rd;
	REP(i, 1, m){
		int l = rd, r = rd;
		g[r].push_back({l, i});
	}
	#define all 1, 1, n
	REP(i, 1, n){
		int&x = mp[a[i]];
		update(all, i, x);
		if(x)update(all, x, 1e9);
		x = i;
		for(auto u : g[i])ans[u.second] = a[ask(all, u.first, i).second];
	}
	REP(i, 1, m)printf("%d\n", ans[i]);
	return 0;
}