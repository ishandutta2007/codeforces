// Hydro submission #63586e6463ef0fee598adfc9@1666739812654
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector> 
#define pii pair<int, LL>
#define mp make_pair
#define LL long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 0; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	if(f) x = ~x + 1;
}
struct itv {
	int l, r, v;
	inline bool operator < (const itv y) const{return l == y.l ? r < y.r : l < y.l;}
};
set <itv> odt;
inline void split(int x) {
	auto it = --odt.upper_bound((itv){x + 1, 0, 0});
	if(it -> l == x) return ;
	int l = it -> l, r = it -> r, v = it -> v;
	odt.insert((itv){l, x - 1, v}), odt.insert((itv){x, r, v});
	odt.erase(it);
}
const int N = 3e5 + 10;
int n, k;
LL ans;
vector<pii> tag[N], opt[N];
bool check(LL x) {
	int l = 1, r = 0;
	LL sl = 0, sum = 0, csum = 0, cur = 0;
	while(r < n) {
		++r;
		for(auto y : opt[r]) {
			if(y.first > l) break;
			cur += y.second, csum += 1ll * y.second * (l - y.first);
		}
		while(cur >= x && l <= r + 1) {
			csum += cur, ++l;
			for(auto y : tag[l]) {
				if(y.first > r) break;
				cur += y.second;
			}
		}
		sl += l - 1, sum += csum;
	}
	if(sl < k) return false;
	ans = sum - (sl - k) * x;
	return true;
}
int main() {
	read(n), read(k);
	odt.insert((itv){1, 1000000000, 0});
	for(int i = 1, l, r; i <= n; ++i) {
		read(l), read(r); --r;
		split(r + 1), split(l);
		while(true) {
			auto it = odt.lower_bound(itv{l, 0, 0});
			if(it == odt.end() || it -> r > r) break;
			int len = it -> r - it -> l + 1, v = it -> v;
			tag[v + 1].emplace_back(mp(i, len)), tag[i + 1].emplace_back(mp(i, -len));
			opt[i].emplace_back(mp(v + 1, len)), opt[i].emplace_back(i + 1, -len);
			odt.erase(it);
		}
		odt.insert((itv){l, r, i});
	}
	for(int i = 1; i <= n; ++i) sort(opt[i].begin(), opt[i].end()), sort(tag[i].begin(), tag[i].end());
	for(int l = 0, r = 1e9, mid; l <= r; ) {
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",ans);
}