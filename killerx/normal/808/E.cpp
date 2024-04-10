#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
struct Obj {int w, v;} o[100005];
bool operator < (const Obj & x, const Obj & y) {
	return 1LL * x.v * y.w > 1LL * y.v * x.w;
}
int lft;
multiset <int> use[4], has[4];
multiset <int> :: iterator it;
ll getmx(int w, int cnt) {
	if (has[w].size() < cnt) return -0x3f3f3f3f;
	it = has[w].end(); ll ans = 0; while (cnt --) -- it, ans += *it; return ans;
}
ll getmn(int w, int cnt) {
	if (use[w].size() < cnt) return 0x3f3f3f3f;
	it = use[w].begin(); ll ans = 0; while (cnt --) ans += *it, ++ it; return ans;
}
void ins(int w) {
	it = has[w].end(); -- it;
	use[w].insert(*it);
	has[w].erase(it);
}
void rem(int w) {
	it = use[w].begin();
	has[w].insert(*it);
	use[w].erase(it);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &o[i].w, &o[i].v);
	}
	sort(o, o + n);
	lft = m;
	ll ans = 0;
	for (int i = 0; i < n; ++ i) {
		has[o[i].w].insert(o[i].v);
	}
	for (int i = 0; i < n; ++ i) {
		if (lft < o[i].w) break;
		ans += o[i].v; lft -= o[i].w;
		use[o[i].w].insert(o[i].v);
		has[o[i].w].erase(has[o[i].w].find(o[i].v));
	}
	while (lft >= 1) {
		ll cur, best = 0; int tp = -1;
		cur = getmx(1, 1); if (cur > best) best = cur, tp = 0;
		cur = getmx(2, 1) - getmn(1, 1); if (cur > best) best = cur, tp = 1;
		cur = getmx(3, 1) - getmn(2, 1); if (cur > best) best = cur, tp = 2;
		cur = getmx(3, 1) - getmn(1, 2); if (cur > best) best = cur, tp = 3;
		cur = getmx(2, 2) - getmn(3, 1); if (cur > best) best = cur, tp = 4;
		if (!~tp) break;
		if (tp == 0) ins(1);
		else if (tp == 1) ins(2), rem(1);
		else if (tp == 2) ins(3), rem(2);
		else if (tp == 3) ins(3), rem(1), rem(1);
		else if (tp == 4) ins(2), ins(2), rem(3);
		ans += best; lft --;
	}
	while (lft >= 2) {
		ll cur, best = 0; int tp = -1;
		cur = getmx(2, 1); if (cur > best) best = cur, tp = 0;
		cur = getmx(3, 1) - getmn(1, 1); if (cur > best) best = cur, tp = 1;
		cur = getmx(3, 2) - getmn(2, 2); if (cur > best) best = cur, tp = 2;
		if (!~tp) break;
		if (tp == 0) ins(2);
		else if (tp == 1) ins(3), rem(1);
		else if (tp == 2) ins(3), ins(3), rem(2), rem(2);
		ans += best; lft -= 2;
	}
	printf("%lld\n", ans);
	return 0;
}