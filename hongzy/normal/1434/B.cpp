#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 6e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> ran(0, 1ll << 62);
int n, Max[N];
void build(int u, int l, int r) {
	Max[u] = 0;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
void modify(int u, int l, int r, int ql, int qr, int v) {
	if(l == ql && r == qr) { Max[u] = v; return ; }
	int mid = (l + r) >> 1;
	if(qr <= mid) modify(u << 1, l, mid, ql, qr, v);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, v);
	else modify(u << 1, l, mid, ql, mid, v), modify(u << 1 | 1, mid + 1, r, mid + 1, qr, v);
	Max[u] = max(Max[u << 1], Max[u << 1 | 1]);
}
int query(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return Max[u];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(u << 1, l, mid, ql, qr);
	if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
	return max(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
}
int ans[N];
multiset<int> S;
void fail() {
	puts("NO"); exit(0);
}
int main() {
	scanf("%d", &n);
	char op[5]; int x; build(1, 1, n);
	rep(i, 1, 2 * n) {
		scanf("%s", op);
		if(*op == '+') {
			S.insert(i);
		} else {
			ans[i] = -1;
			scanf("%d", &x);
			int u = x == n ? 0 : query(1, 1, n, x + 1, n);
			auto it = S.lower_bound(u);
			if(it == S.end()) fail();
			ans[*it] = x; S.erase(it);
			modify(1, 1, n, x, x, i);
		}
	}
	puts("YES");
	rep(i, 1, 2 * n) if(~ ans[i]) printf("%d ", ans[i]);
   return 0;
}