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

const int N(1e7 + 5);
std::vector< std::pair<int, int> > g[250005];
int n, a[N];
ll b[N], f[N], c[N];
inline void add(int p, ll x){
	for(; p; p -= p & -p)smin(c[p], x);
}
inline ll ask(int p){
	ll r = 1e18;
	for(; p <= n; p += p & -p)smin(r, c[p]);
	return r;
}
int main(){
	n = rd;
	int m = rd, p = 0;
	REP(i, 1, n){
		g[i].resize((int)rd);
		for(auto&t : g[i])t.first = rd;
		for(auto&t : g[i])t.second = rd;
	}
	n = rd;
	while(n--){
		int x = rd, y = rd;
		for(auto t : g[x])a[++p] = t.first, b[p] = 1ll * t.second * y;
	}
	static int pr[N], ne[N];
	n = m;
	REP(i, 1, n)pr[i] = ne[i] = i;
	REP(i, 1, n)
		while(pr[i] > 1 && i - a[i] < pr[i] - 1)pr[i] = pr[pr[i] - 1];
	for(int i = n; i; --i)
		while(ne[i] < n && i + a[i] > ne[i] + 1)ne[i] = ne[ne[i] + 1];
	memset(c, 0x3f, sizeof c);
	REP(i, 1, n){
		f[i] = std::min(f[pr[i] - 1] + b[i], ask(i));
		add(ne[i], f[i - 1] + b[i]);
	}
	std::cout << f[n];
	return 0;
}