#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

const int N = 1010;

int n, m, a[N], b[N], p[N], l[4], r[4];
vector<int> pos[4];

bool dfs(int u) {
	bool tag = 1;
	for(int i = 1; i <= n; i ++) {
		if(a[i] != i) {
			tag = 0; break ;
		}
	}
	if(tag) {
		printf("%d\n", u - 1);
		for(int i = u - 1; i >= 1; i --) {
			printf("%d %d\n", l[i], r[i]);
		}
		return 1;
	}
	if(u == 4) return 0;
	pos[u].clear();
	for(int i = 1; i <= n; i ++) {
//		printf("a[%d] = %d;", i, a[i]);
		if(i == 1) {
			if(a[i] != 1) pos[u].pb(i);
		} else if(i == n) {
			if(a[i] != n) pos[u].pb(i);
		}
		if(i > 1 && abs(a[i] - a[i - 1]) != 1) {
			pos[u].pb(i - 1); pos[u].pb(i);
		}
	}
	sort(pos[u].begin(), pos[u].end());
	int m = unique(pos[u].begin(), pos[u].end()) - pos[u].begin();
//	for(int i = 1; i <= n; i ++) p[b[i]] = i;
//	for(int i = 0; i < m; i ++) {
//		printf("u = %d; pos[%d] = %d\n", u, i, pos[u][i]);
//	}
	for(int i = 0; i < m; i ++) {
		for(int j = i + 1; j < m; j ++) {
			int x = pos[u][i], y = pos[u][j];
//			if(x > y) swap(x, y);
			reverse(a + x, a + y + 1);
			l[u] = x; r[u] = y;
			if(dfs(u + 1)) return 1;
			reverse(a + x, a + y + 1);
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i); b[i] = i;
	}
//	n = 99;
//	for(int i = 1; i <= n; i ++) a[i] = i;
//	reverse(a + 14, a + 88 + 1);
//	reverse(a + 54, a + 62 + 1);
//	reverse(a + 84, a + 91 + 1);

//	printf("a[87, 88, 89] = %d %d %d\n", a[87], a[88], a[89]);
//	printf("size = %d\n", (int) pos.size());
//	for(int i = 0; i < m; i ++) {
//		printf("[%d] ", pos[i]);
//	} 
	dfs(1);
	return 0;
}