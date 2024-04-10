#include <stdio.h>

const int N = 3e5 + 10;

namespace _01trie {
	int c[N * 30][2], sz[N * 30], id;
	void insert(int x) {
		int u = 0;
		for(int i = 29; ~ i; i --) {
			int & v = c[u][x >> i & 1];
			u = v ? v : v = ++ id;
			sz[u] ++;
		}
	}
	int match(int x) {
		int u = 0, ans = 0;
		for(int i = 29; ~ i; i --) {
			bool j = x >> i & 1;
			if(c[u][j] && sz[ c[u][j] ]) u = c[u][j];
			else u = c[u][j ^ 1], ans |= 1 << i;
			sz[u] --;
		}
		return ans;
	}
}
using namespace _01trie;

int main() {
	static int n, a[N];
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1, x; i <= n; i ++) {
		scanf("%d", &x); insert(x);
	}
	for(int i = 1; i <= n; i ++)
		printf("%d%c", match(a[i]), " \n"[i == n]);
	return 0;
}