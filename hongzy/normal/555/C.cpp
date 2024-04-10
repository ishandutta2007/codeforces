#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int n, q;

struct Node {
	int u, d, ans;
	bool operator < (const Node &b) const { return u < b.u; };
};

set<Node> s;

int main() {
	scanf("%d%d", &n, &q);
	char dir[5];
	s.insert((Node) {0, -1});
	s.insert((Node) {n + 1, -1});
	for(int i = 1; i <= q; i ++) {
		int x, ans; scanf("%d%*d%s", &x, dir); dir[0] = dir[0] == 'U' ? 0 : 1;
		set<Node> :: iterator R = s.lower_bound((Node) {x, dir[0], 0}), L = R; L --;
		if(R -> u == x) {
			puts("0"); continue ;
		}
		if(dir[0] == 0) {
			ans = n + 1 - x;
			if(R -> d == 1) ans = R -> u - x;
			if(R -> d == 0) ans = min(ans, R -> ans + R -> u - x);
		} else {
			ans = x;
			if(L -> d == 0) ans = x - L -> u;
			if(L -> d == 1) ans = min(ans, L -> ans + x - L -> u);
		}
		printf("%d\n", ans);
		s.insert((Node) {x, dir[0], ans});
	}
	return 0;
}
/*
10 7
2 9 U
10 1 U
1 10 U
8 3 L
10 1 L
6 5 U
5 6 U
*/