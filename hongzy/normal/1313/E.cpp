#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define minus _sto_WTYAKIOI___
#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e6 + 10;
const int M = 5e5 + 10;
int n, m, f[M], g[M], z[N + M];
char s[N], a[M], b[M], t[N + M];
vector<int> cr[N], dl[N];
ull ans;

int bit[M], bit2[M];
void insert(int u, int v) {
	for(; u <= n; u += u & (-u)) {
		bit[u] += v;
	}
}
int query(int u) {
	int ans = 0;
	for(; u >= 1; u &= u - 1) {
		ans += bit[u];
	}
	return ans;
}
int query(int u, int v) {
	return query(v) - query(u - 1);
}
void mf(int u, int v) {
	for(; u <= n; u += u & (-u)) {
		bit2[u] += v;
	}
}
int modify(int u, int v) {
	mf(u, 1); mf(v + 1, -1);
}
int queryd(int u) {
	int ans = 0;
	for(; u >= 1; u &= u - 1) {
		ans += bit2[u];
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s%s%s", a + 1, b + 1, s + 1);
	copy(s + 1, s + m + 1, t + 1); t[m + 1] = '$';
	copy(a + 1, a + n + 1, t + m + 2);
	for(int i = 2, l = 0, r = 0; i <= n + m + 1; i ++) {
		z[i] = 0;
   	if(i <= r) z[i] = min(r - i + 1, z[i - l + 1]);
   	while(i + z[i] <= n + m + 1 && t[z[i] + 1] == t[i + z[i]]) z[i] ++;
   	if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
 	}
 	for(int i = 1; i <= n; i ++) f[i] = z[m + 1 + i];
 	
 	for(int i = 1; i <= m; i ++) t[m - i + 1] = s[i];
 	t[m + 1] = '@';
 	for(int i = 1; i <= n; i ++) t[n + m + 2 - i] = b[i];
	for(int i = 2, l = 0, r = 0; i <= n + m + 1; i ++) {
		z[i] = 0;
   	if(i <= r) z[i] = min(r - i + 1, z[i - l + 1]);
   	while(i + z[i] <= n + m + 1 && t[z[i] + 1] == t[i + z[i]]) z[i] ++;
   	if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
 	}
 	for(int i = m + 2; i <= m + 1 + n; i ++) g[n + m + 2 - i] = z[i];
 	for(int i = 1; i <= n; i ++) {
 		if(f[i]) cr[f[i] + 1].pb(i);
 		if(g[i]) dl[m - g[i]].pb(i);
	}
	for(int i = 1; i <= n; i ++) if(f[i]) insert(i, 1);
	ull cur = 0;
 	for(int t = 0; t <= m - 1; t ++) {
 		for(int v : dl[t]) {
			cur += query(max(1, v - m + 2), v);
			modify(max(1, v - m + 2), v);
		}
 		for(int v : cr[t]) {
 			cur -= queryd(v);
 			insert(v, -1);
		}
		if(t) ans += cur;
	}
	printf("%llu\n", ans);
	return 0;
}