#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 100 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
struct Node { int t, l, r; } a[N];
int q, n, m;
int main() {
	scanf("%d", &q);
	while(q --) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i ++)
			scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r);
		int ql = m, qr = m; bool fail = 0;
		for(int i = 1; i <= n; i ++) {
			int nl = a[i].l, nr = a[i].r, dt = a[i].t - a[i - 1].t;
			if(nr < ql - dt || nl > qr + dt) { fail = 1; break ; }
			ql -= dt; qr += dt; ql = max(ql, nl); qr = min(qr, nr);
		}
		puts(fail ? "NO" : "YES");
	}
	return 0;
}